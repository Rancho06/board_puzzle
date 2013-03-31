#include <iostream>
#include "puzzle_heur.h"
#include <cmath>

using namespace std;

/**compute the value of h based on its Manhattan distance(x-/y-)*/
int ManhattanHeuristic::compute(int *tiles, int size){
	int count=0;
	int dim=(int)sqrt(size);
	for(int i=0;i<size;i++){
		if(tiles[i]!=0){
			/** get the abosulte value*/
			count+=(int)sqrt(pow(tiles[i]/dim-i/dim,2));
			count+=(int)sqrt(pow(tiles[i]%dim-i%dim,2));
		}
	}
	return count;
};

/** compute the value of h based on how many tiles are out of place*/
int  OutOfPlaceHeuristic::compute(int *tiles, int size){
	int count=0;
	for(int i=0;i<size;i++){
		if(tiles[i]!=i) count++;
	}
	return count;
};



