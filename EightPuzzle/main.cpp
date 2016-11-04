#include <iostream>
#include "functions.h"

//menu outputs
const string puz_out = "Welcome! Please enter 1 if you would like to use the default puzzle or 2 if you want to input your own\n";
const string alg_out = "Please enter choice or algorithm\n";
const string alg1 = "1. Uniform Cost Search\n";
const string alg2 = "2. A* with the Misplaced Tile heuristic\n";
const string alg3 = "3. A* with the Manhattan distance heuristic\n";

//main function
int main(){
	
	//check puzzle.h
	if(R != C){
		cout << "Puzzle Settings are not of correct size\n";
		exit(0);
	}

	char choice_alg = 0;
	char choice_puzzle = 0;

	//welcome message and choice of puzzle
	cout << puz_out;
	cin >> choice_puzzle;
	cout << "\n";

	//switch case to set up use of puzzle
	switch(choice_puzzle){

		case '1':
			print_start(1);
			break;

		case '2':
			personal_puzzle();
			print_start(2);
			break;

		default:
			cout << "Please enter valid choice (1 or 2) and try again.\n";
			return 0;
			break;

	}
	
	//output algorithm prompts
	cout << alg_out << alg1 << alg2 << alg3;

	//intake outputs
	cin >> choice_alg; 

	//switch case for algorithm chouce
	switch(choice_alg){

		//Uniform cose choice
		case '1':
				general_alg(1);
			break;

		//Uniform A* with the Misplaced Tile heuristic
		case '2':
			general_alg(2);
			break;

		//Uniform A* with the Manhattan distance heusistic
		case '3':
			general_alg(2);
			break;
		
		//well lets try again
		default:
			cout << "Please slect a valid choice (1 or 2 or 3) and try again.\n";
			return 0;
			break;

	}

return 0;
}
