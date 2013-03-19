#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include "board.h"
using namespace std;


/** Init a board of given size and scramble it with numInitMoves 
 * by moving the space tile with a randomly chosen direction N, W, S, E
 * some of which may be invalid, in which case we skip that move 
 * 
 *  @param size Number of tiles for the game.  \
 *      Should be a perfect square (4, 16, 25)
 *  @param numInitMoves Number of tile moves to attempt to scramble the board
 *  @param seed Use to seed the random number generator (srand) 
 */
Board::Board(int size, int numInitMoves, int seed )
{
  size_ = size;
  tiles_ = new int[size_];
  int dim = static_cast<int>(sqrt(size_));
  srand(seed);
  for(int i=0; i < size_; i++){
    tiles_[i] = i;
  }
  int blankLoc = 0;
  for(int i=0; i < numInitMoves; i++){
    int r = rand()%4;
    int randNeighbor = -1;
    if(r == 0){
      int n = blankLoc - dim;
      if(n >= 0){
	randNeighbor = n;
      }
    }
    else if(r == 1){
      int w = blankLoc - 1;
      if(blankLoc % dim != 0){
	randNeighbor = w;
      }
    }
    else if(r == 2){
      int s = blankLoc + dim;
      if(s  < size_){
	randNeighbor = s;
      }
    }
    else {
      int e = blankLoc + 1;
      if(blankLoc % dim != dim-1){
	randNeighbor = e;
      }
    }
    if(randNeighbor > -1){
      tiles_[blankLoc] = tiles_[randNeighbor];
      tiles_[randNeighbor] = 0;
      blankLoc = randNeighbor;
    }
  }
}


/** Default constructor. provide documentation here */
Board::Board()
{
  size_=16;
  tiles_=new int[size_];
}

/** Default destructor. provide documentation here */
Board::~Board()
{
 	delete[] tiles_;
}

bool Board::operator<(const Board& rhs) const
{
  if(size_ < rhs.size_){
    return true;
  }
  bool val = false;
  for(int i=0; i < size_; i++){
    if(tiles_[i] < rhs.tiles_[i]){
       //val = true;
       //break;
       return true;
     }
     else if(tiles_[i] > rhs.tiles_[i]){
       //break;
       return false;
     }
  }
  return val;
}

/** Copy constructor */
Board::Board(const Board &b){
	this->size_=b.getSize();
	tiles_=new int[size_];
	for(int i=0;i<size_;i++){
		tiles_[i]=b.getTiles()[i];
	
	}

}

/** Another kind of "copy" constructor */
Board::Board(int *tiles, int size){
	size_=size;
	tiles_=new int[size_];
	for(int i=0;i<size_;i++){
		tiles_[i]=tiles[i];
	}
}

/** Swaps the blank with the specified tile */
void Board::move(int tile){
	int blankloc, tileloc;
	for(int i=0;i<size_;i++){
		if(tiles_[i]==0) blankloc=i;
		if(tiles_[i]==tile) tileloc=i;
	}
	tiles_[blankloc]=tile;
	tiles_[tileloc]=0;
}

Board* Board::NewBoard(int loc){
	Board* bd=new Board(tiles_,size_);
	bd->move(loc);
	return bd;
}


/** Generate potential moves and returns new boards
   * Key=tile, Value=Ptr to corresponding Board */
std::map<int, Board*> Board::potentialMoves(){
	std::map<int, Board*> list;
	int blankloc;
	int dim=(int)sqrt(size_);
	for(int i=0;i<size_;i++){
		if(tiles_[i]==0) blankloc=i;
	}
	if(blankloc/dim>0) list[tiles_[blankloc-dim]]=NewBoard(tiles_[blankloc-dim]);
	if(blankloc/dim<(dim-1)) list[tiles_[blankloc+dim]]=NewBoard(tiles_[blankloc+dim]);
	if(blankloc%dim>0) list[tiles_[blankloc-1]]=NewBoard(tiles_[blankloc-1]);
	if(blankloc%dim<(dim-1)) list[tiles_[blankloc+1]]=NewBoard(tiles_[blankloc+1]);
	return list;
}



/** Returns true if the board is solved, false otherwise */
bool Board::solved(){
	for(int i=0;i<size_;i++){
		if(tiles_[i]!=i) return false;
	}
	return true;
}

// Operators
std::ostream& operator<<(std::ostream &os, const Board &b){
	os<<left;
	int N=2;
  	for(int i=0;i<b.getSize();i++){
  		if(i%(int)sqrt(b.getSize())==0) os<<endl;
		if(b.getTiles()[i]==0) os<<setw(N)<<" ";
		else os<<setw(N)<<b.getTiles()[i];
	}
	os<<endl<<endl;
	return os;
}
  
bool Board::operator!=(const Board& rhs) const{
	if(size_ != rhs.size_){
    	return true;
  	}
  	bool val = false;
  	for(int i=0; i < size_; i++){
    	if(tiles_[i] != rhs.tiles_[i]){
       	//val = true;
       	//break;
       	return true;
     	}
  	}
  	return val;
}
  
bool Board::operator==(const Board& rhs) const{
	return !(operator!=(rhs));
}

// Accessors
int* Board::getTiles() const{
	return tiles_;
}

int Board::getSize() const{
	return size_;
}

