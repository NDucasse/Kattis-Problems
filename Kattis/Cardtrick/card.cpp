#include <iostream>
#include <deque>

using namespace std;

void printq(deque<int> d);

int main() {
    int num = 0;
    int cards = 0;
    int card = 0;
    cin >> num;
    deque<int> deck;
    for(int i = 0; i<num; i++) {
        cin >> cards;
        for(int j = 0; j<cards; j++) {
            deck.push_back(0);
        }
        for(int j = 1; j<=cards; j++) {
            for(int k = 1; k<=j; k++) {
                card = deck.front();
                deck.pop_front();
                deck.push_back(card);
                if(card != 0) {
                    k--;
                }
            }
            while(true) {
                if(deck.front() == 0) {
                    deck.pop_front();
                    deck.push_back(j);
                    break;
                }else {
                    card = deck.front();
                    deck.pop_front();
                    deck.push_back(card);
                }
            }
        }
//        printq(deck);
        while(deck.size() >1) {
            card = deck.front();
            deck.pop_front();
            if(deck.front() == 1) {
                deck.push_front(card);
                break;
            }         
            deck.push_front(card);   
            deck.push_back(deck.front());
            deck.pop_front();
        }
        while(!deck.empty()) {
            cout << deck.front() << ' ';
            deck.pop_front();
        }
        cout << endl;
    }
}



void printq(deque<int> d) {
    for(int i = 0; i<d.size(); i++) {
        cout << d.front() << ' ';
        d.push_back(d.front());
        d.pop_front();
    }
    cout << endl;
} 
