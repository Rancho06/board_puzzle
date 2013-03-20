#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include "puzzle_solver.h"
#include "pmminlist.h"

using namespace std;

PuzzleSolver::PuzzleSolver(const Board &b){
	b_=b;
	expansions_=0;
}

PuzzleSolver::~PuzzleSolver(){
}

int PuzzleSolver::run(PuzzleHeuristic* ph){
	BoardSet closedlist;
  PMMinList openlist;
  vector<PuzzleMove*> garbage;
  PuzzleMove* pm=new PuzzleMove(b_);
  openlist.push(pm);
  while(!openlist.empty()){
  	PuzzleMove* move=openlist.top();
  	openlist.pop();
  	closedlist.insert(move->b_);
  	garbage.push_back(move);
  	if(move->b_->solved()){
  		//trace
  		do{
  			solutionlist.push_back(move->tileMove_);
  			move=move->prev_;
  		}
  		while(move!=NULL);
  		
  		break;
  	}
  	std::map<int, Board*> pmove=move->b_->potentialMoves();
  	std::map<int, Board*>::iterator it;
  	for(it=pmove.begin();it!=pmove.end();++it){
  		PuzzleMove* pm2=new PuzzleMove(it->first,it->second,move);
  		if(closedlist.find(pm2->b_)==closedlist.end()){
  			pm2->h_=ph->compute(pm2->b_->getTiles(),pm2->b_->getSize());
  			openlist.push(pm2);
  			expansions_++;
  		}
  		else delete pm2;
  	}
  }
  vector<PuzzleMove*>::iterator it;
  for(it=garbage.begin();it!=garbage.end();++it){
  	delete (*it);
  }
 	
 	while(!openlist.empty()){
 		delete openlist.top();
 		openlist.pop();
 	}
  
  return solutionlist.size();
}

int PuzzleSolver::getNumExpansions()
{
  return expansions_;
}

MyList<int> PuzzleSolver::getlist(){
	return solutionlist;
}


