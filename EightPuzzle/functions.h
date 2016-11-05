#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "puzzle.h"
#include "node.h"
#include <math.h>
#include <queue>
#include <map>

using namespace std;

int expanded = 0;
int max_qeueue = 0;

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
			xdistance = abs(i - ((temp - 1) / 3));
			//this helps with the corresponding column
			ydistance = abs(j - ((temp - 1) % 3));
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

//for traceback
void trace_back(node last){
	vector <vector <vector <int> > > output_trace;
	
	//push path to vector
	node * temp = &last;
	
	while(temp->parent != NULL){
		output_trace.push_back(temp->curr_state);
		temp = temp->parent;
	}
	
	//output path
	for(int i = output_trace.size() - 1; i > -1; --i){
		print_trace(output_trace.at(i));
	}
	
	//program should end here
	exit(0);
}

//checking if we are done
int end_program_check(vector <vector <int> > current, int depth){
	
	if(current == goal_state){
		cout << "Expanded nodes: " << expanded << endl;
		cout << "Max queue size: " << max_qeueue << endl;
		cout << "Depth of goal node: " << depth << endl << endl;
		return 1;
	}
	return 0;
}

//updating queue function
//sets fn
void update_q(node & cur, priority_queue<node, vector<node>, Compare> & q, 
map < vector <vector <int> >, bool> & trav, int movement, int alg){
	
	//for hn
	int hn = 0;
	if(alg == 1){ hn = 0; }
	else if(alg == 2){ hn = hn_misplaced(cur.curr_state); }
	else if(alg == 3){ hn = hn_manhattan(cur.curr_state); }
	node temp;
	temp.depth = cur.depth + 1;
	temp.fn = temp.depth + hn;
	temp.parent = &cur;
	temp.curr_state = cur.curr_state;
	
	//for movement type
	switch(movement){
		//left
		case 0:
			if(m_left(temp.curr_state) == 1){
				if(trav.find(temp.curr_state) == trav.end()){
					trav.insert(pair<vector <vector <int> >,bool>(temp.curr_state, 0));
					q.push(temp);
					expanded++;
					if(end_program_check(temp.curr_state, temp.depth)){
						trace_back(temp);
						exit(0);
					}					
				}
			}
			break;
		//right
		case 1:
			if(m_right(temp.curr_state) == 1){
				if(trav.find(temp.curr_state) == trav.end()){
					trav.insert(pair<vector <vector <int> >,bool>(temp.curr_state, 0));
					q.push(temp);
					expanded++;
					if(end_program_check(temp.curr_state, temp.depth)){
						trace_back(temp);
						exit(0);
					}					
				}
			}
			break;
		
		//up
		case 2:
			if(m_up(temp.curr_state) == 1){
				if(trav.find(temp.curr_state) == trav.end()){
					trav.insert(pair<vector <vector <int> >,bool>(temp.curr_state, 0));
					q.push(temp);
					expanded++;
					if(end_program_check(temp.curr_state, temp.depth)){
						trace_back(temp);
						exit(0);
					}					
				}
			}
			break;
		
		//down
		case 3:
			if(m_down(temp.curr_state) == 1){
				if(trav.find(temp.curr_state) == trav.end()){
					trav.insert(pair<vector <vector <int> >,bool>(temp.curr_state, 0));
					q.push(temp);
					expanded++;
					if(end_program_check(temp.curr_state, temp.depth)){
						trace_back(temp);
						exit(0);
					}					
				}
			}
			break;
		//error
		default:
			cout <<"ERROR: You should not be here\n";
			exit(1);
	}
}

//Uniform Cost 
//h(n) = 0; g(n) = 1, or current depth;
//misplaced tile
//h(n) = hn_misplaced; g(n) = 1, or current depth;
//manhattan distance 
//h(n) = hn_manhattan; g(n) = 1, or current depth;
void general_alg(int choice){
	//just in case there is no need to solve
	if(init_puzzle == goal_state){
		cout << "The puzzle is already in a Solved state\n";
		exit(0);
	}
	//create initial node
	node top;
	top.curr_state = init_puzzle;
	
	//already traversed container
	map <vector <vector <int> >, bool> trav;
	
	//actually using prio_q now and setting it up
	priority_queue<node, vector<node>, Compare> q;
	trav.insert(pair<vector <vector <int> >,bool>(top.curr_state, 0));
	q.push(top);
	
	while(1){
		
		//check if queue is empty which it shouldnt
		if(q.empty()){
			cout << "Puzzle cannot be solved\n";
			exit(0);
		}
		//we need to update the max size of the queue
		if(max_qeueue < q.size()){
			max_qeueue = q.size();
		}
		//if we are ever deaper than the known diameter we can solve
		//but shouldnt so we will return an error since we are trying to optimize 
		//this
		if(top.depth > diameter){
			cout << "Puzzle should not be solved beyond this point\n";
			exit(0);
		}
		//pop off top of queue
		node current_node;
		current_node = q.top();
		
		//print_trace(current_node.curr_state);
		
		q.pop();		
		
		print_trace(current_node.curr_state); 
		// cout << " " << current_node.depth << "\n";
		
		//checking all the children before pushing to the heap
		for(int i = 0; i < 4; ++i){
			//0 = left, 1 = right, 2 = up, 3 = down
			update_q(current_node,q,trav, i, choice);	
		}
	}
	
}

#endif