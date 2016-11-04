#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <vector>
using namespace std;

//array size, must match
const int R = 3;
const int C = 3;

//puzzle types
//change size with type of puzzle
vector < vector <int> > def_puzzle { {1,2,3}, {4,8,0}, {7,6,5} };
vector < vector <int> > cust_puzzle { {0,0,0}, {0,0,0}, {0,0,0} };
const vector < vector <int> > goal_state { {1,2,3}, {4,5,6}, {7,8,0} };
vector < vector <int> > init_puzzle; 

//diameter for known 3x3, change for different size
const int diameter = 31;

//function to set up personal puzzle
void personal_puzzle(){

	//optimize this later
	cout << "Enter your puzzle, user a zero to represent the blank\n";
	
	int var1, var2, var3;

	cout << "Enter the first row, use space or tabs between numbers: ";
	cin >> var1 >> var2 >> var3;

	cust_puzzle.at(0).at(0) = var1;
	cust_puzzle.at(0).at(1) = var2;
	cust_puzzle.at(0).at(2) = var3;

	cout << "Enter the second row, use space or tabs between numbers: ";
	cin >> var1 >> var2 >> var3;

	cust_puzzle.at(1).at(0) = var1;
	cust_puzzle.at(1).at(1) = var2;
	cust_puzzle.at(1).at(2) = var3;

	cout << "Enter the third row, use space or tabs between numbers: ";
	cin >> var1 >> var2 >> var3;

	cust_puzzle.at(2).at(0) = var1;
	cust_puzzle.at(2).at(1) = var2;
	cust_puzzle.at(2).at(2) = var3;

	cout << "\n";
}

//prints starting puzzle
void print_start(int puzzle_choice){

	if(puzzle_choice == 1){
		init_puzzle = def_puzzle;
	}
	else{
		init_puzzle = cust_puzzle;		
	}
	cout << "Here is your puzzle!\n";
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cout << init_puzzle.at(i).at(j) << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

//prints out goal puzzle
//mainly for testing
void print_trace(vector<vector <int> > trace){

	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cout << trace.at(i).at(j) << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

#endif