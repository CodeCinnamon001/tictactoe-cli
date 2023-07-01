#include <iostream>
#include <ctime>
#include <cstring>

class TicTacToe {
  public:
  char user_one;
  char user_two;
  bool running = true;
 protected:
  char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  public:
  void set_value();
  void draw_board();
  bool check_win();
  bool check_tie();
};

class Player: public TicTacToe {
  public:
  void user_one_move();
  void user_two_move();
  Player(Player &obj) {
   obj.set_value();
   obj.draw_board();

  while (obj.running) {

    obj.user_one_move();

    obj.draw_board();

    if (obj.check_win()) {

      obj.running = false;

      break;

    }

    else if (obj.check_tie()) {

      obj.running = false;

      break;
    }

    obj.user_two_move();

    obj.draw_board();

    if (obj.check_win()) {

      obj.running = false;

      break;

    }

    else if (obj.check_tie()){

      obj.running = false;

      break;
    }
  }
  std::cout << "Thanks for playing!\n";
  }
};
class Player_Bot: public TicTacToe {
  public: 
  void player_move();
  void bot_move();
  Player_Bot(Player_Bot &obj){
   obj.set_value();
   obj.draw_board();

  while (obj.running) {

    obj.player_move();

    obj.draw_board();

    if (obj.check_win()) {

      obj.running = false;

      break;

    }

    else if (obj.check_tie()) {

      obj.running = false;

      break;
    }

    obj.bot_move();

    obj.draw_board();

    if (obj.check_win()) {

      obj.running = false;

      break;

    }

    else if (obj.check_tie()){

      obj.running = false;

      break;
    }
  }
  std::cout << "Thanks for playing!\n";
  }
  
};


void TicTacToe::set_value() {
  std::cout << "Choose X or O: ";
  std::cin >> user_one;
  user_one = toupper(user_one);
  if(user_one == 'X' || user_one == 'O' ) {
    std::cout << "You have choosen " << user_one << std::endl;
    }
  else{
    std::cout << "invalid input " <<std::endl;
   }
  
  // computer value 
  if(user_one == 'X') {
     user_two = 'O';
  }
  else {
    user_two = 'X';
  }
}

void TicTacToe::draw_board() {
  std::cout << '\n';

  std::cout << "     |     |     " << '\n';

  std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2]
            << "  " << '\n';

  std::cout << "_____|_____|_____" << '\n';

  std::cout << "     |     |     " << '\n';

  std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5]
            << "  " << '\n';

  std::cout << "_____|_____|_____" << '\n';

  std::cout << "     |     |     " << '\n';

  std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8]
            << "  " << '\n';

  std::cout << "     |     |     " << '\n';

  std::cout << '\n';
}

void Player::user_one_move() {

  int number;

  do {

    std::cout << "Enter a spot to place a marker (1-9): ";

    std::cin >> number;

    number--;

    if (spaces[number] == ' ') {

      spaces[number] = user_one;

      break;
    }

  } while (!number > 0 || !number < 8);
}


void Player::user_two_move() {

  int number;

  do {

    std::cout << "Enter a spot to place a marker (1-9): ";

    std::cin >> number;

    number--;

    if (spaces[number] == ' ') {

      spaces[number] = user_two;

      break;
    }

  } while (!number > 0 || !number < 8);
}

bool TicTacToe::check_win() {

  if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) &&
      (spaces[1] == spaces[2])) {

    spaces[0] == user_one ? std::cout << "Player1 WIN!\n"
                        : std::cout << "Player1 WIN!\n";

  }

  else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) &&
           (spaces[4] == spaces[5])) {

    spaces[3] == user_one ? std::cout << "Player1 WIN!\n"
                        : std::cout << "Player2 WIN!\n";

  }

  else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) &&
           (spaces[7] == spaces[8])) {

    spaces[6] == user_one ? std::cout << "Player1 WIN!\n"
                        : std::cout << "Player2 WIN!\n";

  }

  else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) &&
           (spaces[3] == spaces[6])) {

    spaces[0] == user_one ? std::cout << "Player1 WIN!\n"
                        : std::cout << "Player2 WIN!\n";

  }

  else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) &&
           (spaces[4] == spaces[7])) {

    spaces[1] == user_one ? std::cout << "Player1 WIN!\n"
                        : std::cout << "Player2 WIN!\n";

  }

  else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) &&
           (spaces[5] == spaces[8])) {

    spaces[2] == user_one ? std::cout << "Player1 WIN!\n"
                        : std::cout << "Player2 WIN!\n";

  }

  else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) &&
           (spaces[4] == spaces[8])) {

    spaces[0] == user_one ? std::cout << "Player1 WIN!\n"
                        : std::cout << "Player2 WIN!\n";

  }

  else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) &&
           (spaces[4] == spaces[6])) {

    spaces[2] == user_one ? std::cout << "Player1 WIN!\n"
                        : std::cout << "Player2 WIN!\n";

  }

  else {

    return false;
  }

  return true;
}

bool TicTacToe::check_tie() {

  for (int i = 0; i < 9; i++) {

    if (spaces[i] == ' ') {

      return false;
    }
  }

  std::cout << "IT'S A TIE!\n";

  return true;
}

void Player_Bot::player_move() {
  int number;

  do {

    std::cout << "Enter a spot to place a marker (1-9): ";

    std::cin >> number;

    number--;

    if (spaces[number] == ' ') {

      spaces[number] = user_one;

      break;
    }

  } while (!number > 0 || !number < 8);
}

void Player_Bot::bot_move() {
  int number;

  srand(time(0));

  while (true) {

    number = rand() % 9;

    if (spaces[number] == ' ') {

      spaces[number] = user_two;

      break;
    }
  }
}

int main() {

  int choice;
  std::cout <<"1.Singleplayer Mode "<<std::endl;
  std::cout <<"2.Multiplayer Mode "<<std::endl;
 while(true){

  std::cout << "Choose The GameMode :  ";
  std::cin >> choice;
  if(choice == 1) {
    Player_Bot game_one(game_one);
    break;
    }
  if (choice == 2){
    Player game_two(game_two);
    break;
    }
  else std::cout << "invalid input"<<std::endl;
    }
  return 0;
}
  
