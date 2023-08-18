/*............................................
  Tic-Tac-Toe Game 
  Autor: Madhusanka Wijerathne
  CPP OOP design 
  ...........................................*/

#include<iostream>
using namespace std;

class Board {
public:

    // count variable
    int count = 0;

    char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

    void print_board() {
        cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
        cout << "-----------" << endl;
        cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
        cout << "-----------" << endl;
        cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
    }

    bool update_board(int position, char type) {

        // if a player selects position n, n-1 index should be updated
        // if the position is not already filled, update the board
        if (board[position - 1] == ' ') {
            board[position - 1] = type;

            // increase the value of count by 1
            ++count;
            return true;
        }

        // if the position is already filled, ask user to select another position
        else {
            cout << "Position already selected. Select another position.";
            return false;
        }
    }

    // if all variables are selected and there is no winner, it's draw
    // return true if it's draw
    bool check_draw() {

        // check if count == 9
        if (count == 9) {
            return true;
        }
        else {
            return false;
        }
    }

    // return true if three symbols appears in a row
    bool check_winner(char type) {
        if ((board[0] == type && board[1] == type && board[2] == type)
            || (board[3] == type && board[4] == type && board[5] == type)
            || (board[6] == type && board[7] == type && board[8] == type)
            || (board[0] == type && board[3] == type && board[6] == type)
            || (board[1] == type && board[4] == type && board[7] == type)
            || (board[2] == type && board[5] == type && board[8] == type)
            || (board[0] == type && board[4] == type && board[8] == type)
            || (board[2] == type && board[4] == type && board[6] == type)) {
            return true;
        }

        else {
            return false;
        }

    }
};

class Player {
public:

    string name;
    char type;

    // function to select the player type and name
    void set_info(char type) {

        // player type is 'X' if parameter is 'X' or 'x'            
        if (type == 'X' || type == 'x') {

            // set member variable to 'X'
            this->type = 'X';

            // get player name
            cout << "Player selecting " << this->type << ", enter your name: ";
            cin >> name;
        }

        // player type is 'O' if parameter is any other character 
        else {
            this->type = 'O';
            cout << "Player selecting " << this->type << ", enter your name: ";
            cin >> name;
        }
    }
};

class Game {
public:

    Board board;

    Player player1;
    Player player2;
    Player* current_player;

    // constructor to set player data
    Game() {
        player1.set_info('X');
        player2.set_info('O');
        current_player = &player1;
    }

    void play() {
        int position;
        string message = "enter the position (1 - 9): ";

        while (true) {
            cout << current_player->name << " " << message;
            cin >> position;

            bool update = board.update_board(position, current_player->type);

            if (update) {
                board.print_board();

                if (board.check_winner(current_player->type)) {
                    cout << current_player->name << " wins!" << endl;
                    break;
                }
                else if (board.check_draw()) {
                    cout << "It's a draw!" << endl;
                    break;
                }

                if (current_player == &player1) {
                    current_player = &player2;
                }
                else {
                    current_player = &player1;
                }
            }
        }
    }

};

int main() {

    Game game;
    game.play();

    return 0;
}
