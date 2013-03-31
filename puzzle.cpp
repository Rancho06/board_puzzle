#include <iostream>
#include <cstdlib>
#include <deque>
#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"

using namespace std;

/** The main function of the whole program to parse the commandline information 
 * it will call the move() function to move a tile or 
 * call the run() method to provide a cheat
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
			if(!cin){
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
			if(b.potentialMoves().find(tile)!=b.potentialMoves().end()){
				b.move(tile);
				cout<<b;
			}
			else{
				cout<<"The tile you entered can not be moved. Please choose another tile.\n\n";
				continue;
			}
		}
	}
	delete mh;
  return 0;
}
