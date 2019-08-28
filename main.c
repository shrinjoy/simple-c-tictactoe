/*
simple tictactoe game written in C 

*/
#include "stdio.h"
//function defs
void set_player();
void tictac_drawmatrix();
void update_grid_with_row_col(int row, int col);
char tictacmatrix[3][5]; //sets the matrix of the tictactoe
int player = 0; //takes care of player count
char mark = 'X';//mark O or X 
//main function
int main()
{

  //this is tictacmatrix
  char inputmatrix[2]; //takes two char hence row and col index

  //0                       // 1                    // 2                   // 3                   // 4
  tictacmatrix[0][0] = '.'; tictacmatrix[0][1] = '|'; tictacmatrix[0][2] = '.'; tictacmatrix[0][3] = '|'; tictacmatrix[0][4] = '.'; //row1
  //0                       // 1                    // 2                   // 3                   // 4
  tictacmatrix[1][0] = '.'; tictacmatrix[1][1] = '|'; tictacmatrix[1][2] = '.'; tictacmatrix[1][3] = '|'; tictacmatrix[1][4] = '.'; //row2
  //0                       // 1                    // 2                   // 3                   // 4
  tictacmatrix[2][0] = '.'; tictacmatrix[2][1] = '|'; tictacmatrix[2][2] = '.'; tictacmatrix[2][3] = '|'; tictacmatrix[2][4] = '.'; //row3
  //draws the tic tac matrix once
  tictac_drawmatrix();
  //sets player to 1
  set_player();
  //game loop
  while (1)
  {
    printf("player \n %d ", player);
    printf(" \n enter row and col:");
    gets(inputmatrix);
    int row = inputmatrix[0] - '0'; //converts the row char to int
    int col = inputmatrix[1] - '0';// converts the col char to int 
    update_grid_with_row_col(row, col); //updates the grid and carries out proper checks to ensure no messup
    tictac_drawmatrix();//redraws the tictac grid
  }
  return 0;
}
//responsible for setting player count to proper player count
void set_player()
{
  // allows players to have their own separate turns;
  if (player >= 2)
  {
    player = 1;
  }
  else
  {
    player++;
  }
}
//responsible for updating marker 
void update_grid_with_row_col(int row, int col)
{
  //all the checks are done here to avoid messup
  if (row < 0 || row > 2 || col == 1 || col == 3 ||col < 0||col>4 ||tictacmatrix[row][col] == 'X' || tictacmatrix[row][col] == 'O')
  {
    printf("invalid grid player: %d", player);
    getchar();
  }
  //if everything is fine then do this 
  else
  {

    if (player == 2)
    {
      mark = 'X';
    }
    else if (player == 1)
    {
      mark = 'O';
    }

    tictacmatrix[row][col] = mark;
    set_player();
  }
}
void tictac_drawmatrix()
{
  //draws the grid after looping through the row and col of tictaxmatrix
  system("cls");//clears the screen
  //loop and its vars
  int row_temp = 0;
  int col_temp = 0;
  printf("0 1 2 3 4 \n");
  for (row_temp = 0; row_temp < 3; row_temp++)
  {
    printf("%d",row_temp);
    for (col_temp = 0; col_temp < 5; col_temp++)
    {
     
      printf("%c", tictacmatrix[row_temp][col_temp]);
    }
    printf("\n");
  }
}
/*
  01234
0 x|x|x
1 y|y|y
2 x|x|x

*/