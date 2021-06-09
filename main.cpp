#include <iostream>
#include<ctime>
#include <random>
using namespace std;
// start at 11:00 6/9/2021
// finish at 13:00 6/9/2021

// board with empty
char board[9]= {' ',' ',' ',' ',' ',' ',' ',' ',' ', };

void display_board();
void x_player_turn();
void o_player_turn();
void computer_turn();
int count_board(char symbol);
char check_winner();
void player_ai();
void player_player();
void ai_player();

int main()
{ 
  int gamemode;
  cout << "Please enter the number for the game mode!" << endl;
  cout << "1. Computer VS Player." << endl;
  cout << "2. Player VS Player." << endl;
  cout << "3. Computer VS Player (Computer will go first.)" << endl;
  cin >> gamemode;
  switch(gamemode)
  {
    case 1:
    player_ai(); 
    break;

    case 2:
    player_player();
    board[0] = ' ';
    board[1] = ' ';
    board[2] = ' ';
    board[3] = ' ';
    board[4] = ' ';
    board[5] = ' ';
    board[6] = ' ';
    board[7] = ' ';
    board[8] = ' ';
    break;

    case 3:
    ai_player();
    board[0] = ' ';
    board[1] = ' ';
    board[2] = ' ';
    board[3] = ' ';
    board[4] = ' ';
    board[5] = ' ';
    board[6] = ' ';
    board[7] = ' ';
    board[8] = ' ';
    break;

    default:
    cout << "Please selece game mode (1 or 2 or 3)." << endl;
    break;
  }
  return 0;
}

/*
* Display the game board
*/
void display_board()
{
  cout << "-------------------" << endl;
  cout << "|  " <<board[0] << "  |  " << board[1] << "  |  " << board[2] << "  |"<< endl;
    cout << "-------------------" << endl;
  cout << "|  " <<board[3] << "  |  " << board[4] << "  |  " << board[5] << "  |"<< endl;
    cout << "-------------------" << endl;
  cout << "|  " <<board[6] << "  |  " << board[7] << "  |  " << board[8] << "  |"<< endl;
   cout << "-------------------" << endl;
}

/*
* Computer's turn to input
*/
void computer_turn()
{

  int input;
  //Initialize random number generator
  // seed the random number generator
  srand(time(0));
  do
  {
    input = rand() % 10 ; // will be a random number from 0 through 9
  }

  while(board[input] != ' ');
  board[input] = 'O';
  
}


/*
* O  Player's turn to input
*/
void x_player_turn()
{
  while(true)
  {
    cout<< "Select from (1-9): ";
    int Xinput ;
    cin >> Xinput;
    Xinput--; //decrease by one since we start from 0 in array

    if (Xinput < 0 || Xinput > 8)
    {
      cout << "The number is not vaild for the game, please select your choice from (1-9)." << endl;
    }
    else if (board[Xinput] != ' ')
    {
      cout << "This space had been taken, please select an empty space." << endl;
    }
    else 
    { 
      board[Xinput] = 'X';
      break;
    }
  }
}

/*
* O  Player's turn to input
*/
void o_player_turn()
{
  while(true)
  { 

    int Oinput;
    cout<< "Select from (1-9): ";

    cin >> Oinput;
    Oinput--; //decrease by one since we start from 0 so the max is 8

    if (Oinput < 0 || Oinput > 8) // if it is bigger than 8 or smaller than 0 
    {
      cout << "The number is not vaild for the game, please select your choice from (1-9)." << endl;
    }
    else if (board[Oinput] != ' ')
    {
      cout << "This space had been taken, please select an empty space." << endl;
    }
    else 
    { 
      board[Oinput] = 'O';
      break;
    }
  }
}

/*
* Count the number of total O or X on the game board
*/
int count_board(char symbol)
{
  int total = 0;
  for (int i = 0 ; i < 9; i++)
  {
    if (board[i] == symbol)
        total += 1;
  }
  return total;
}

/*
* Check for the winner usually it is horizontal, vertical or diagaonal
*/
char check_winner()
{
  // checking hor  return what ever is is O or X
  if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
  return board[0];
  if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
  return board[3];
  if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
  return board[6];

  // checking ver return what ever is is O or X

  if(board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
  return board[0];
  if(board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
  return board[1];
  if(board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
  return board[2];


// check diagonal return what ever is is O or X

if(board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
  return board[0];
  if(board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
  return board[2];
//the total of X and O should not be over the size of the board which is 9
if (count_board('X') + count_board('O') < 9)
{
  return 'C'; // for continal the game
}
else 
{
  return 'D'; // for draw
}

}

/*
*computer VS player mode 
*Player goes first 
*/
void player_ai()
{
  string player_name;
  cout << "Enter your name as player: ";
  cin >> player_name;


  while(true)
  {
    system("clear"); // clear the screen
    display_board();
    // when the board is clear of X or O
    if (count_board('X') == count_board('O'))
    {
        cout << player_name << " it is your turn right now." << endl;
        x_player_turn();
    }
    else 
    {
      computer_turn();
    }

    char winner = check_winner();
    if (winner == 'X')
    {
      system("clear");
      display_board();
      cout << player_name << " is the winner" << endl;
      break;
    }
    else if (winner == 'O')
    {
      system("clear");
      display_board();
      cout << "Computer is the winner." << endl;
      break;
    }
    else if (winner == 'D')
    {
      cout << "The game is draw." << endl;
      break;
    }
  }

  char gameStatus = ' ';
    cout << "What would you like to do? (R for Retry/ Q for Quit)" << endl;
    cin >> gameStatus;
    switch(gameStatus)
    {
      case 'R':
    board[0] = ' ';
    board[1] = ' ';
    board[2] = ' ';
    board[3] = ' ';
    board[4] = ' ';
    board[5] = ' ';
    board[6] = ' ';
    board[7] = ' ';
    board[8] = ' ';
    player_ai();
      break;
      case 'Q':
      cout << "Thank you for playing!" << endl;
      main();
      break;
      default:
      cout << "Please Type R for Replay or Q for Quit" << endl;

    }
}


/*
*computer VS player mode 
*computer's turn first when playing with user
*/

void ai_player()
{
  string player_name;
  cout << "Enter your name as a player: ";
  cin >> player_name;

  while(true)
  {
    system("clear"); // clean the memory
    display_board();
    
    cout << "Computer had made his turn." << endl;
    cout << player_name << " 's turn right now." << endl;
    if (count_board('X') == count_board('O'))
    {   
      computer_turn();
    }
    else 
    {
      x_player_turn();
    }
      

    char winner = check_winner();
    if (winner == 'X')
    {
      system("clear");
      display_board();
      cout << player_name << " is the winner" << endl;
      break;
    }
    else if (winner == 'O')
    {
      system("clear");
      display_board();
      cout << "Computer is the winner." << endl;
      break;
    }
    else if (winner == 'D')
    {
      cout << "The game is draw." << endl;
      break;
    }
  }
  char gameStatus = ' ';
    cout << "What would you like to do? (R for Retry/ Q for Quit)" << endl;
    cin >> gameStatus;
    switch(gameStatus)
    {
      case 'R':
    board[0] = ' ';
    board[1] = ' ';
    board[2] = ' ';
    board[3] = ' ';
    board[4] = ' ';
    board[5] = ' ';
    board[6] = ' ';
    board[7] = ' ';
    board[8] = ' ';
    ai_player();
      break;
      case 'Q':
       cout << "Thank you for playing!" << endl;
      main();
      break;
      default:
      cout << "Please Type R for Replay or Q for Quit" << endl;
    }
}

/*
* Player VS Player game mode
*/
void player_player()
{ 
  // for player or X
  string x_player;
  cout << "Enter Player X 's name: ";
  cin >> x_player;
   // for player or O
  string o_player;
  cout << "Enter Player O 's name: ";
  cin >> o_player;


  while(true)
  { 
    // clear the screen
    system("clear");
    display_board();
    if (count_board('X') == count_board('O'))
    {
        cout << x_player << " it is your turn right now" << endl;
        x_player_turn();
    }
    else 
    {
      cout << o_player << "it is your turn right now" << endl;
      o_player_turn();
    }

    // check for winner 
    char winner = check_winner();
    if (winner == 'X')
    {
      system("clear");
      display_board();
      cout << x_player << " is the winner" << endl;
      break;
    }
    else if (winner == 'O')
    {
      system("clear");
      display_board();
      cout << o_player << " is the winner" << endl;
      break;
    }
    else if (winner == 'D')
    {
      cout << "The game is draw." << endl;
      break;
    }
  }

  char gameStatus = ' ';
    cout << "What would you like to do? (R for Retry/ Q for Quit)" << endl;
    cin >> gameStatus;
    switch(gameStatus)
    {
      case 'R':
    board[0] = ' ';
    board[1] = ' ';
    board[2] = ' ';
    board[3] = ' ';
    board[4] = ' ';
    board[5] = ' ';
    board[6] = ' ';
    board[7] = ' ';
    board[8] = ' ';
    player_player();
      break;
      case 'Q':
       cout << "Thank you for playing!" << endl;
      main();
      break;
      default:
      cout << "Please Type R for Replay or Q for Quit" << endl;
    }
}

