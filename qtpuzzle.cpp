#include <QtGui/QApplication>
#include "main_window.h"

/** The main function of the whole program to create and show the main window 
  
  @mainpage csci102 Programming Assignment #4
  @section purpose Purpose/Overview
  This assignment will display a game window and allow users to create manipulate the game themselves. Users can select 
  the size of the game board, though we will require it to be square. 
  Valid sizes are 4 (2x2), 9 (3x3), 16 (4x4), 25(5x5), 36(6x6) etc. 
  Further, we will define the SOLVED gameboard to be as shown below with the blank tile at the upper-left corner.
  Users can click on a tile to swap the tile with the blue blank tile. Only neighbors of the blank tile can be moved.
  Users can also choose to Get Cheat and get the shortest ways to solve the board.
  People who solved the board would see a congratulation message printing out in the top box.
  @section requirements Requirements
  The program requires users create the game window themselves by giving appropriate inputs. 
  Then users must select a heuristic method to get cheat answers.
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(&a);

    w.show();

    return a.exec();
}
