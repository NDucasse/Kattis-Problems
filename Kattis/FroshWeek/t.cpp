#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream fout;
    fout.open("test.txt");
    fout << "1000000" << endl;
    for(int i = 1; i <= 1000000; i++) {
        fout << i << endl;
    }
    fout.close();
}
