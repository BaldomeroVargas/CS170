#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <vector>
using namespace std;

//array size, must match
const int R = 3;
const int C = 3;

//puzzle types
vector < vector <int> > def_puzzle { {1,2,3}, {4,8,0}, {7,6,5} };

vector < vector <int> > cust_puzzle { {0,0,0}, {0,0,0}, {0,0,0} };

vector < vector <int> > goal_puzzle; 

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

	cout << "\nEnter the second row, use space or tabs between numbers: ";
	cin >> var1 >> var2 >> var3;

	cust_puzzle.at(1).at(0) = var1;
	cust_puzzle.at(1).at(1) = var2;
	cust_puzzle.at(1).at(2) = var3;

	cout << "\nEnter the third row, use space or tabs between numbers: ";
	cin >> var1 >> var2 >> var3;

	cust_puzzle.at(2).at(0) = var1;
	cust_puzzle.at(2).at(1) = var2;
	cust_puzzle.at(2).at(2) = var3;

	cout << "\n";

}

//prints default puzzle
void print_default(){

	cout << "Here is the default puzzle!\n";
	for(int i = 0; i < R; i++){
		for(int j = 0;j < C; j++){
			cout << def_puzzle.at(i).at(j) << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	
	goal_puzzle  = def_puzzle;
}

//prints custom puzzle
void print_custom(){

	cout << "Here is your custom puzzle!\n";
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cout << cust_puzzle.at(i).at(j) << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	
	goal_puzzle = cust_puzzle;
}

//prints out goal puzzle
//mainly for testing
void print_goal(){

	cout << "Here is the goal  puzzle!\n";
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cout << goal_puzzle.at(i).at(j) << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
#endif
