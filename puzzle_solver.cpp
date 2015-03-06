#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include "puzzle_solver.h"
#include "pmminlist.h"

using namespace std;

/** constructor sets the initial expansions to 0 and copy the current board*/
PuzzleSolver::PuzzleSolver(const Board &b):b_(b){
	expansions_=0;
	qstringlist=new QStringList;
}

/** Destuctor*/
PuzzleSolver::~PuzzleSolver(){
}

/** run() is to actually solve the puzzle when user calls for a cheat
 * return a number indicating how many steps need to go
 @param ph A pointer to a PuzzleHeuristic object that can be used to compute h_ value
 @return The number of steps it takes to solve the puzzle
*/
void PuzzleSolver::run(PuzzleHeuristic* ph){
	  //Declare a closedlist to store pointers pointing to boards
	  BoardSet closedlist;
	  //Declare a openlist to store pointers to PuzzleMove objects
  	PMMinList openlist;
  	//Declare a garbage list to store pointers popped from openlist
  	vector<PuzzleMove*> garbage;
    
    //The A Star Algorithm
  	PuzzleMove* pm=new PuzzleMove(b_);
  	openlist.push(pm);
  	closedlist.insert(pm->b_);
  	expansions_++;
  	
  	while(!openlist.empty()){
  		PuzzleMove* move=openlist.top();
  		
  		openlist.pop();
  		garbage.push_back(move);
  		
  		if(move->b_->solved()){
  			//trace back to get the solutionlist
  			do{
  				//add the tile number to the solutionlist
  				solutionlist.push_back(move->tileMove_);
  				QString* qs=new QString;
  				qs->setNum(move->tileMove_);
  				qstringlist->push_front(*qs);
  				move=move->prev_;
  			}
  			while(move->prev_!=NULL);
  			
  			break;
  		}
  		//generate potential moves and resulting boards
  		
  		std::map<int, Board*> pmove=move->b_->potentialMoves();
  		//check if the resulting boards have already existed in the closedlist
  		std::map<int, Board*>::iterator it;
  		for(it=pmove.begin();it!=pmove.end();++it){
  		
  			BoardSet::iterator it1;
  			bool exist=0;
  			for(it1=closedlist.begin();it1!=closedlist.end();it1++){
  				if(*(*it1)==*(it->second)){
  					exist=1;
  				}	
  			}
  			if(!exist){//board not exists
  				
  				pm=new PuzzleMove(it->first,it->second,move);
  				pm->h_=ph->compute(pm->b_->getTiles(),pm->b_->getSize());
  				openlist.push(pm);
  				expansions_++;
  				closedlist.insert(pm->b_);
  					
  			}
  			else delete it->second;//board already exists
  		}
  	}	
  	
  	//Clear up and deallocate any memories in the heap
  	vector<PuzzleMove*>::iterator it=garbage.begin();
  	delete *it; //This is to delete the initial PuzzleMove object
  	for(++it;it!=garbage.end();++it){
  		delete (*it)->b_;//delete all the boards in all the PuzzleMove Objects in the garbage
  		delete (*it);    //delete all the PuzzleMove objects in the garbage
  	}
 	
 	while(!openlist.empty()){
 		delete openlist.top()->b_; //delete all the boards in all the PuzzleMove Objects in the openlist
 		delete openlist.top();     //delete all the PuzzleMove Objects in the openlist
 		openlist.pop();
 	}
  
	//return solutionlist.size();
}


int PuzzleSolver::getNumExpansions()
{
  return expansions_;
}

MyList<int>* PuzzleSolver::getlist(){
	return &solutionlist;
}





