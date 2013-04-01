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
}

/** Destuctor*/
PuzzleSolver::~PuzzleSolver(){
}

/** run() is to actually solve the puzzle when user calls for a cheat
 * return a number indicating how many steps need to go
*/
int PuzzleSolver::run(PuzzleHeuristic* ph){
	BoardSet closedlist;
  	PMMinList openlist;
  	vector<PuzzleMove*> garbage;
  
  	PuzzleMove* pm=new PuzzleMove(b_);
  	openlist.push(pm);
  	closedlist.insert(pm->b_);
  	expansions_++;
  	while(!openlist.empty()){
  		PuzzleMove* move=openlist.top();
  		
  		openlist.pop();
  		garbage.push_back(move);
  		if(move->b_->solved()){
  			//trace
  			do{
  				
  				solutionlist.push_back(move->tileMove_);
  				move=move->prev_;
  			}
  			while(move->prev_!=NULL);
  			
  			break;
  		}
  		std::map<int, Board*> pmove=move->b_->potentialMoves();
  		
  		std::map<int, Board*>::iterator it;
  		for(it=pmove.begin();it!=pmove.end();++it){
  			//cout<<it->first<<endl<<*(it->second);
  			BoardSet::iterator it1;
  			bool exist=0;
  			for(it1=closedlist.begin();it1!=closedlist.end();it1++){
  				if(*(*it1)==*(it->second)){
  					exist=1;
  				}
  				
  			}
  			if(!exist){
  				
  				pm=new PuzzleMove(it->first,it->second,move);
  				pm->h_=ph->compute(pm->b_->getTiles(),pm->b_->getSize());
  				openlist.push(pm);
  				expansions_++;
  				closedlist.insert(pm->b_);
  					
  			}
  		}
  	}	
  	vector<PuzzleMove*>::iterator it;
  	for(it=garbage.begin();it!=garbage.end();++it){
  		//delete[] (*it)->b_->getTiles();
  		//delete (*it)->b_;
  		delete (*it);
  	}
 	
 	while(!openlist.empty()){
 		//delete[] openlist.top()->b_->getTiles();
 		delete openlist.top()->b_;
 		delete openlist.top();
 		openlist.pop();
 	}
  
	return solutionlist.size();
}

int PuzzleSolver::getNumExpansions()
{
  return expansions_;
}

MyList<int>* PuzzleSolver::getlist(){
	return &solutionlist;
}


