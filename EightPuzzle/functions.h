#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "puzzle.h"
#include "node.h"
#include <math.h>
#include <queue>

int expanded = 0;
int max_qeueue = 0;

//Uniform Cost 
//h(n) = 0; g(n) = 1, or current depth;
void uniform_cost(){
	
	//just in case there is no need to solve
	if(init_puzzle == goal_state){
		cout << "The puzzle is already in a Solved state\n";
		exit(0);
	}
	//create initial node
	node top;
	top.curr_state = init_puzzle;
	//queue init, already traversed
	vector < node > seen;
	vector < node > prio_q;
	
	//initializing our prio q
	prio_q.push_back(top);
	
	while(1){
		
		//if we are ever deaper than the known diameter we can solve
		//but shouldnt so we will return an error since we are trying to optimize 
		//this
		if(top.depth > diameter){
			cout << "Puzzle should not be solved beyond this point\n";
			exit(0);
		}
		//checking all the children before pushing to the heap
		// for(int i = 0; i < 4; ++i){
		// 	if(i == 0){
				
		// 	}
		// 	else if(i == 1){
				
		// 	}
		// 	else if(i == 2){
				
		// 	}
		// 	else{
				
		// 	}
		// }
	}
	
}

/*cout << "Puzzle solved!\nExpanded nodes: << expanded 
		<< "\nMax Nodes in queue: << "\nDepth of goal node: << depth <<< "\n";*/

//misplaced tile
//h(n) = hn_misplaced; g(n) = 1, or current depth;
void misplaced_tile(){

	cout << "ALG2\n";
}

//manhattan distance 
//h(n) = hn_manhattan; g(n) = 1, or current depth;
void manhattan_distance(){

	cout << "ALG3\n";
}

//manhattan distance h(n)
int hn_manhattan(vector <vector <int> > current){
	int man_dist = 0;
	int temp, xdistance, ydistance;
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			if(current.at(i).at(j) == 0){
				continue;
			}
			temp = current.at(i).at(j);
			//this will give us the corresponding row
			xdistance = abs(i - (temp / 3));
			//this helps with the corresponding column
			ydistance = abs(j - (temp % 3));
			//now lets add to our overall count
			man_dist += (xdistance + ydistance);
		}
	}

	return man_dist;
}

//mispaced tile h(n)
int hn_misplaced(vector <vector <int> > current){

	int count = 0;
	//checking misplaced tiles 
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			//do not check the last entry since it should be blank
			if( (i == 2) && (j == 2) ){
				continue;
			}
			if(current.at(i).at(j) != goal_state.at(i).at(j)){
				count++;
			} 
		}
	}
	return count;
}


#endif
