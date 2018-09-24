#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Classy {
  public:
    Classy(string n, int s) : name(n), score(s) {}
    friend ostream &operator<<(ostream &out, const Classy &cl);

    int score;
    string name;

};

ostream &operator<<(ostream &out, const Classy &cl) {

    out << cl.name;

    return out;

}

bool sortfunc(Classy *one, Classy *two) {
    if((*one).score != (*two).score) {
        return (*one).score > (*two).score;
    }
    return (*one).name.compare((*two).name) < 0;
} 

int findstrval(string t);

int main() {
    int loops = 0;
    int people = 0;
    int score = 0;
    int strpos = 0;
    int it;
    int end;
    string name;
    string temp;
    string classbit;
    vector<Classy*> classlist;
    Classy *classtemp;

    cin >> loops;
    
    if(loops > 500) {return 0;}

    for(int i = 0; i<loops; i++) {

        cin >> people;

        if(people > 100) {continue;}

        for(int j = 0; j<people; j++) {

            cin >> name;

            name = name.substr(0, name.length()-1);

            cin >> temp;

            it = 9;
            score = 0;
            strpos = 0;
            end = 0;

	        reverse(temp.begin(), temp.end());

            while(it>=0 && strpos < temp.length()) {

                if(temp.find("-", strpos) == -1) {end = temp.length();}

                else {end = temp.find("-", strpos);}

                classbit = temp.substr(strpos, (end - strpos));

                reverse(classbit.begin(), classbit.end());

                strpos = end + 1;

                score += findstrval(classbit) * pow(10, it--);

            }

            cin >> temp;
            
            classtemp = new Classy(name, score);

            classlist.push_back(classtemp);    
    
        }

        sort(classlist.begin(), classlist.end(), sortfunc);

        for(auto x : classlist) {

            cout << *x << endl;

        }

        cout << "==============================" << endl;

	    while(classlist.empty() == false) {
		    classlist.pop_back();
	    }
    }

  


}



int findstrval(string t) {

    if(t == "upper") {

        return 1;

    }else if(t == "middle") {

        return 0;

    }

    return -1;

}
