#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "puzzle.h"
#include "node.h"
#include <math.h>
#include <queue>

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

//for traceback
void trace_back(node last){
	vector <vector <vector <int> > > output_trace;
	
	//push path to vector
	node * temp = last.parent;
	node * move_temp = last.parent;
	
	output_trace.push_back(last.curr_state);
	while(temp != 0){
		output_trace.push_back(temp->curr_state);
		temp = move_temp->parent;
	}
	
	//output path
	for(int i = output_trace.size() - 1; i > -1; --i){
		print_trace(output_trace.at(i));
	}
	
	
}

//updating queue function
void update_q(node cur, priority_queue<node, vector<node>, cost> & q, int movement, int alg){
				//for hn
				int hn = 0;
				if(alg == 0){
					hn = 0;
				}
				else if(alg == 1){
					hn = hn_misplaced(cur.curr_state);
				}
				else{
					hn = hn_manhattan(cur.curr_state);
				}
				node temp;
				temp.depth = cur.depth + 1;
				temp.fn = temp.depth + hn;
				temp.parent = &cur;
				temp.curr_state = cur.curr_state;
				
				//for movement type
				if(movement == 0){
					if(m_left(temp.curr_state) == 1){
						q.push(temp);
						expanded++;
						if(temp.curr_state == goal_state){
							cout << "Expanded nodes: " << expanded << endl;
							cout << "Max queue size: " << max_qeueue << endl;
							cout << "Depth of goal node: " << temp.depth << endl << endl;
							trace_back(temp);
							exit(0);
						}
					}					
				}
				else if(movement == 1){
					if(m_right(temp.curr_state) == 1){
						q.push(temp);
						expanded++;
						if(temp.curr_state == goal_state){
							cout << "Expanded nodes: " << expanded << endl;
							cout << "Max queue size: " << max_qeueue << endl;
							cout << "Depth of goal node: " << temp.depth << endl << endl;
							trace_back(temp);
							exit(0);
						}
					}					
				}
				else if(movement == 2){
					if(m_up(temp.curr_state) == 1){
						q.push(temp);
						expanded++;
						if(temp.curr_state == goal_state){
							cout << "Expanded nodes: " << expanded << endl;
							cout << "Max queue size: " << max_qeueue << endl;
							cout << "Depth of goal node: " << temp.depth << endl << endl;
							trace_back(temp);
							exit(0);
						}
					}					
				}
				else{
					if(m_down(temp.curr_state) == 1){
						q.push(temp);
						expanded++;
						if(temp.curr_state == goal_state){
							cout << "Expanded nodes: " << expanded << endl;
							cout << "Max queue size: " << max_qeueue << endl;
							cout << "Depth of goal node: " << temp.depth << endl << endl;
							trace_back(temp);
							exit(0);
						}
					}					
				}
				
}

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
	
	//already traversed container
	vector < node > seen;
	
	//actually using prio_q no
	priority_queue<node, vector<node>, cost> q;
	q.push(top);
	
	while(1){
		
		//cehck if queue is empty which it shouldnt
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
		current_node.curr_state = q.top().curr_state;
		current_node.depth = q.top().depth;
		current_node.parent = q.top().parent;
		
		q.pop();
		
		//checking all the children before pushing to the heap
		for(int i = 0; i < 4; ++i){
			if(i == 0){
				//move left
				update_q(current_node,q,i, 0);
			}
			else if(i == 1){
				update_q(current_node,q,i, 0);			
			}
			else if(i == 2){
				//move up
				update_q(current_node,q,i, 0);			
			}
			else{
				//move down
				update_q(current_node,q,i, 0);			
			}
		}
	}
	
}

/*cout << "Puzzle solved!\nExpanded nodes: << expanded 
		<< "\nMax Nodes in queue: << "\nDepth of goal node: << depth <<< "\n";*/

//misplaced tile
//h(n) = hn_misplaced; g(n) = 1, or current depth;
void misplaced_tile(){
	//just in case there is no need to solve
	if(init_puzzle == goal_state){
		cout << "The puzzle is already in a Solved state\n";
		exit(0);
	}
	//create initial node
	node top;
	top.curr_state = init_puzzle;
	
	//already traversed container
	vector < node > seen;
	
	//actually using prio_q no
	priority_queue<node, vector<node>, cost> q;
	q.push(top);
	
	while(1){
		
		//cehck if queue is empty which it shouldnt
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
		current_node.curr_state = q.top().curr_state;
		current_node.depth = q.top().depth;
		current_node.parent = q.top().parent;
		
		q.pop();
		
		//checking all the children before pushing to the heap
		for(int i = 0; i < 4; ++i){
			if(i == 0){
				//move left
				update_q(current_node,q,i, 1);
			}
			else if(i == 1){
				update_q(current_node,q,i, 1);			
			}
			else if(i == 2){
				//move up
				update_q(current_node,q,i, 1);			
			}
			else{
				//move down
				update_q(current_node,q,i, 1);			
			}
		}
	}
}

//manhattan distance 
//h(n) = hn_manhattan; g(n) = 1, or current depth;
void manhattan_distance(){

	//just in case there is no need to solve
	if(init_puzzle == goal_state){
		cout << "The puzzle is already in a Solved state\n";
		exit(0);
	}
	//create initial node
	node top;
	top.curr_state = init_puzzle;
	
	//already traversed container
	vector < node > seen;
	
	//actually using prio_q no
	priority_queue<node, vector<node>, cost> q;
	q.push(top);
	
	while(1){
		
		//cehck if queue is empty which it shouldnt
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
		current_node.curr_state = q.top().curr_state;
		current_node.depth = q.top().depth;
		current_node.parent = q.top().parent;
		
		q.pop();
		
		//checking all the children before pushing to the heap
		for(int i = 0; i < 4; ++i){
			if(i == 0){
				//move left
				update_q(current_node,q,i, 2);
			}
			else if(i == 1){
				update_q(current_node,q,i, 2);			
			}
			else if(i == 2){
				//move up
				update_q(current_node,q,i, 2);			
			}
			else{
				//move down
				update_q(current_node,q,i, 2);			
			}
		}
	}
}

#endif
