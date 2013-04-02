#include <iostream>
#include <cstdlib>
#include <deque>
#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"

using namespace std;

/** The main function of the whole program to parse the commandline information 
  it will call the move() function to move a tile or 
  call the run() method to provide a cheat
  @mainpage csci102 Programming Assignment #3
  @section purpose Purpose/Overview
  This assignment will allow a user to select the size of the game board, 
  though we will require it to be square. Valid sizes are 4 (2x2), 9 (3x3), 16 (4x4), etc. 
  Further, we will define the SOLVED gameboard to be as shown below with the blank tile at the upper-left corner.
  @section requirements Requirements
  The program requires users to select a valid tile to move or choose -1 for a cheat.
*/
int main(int argc, char *argv[])
{
  	if(argc < 4){
    	cerr << "Usage: ./puzzle size initMoves seed" << endl;
    	return 1;
  	}

  	int size, initMoves, seed;

  	size = atoi(argv[1]);
  	initMoves = atoi(argv[2]);
  	seed = atoi(argv[3]);
  	Board b(size,initMoves,seed);  
  
  	int tile;
  	cout<<b;
  	ManhattanHeuristic* mh=new ManhattanHeuristic;
  	/** if the board has been solved, the program ends
  	 * if the board is not solved, we ask for a tile to move or provide a cheat.
  	*/
  	while(!b.solved()){
		do{
			cout<<"Enter tile number to move or -1 for a cheat: ";
			cin>>tile;
			//check the input validation
			if(!cin){
				cout<<"What you entered is not an integer!\n";
				cin.clear();
				cin.ignore(10000,'\n');
				continue;
			}
			break;
		}
		while(true);
		/** if the user choose to cheat, we use the run() in PuzzleSolver class 
		 * to get the sequence of numbers
		*/
		if(tile==-1){
			int step;
			MyList<int>* list;
			PuzzleSolver ps(b);
			step=ps.run(mh);
			list=ps.getlist();
			cout<<endl<<"Try this sequence: ";
			//cout<<"size: "<<list->size();
			for(int i=0;i<step;i++){
				cout<<" "<<list->at(step-1-i);
			}
			cout<<endl<<"(Expansions = "<<ps.getNumExpansions()<<")\n";
			cout<<b;
		}
		/** if the user chooses to move an actual tile, we first check whether the tile can be moved.
		 * if the tile can be moved, we move that.
		 * if the tile can not be moved, we print a error message and continue the game
		*/
		else{
			std::map<int,Board*> plist=b.potentialMoves();
			//Check whether the tile entered can be moved
			if( plist.find(tile) != plist.end()){
				b.move(tile);
				cout<<b;
				std::map<int,Board*>::iterator it;
				for(it=plist.begin();it!=plist.end();it++){
					delete it->second;
				}
			}
			else{
				std::map<int,Board*>::iterator it;
				for(it=plist.begin();it!=plist.end();it++){
					delete it->second;
				}
				cout<<"The tile you entered can not be moved. Please choose another tile.\n\n";
				continue;//Go back to the loop and ask for number again
			}
		}
	}
	delete mh;
  return 0;
}
