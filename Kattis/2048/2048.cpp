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
