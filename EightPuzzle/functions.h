#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include "puzzle.h"

using namespace std;

//node class declaration
class node {

	private:
		int depth = 0;
		vector <vector <int> > curr_state { {0,0,0}, {0,0,0}, {0,0,0} };
		node * child1;
		node * child2;
		node * child3;
		node * child4;

	public:
		void set_depth(){
			depth++;
		}

};

//Uniform Cost 
void uniform_cost(){
	
	cout << "ALG1\n";
}


//misplaced tile
void misplaced_tile(){

	cout << "ALG2\n";
}


//manhattan distance 
void manhattan_distance(){

	cout << "ALG3\n";
}

int manhata
#endif
