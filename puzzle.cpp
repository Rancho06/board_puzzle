#include <iostream>
#include <cstdlib>
#include <deque>
#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"

using namespace std;

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

  //**** Implement the gameplay here
  
  
  int tile;
  cout<<b;
  ManhattanHeuristic* mh=new ManhattanHeuristic;
  while(!b.solved()){
		cout<<"Enter tile number to move or -1 for a cheat: ";
		cin>>tile;
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
		else{
			b.move(tile);
			cout<<b;
		}
	}
	delete mh;
  return 0;
}
