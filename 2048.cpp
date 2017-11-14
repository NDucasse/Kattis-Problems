/*
2048 is a single-player puzzle game created by Gabriele Cirulli1.
It is played on a 4×4 grid that contains integers ≥2 that are powers of 2. 
The player can use a keyboard arrow key (left/up/right/down) to move all the tiles simultaneously. 
Tiles slide as far as possible in the chosen direction until they are stopped by either another tile or the edge of the grid.
If two tiles of the same number collide while moving, they will merge into a tile with the total value of the two tiles that collided. 
The resulting tile cannot merge with another tile again in the same move.
Please observe this merging behavior carefully in all Sample Inputs and Outputs.

Input
The input is always a valid game state of a 2048 puzzle. 
The first four lines of input, that each contains four integers, 
describe the 16 integers in the 4×4 grid of 2048 puzzle. 
The j-th integer in the i-th line denotes the content of the cell located at the i-th row and the j-th cell. 
For this problem, all integers in the input will be either {0, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024}.
Integer 0 means an empty cell.

The fifth line of input contains an integer 0, 1, 2, or 3 that denotes a left, up, right, or down move 
executed by the player, respectively.

Output
Output four lines with four integers each.
Two integers in a line must be separated by a single space. 
This describes the new state of the 4×44×4 grid of 2048 puzzle.
Again, integer 0 means an empty cell. Note that in this problem,
you can ignore the part from the 2048 puzzle where it introduces a new random tile 
with a value of either 2 or 4 in an empty spot of the board at the start of a new turn.
*/

#include <iostream>
using namespace std;

void move(int board[4][4], int direction);

int main() {
    int board[4][4] = {{0}};
    int direction = 0;
    int curr = 0;

    for(int i = 0; i<4; i++) {
        for(int j = 0; j<4; j++) {
            cin >> board[i][j];
        }
    }

    cin >> direction;
    
    if(direction == 0) {
        for(int i = 0; i < 4; i++) {
            curr = 0;
            for(int j = 1; j < 4; j++) {
                if(board[i][j] == 0) {
                    continue;
                } else if(board[i][j] == board[i][curr]) {
                    board[i][curr] += board[i][j];
                    board[i][j] = 0;
                }else if(board[i][curr] == 0) {
                    board[i][curr] += board[i][j];
                    board[i][j] = 0;
                    continue;
                }
                curr++;
                if(curr != j) {
                    j--;
                }
            }
        }
    }else if(direction == 1) {
        for(int i = 0; i < 4; i++) {
            curr = 0;
            for(int j = 1; j < 4; j++) {
                if(board[j][i] == 0) {
                    continue;
                } else if(board[j][i] == board[curr][i]) {
                    board[curr][i] += board[j][i];
                    board[j][i] = 0;
                }else if(board[curr][i] == 0) {
                    board[curr][i] += board[j][i];
                    board[j][i] = 0;
                    continue;
                }
                curr++;
                if(curr != j) {
                    j--;
                }
            }
        }
    }else if(direction == 2) {
        for(int i = 0; i < 4; i++) {
            curr = 3;
            for(int j = 2; j >= 0; j--) {
                if(board[i][j] == 0) {
                    continue;
                } else if(board[i][j] == board[i][curr]) {
                    board[i][curr] += board[i][j];
                    board[i][j] = 0;
                }else if(board[i][curr] == 0) {
                    board[i][curr] += board[i][j];
                    board[i][j] = 0;
                    continue;
                }
                curr--;
                if(curr != j) {
                    j++;
                }
            }
        }
    }else if(direction == 3) {
        for(int i = 0; i < 4; i++) {
            curr = 3;
            for(int j = 2; j >= 0; j--) {
                if(board[j][i] == 0) {
                    continue;
                } else if(board[j][i] == board[curr][i]) {
                    board[curr][i] += board[j][i];
                    board[j][i] = 0;
                }else if(board[curr][i] == 0) {
                    board[curr][i] += board[j][i];
                    board[j][i] = 0;
                    continue;
                }
                curr--;
                if(curr != j) {
                    j++;
                }
            }
        }
    }

    for(int i = 0; i<4; i++) {
        for(int j = 0; j<4; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
