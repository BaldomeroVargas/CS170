#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>

using namespace std;

//array size, must match
const int R = 3;
const int C = 3;

//puzzle types
int def_puzzle[R][C] = {1, 2, 3,
			4, 8, 0,
			7, 6, 5};

int cust_puzzle[R][C];


//status bit for puzzle
//0 = default
//1 = costom
int puzz_choice = 0;


//function to set up personal puzzle
void personal_puzzle(){
	

}

//prints default puzzle
void print_default(){

	for(int i = 0; i < R; i++){
		for(int j = 0;j < C; j++){
			cout << def_puzzle[i][j] << " ";
		}
		cout << endl;
	}
}

//prints custom puzzle
void print_custom(){

	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cout << cust_puzzle[i][j] << " ";
		}
		cout << endl;
	}

}


#endif
