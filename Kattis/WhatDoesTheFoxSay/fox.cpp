#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <istringstream>

using namespace std;

int main() {
    int num;
    cin >> num;
    string recording, line, animal, sound;
    unordered_map<string, string> sounds;
    vector<string> tok;
    char * pch;
    for(int i = 0; i < num; i++) {
        recording = "";
        line = "";
        tok.clear();
        sounds.clear();
        getline(cin, recording);
        getline(cin, line);
        while(!line.equals("what does the fox say?")) {
            animal = strtok(line.c_str(), " ");
            strtok(line, " ");
            sound = strtok(line, " ");
            sounds[animal] = sound;
            cout << animal << " " << sound << endl;
            getline(cin, line)
        }
        
    }
    
}
