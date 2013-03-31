#include "puzzle_move.h"

// Constructor for starting Board of an A* search
PuzzleMove::PuzzleMove(Board &b){
	b_=&b;
	prev_=NULL;
	g_=0;
}

// Constructor for subsequent search boards 
  // (i.e. those returned by Board::potentialMoves() )
PuzzleMove::PuzzleMove(int tile, Board *b, PuzzleMove *parent){
	tileMove_=tile;
	b_=b;
	prev_=parent;
	g_=parent->g_+1;
}

PuzzleMove::~PuzzleMove(){

}

// Compare to PuzzleMoves based on f distance (needed for priority queue
bool PuzzleMove::operator<(const PuzzleMove& p) const
{
  if((g_ + h_) < (p.g_ + p.h_)){
    return true;
  }
  else if((g_ + h_ == p.g_ + p.h_) && (g_ > p.g_)){
    return true;
  }
  else {
    return false;
  }
}

//Compare to PuzzleMoves based on f distance
bool PuzzleMove::operator>(const PuzzleMove& p) const
{
  if( (g_ + h_) > (p.g_ + p.h_) ){
    return true;
  }
  else if((g_ + h_ == p.g_ + p.h_) && (g_ < p.g_) ){
    return true;
  }
  else {
     return false;
  }
  
}

//Compare if it's equal to puzzle moves based on f distance
bool PuzzleMove::operator==(const PuzzleMove& p) const{
	if((g_==p.g_)&&(h_==p.h_))
		return true;
	else
		return false;
}




