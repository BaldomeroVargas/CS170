#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "puzzle.h"
#include <math.h>

//node class declaration
class node {

	private:
		int depth = 0;
		vector <vector <int> > curr_state { {0,0,0}, {0,0,0}, {0,0,0} };
		//for possible branches
		node * child1;
		node * child2;
		node * child3;
		node * child4;
		//use primarily for Traceback from goal state
		node * parent = 0;

	public:
		void set_depth(){
			depth++;
		}

};

//Uniform Cost 
//h(n) = 0; g(n) = 1;
void uniform_cost(){
	
	cout << "ALG1\n";
}


//misplaced tile
//h(n) = hn_misplaced; g(n) = 1;
void misplaced_tile(){

	cout << "ALG2\n";
}


//manhattan distance 
//h(n) = hn_manhattan; g(n) = 1;
void manhattan_distance(){

	cout << "ALG3\n";
}

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
