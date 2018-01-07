#include <stdio.h>
#include <stdlib.h>
#define SIDE 3
#define PLAYER1 1
#define PLAYER2 2
#define COMPUTER 3

void showInstructions(char board[][SIDE]){
  printf("\n\n");
  printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
  printf("-----------\n");
  printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
  printf("-----------\n");
  printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int gameOver(char board[][SIDE]){
  int line = 0;
  int flag = 1;
  if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
      flag=0;
  else{
      for(line = 0; line <= 2; line ++){
          if((board[line][0] == board[line][1] && board[line][0] == board[line][2])||(board[0][line] == board[1][line] && board[0][line] == board[2][line]))
              flag=0;
            }
        }
  return flag;
}

int playerMove(int player,char board[][SIDE]){
  int row = 0;
  int column = 0;
  int go = 0;
  showInstructions(board);
    do
    {
      if(player==3){
        go = rand()%10;
        printf("\nComputer Played\n");
      }
      else{
        printf("\nPlayer %d, please enter the number of the square "
               "where you want to place your %c: ", player,(player==1)?'X':'O');
        scanf("%d", &go);
      }
        row = --go/3;
        column = go%3;
    }
    while(go<0 || go>9 || board[row][column]>'9');
    board[row][column] = (player == 1) ? 'X' : 'O';
    if (gameOver(board)==0){
      showInstructions(board);
      if(player==3){
        printf("Computer Won!!!, Try again\n");
      }
      else{
        printf("Player %d won\n",player);
      }
      exit(0);
    }
}

int playGame(int player1, int player2){
  int i=0;
  int moves=9;
  char board[3][3] =
  {
      {'1','2','3'},
      {'4','5','6'},
      {'7','8','9'}
  };
  for(i=0;i<10;i++){
    if(i%2==0){playerMove(player1,board);}
    else{
      playerMove(player2,board);
    }
  }
  printf("Game Draw");
  exit(0);
}

int main(){
  int mode=1;
  printf("Welcome to TIC TAC TOE game\n");
  do{
    printf("Select Below option\n");
    printf("1. 2 players\n2. Play with computer");
    scanf("%d",&mode);
  }
  while(mode<1 || mode>2);
  if(mode==1)
    playGame(PLAYER1, PLAYER2);
  else
    playGame(PLAYER1, COMPUTER);
}
