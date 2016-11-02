#include <iostream>
#include "functions.h"

using namespace std;

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

	char exit_status = 'C';
	char choice_alg = 0;
	char choice_puzzle = 0;

	while(exit_status == 'c' || exit_status == 'C'){

		//welcome message and choice of puzzle
		cout << puz_out;
		cin >> choice_puzzle;
		cout << "\n";

		//switch case to set up use of puzzle
		switch(choice_puzzle){

			case '1':
				print_default();
				break;

			case '2':
				personal_puzzle();
				print_custom();
				break;

			default:
				cout << "Please enter valid choice (1 or 2)\n";
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
			        uniform_cost();					
				break;

			//Uniform A* with the Misplaced Tile heuristic
			case '2':
				misplaced_tile();
				break;

			//Uniform A* with the Manhattan distance heusistic
			case '3':
				manhattan_distance();
				break;
			
			//well lets try again
			default:
				cout << "Please slect a valid choice (1 or 2 or 3)\n";
				break;

		}
		
		//to exit program
		cout << "Would you like to continue? (C/c)\n";
		cin >> exit_status;
	}

	return 0;

}
