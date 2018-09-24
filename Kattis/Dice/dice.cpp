#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

void RowReduce(float grid[3][4]);

void printmatrix(float A[3][4]);

bool CheckGrid(float grid[3][4]);

void gridswap(float row1[4], float row2[4]);

void swaprows(float grid[3][4]);

int main() {
    float grid[3][4] = {{0}};
    bool flag = false;
    
    while(true) {
        for(int i = 0; i<4; i++) {
            cin >> grid[2][i] >> grid[1][i] >> grid[0][i];
            if(grid[0][i] == 0 && grid[1][i] == 0 && grid[2][i] == 0) {
                flag = true;
                break;
            }
        }
        if(flag) break;
        RowReduce(grid);
        if(CheckGrid(grid)) {
            cout << "Yes" << endl;
        }else {
            cout << "No" << endl;
        }
        
    }
}

void RowReduce(float grid[3][4]) {
    const int nrows = 3;
    const int ncols = 4;

    int lead = 0; 

    while (lead < nrows) {
        float d;
        float m;

        for (int r = 0; r < nrows; r++) {
            swaprows(grid);
            d = grid[lead][lead];
            m = grid[r][lead] / grid[lead][lead];
            for (int c = 0; c < ncols; c++) {
                if (r == lead) {
                    grid[r][c] /= d;               
                } else {
                    grid[r][c] -= grid[lead][c] * m; 
                }
            }
        }
        lead++;
    }

}

void printmatrix(float grid[3][4])
{
    int p=3;
    int q=4;

    for (int i=0; i<p; i++) {
            for (int j=0; j<q; j++) {
                    cout << setw(7) << setprecision(4) << grid[i][j] << " ";
            }
            cout << endl;
    }

    cout << endl;
}

bool CheckGrid(float grid[3][4]) {
    if(grid[0][3] <= 0.0 && grid[1][3] <= 0.0 && grid[2][3] <= 0.0) {
        return true;
    }
    if(grid[0][3] <= 0.0 || grid[1][3] <= 0.0 || grid[2][3] <= 0.0) {
        return false;
    }
    return true;
}

void gridswap(float row1[4], float row2[4]) {
    float temp [4] = {0};
    for(int i = 0; i<4; i++) {
        temp[i] = row1[i];
        row1[i] = row2[i];
        row2[i] = temp[i];
    }
}

void swaprows(float grid[3][4]) {
    while(grid[0][0] == 0 || grid[1][1] == 0 || grid[2][2] == 0) {
        gridswap(grid[0], grid[1]);
        if(grid[0][0] != 0 && grid[1][1] != 0 && grid[2][2] != 0) {
            break;
        }
        gridswap(grid[1], grid[2]);
    }
}
