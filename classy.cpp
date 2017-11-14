/*
In his memoir “So, Anyway”, comedian John Cleese writes of the class difference 
between his father (who was “middle-middle-middle-lower-middle class”) and 
his mother (who was “upper-upper-lower-middle class”). 
These fine distinctions between classes tend to confuse North American readers, 
so you are to write a program to sort a group of people by their classes to show their true place in the social class hierarchy.

For this problem, there are three main classes: upper, middle, and lower. 
Obviously, the highest is upper and the lowest is lower. 
But there can be distinctions within a class, so upper-upper is a higher class than middle-upper, which is higher than lower-upper. 
However, all of the upper classes (upper-upper, middle-upper, and lower-upper) are higher than any of the middle classes.

Within a class like middle-upper, there can be further distinctions as well, leading to classes like lower-middle-upper-middle-upper.
When comparing classes, once you have reached the lowest level of detail, 
you should assume that all further classes are the same as the middle level of the previous level of detail.
So upper class and middle-upper class are equivalent, as are middle-middle-lower-middle and lower-middle.

Input
The first line of input contains a single positive integer T (T≤500) indicating the number of cases to follow. 
Each case starts with a positive integer n (n≤100) on a line indicating the number of people to consider.
Each of the next nn lines contains the name of a person followed by a colon and a space, followed by the class of the person.
The name contains up to 30 lowercase characters.
The class is a string consisting of a nonempty sequence of up to 10 
of the words upper, middle, lower separated by hyphens (-), followed by a space, followed by the word class.
No two people will have the same name in a single case.

Output
For each test case, print the list of names from highest to lowest class. 
If two people have the same or equivalent classes, they should be listed in alphabetical order by name.
Output a line of 30 equal signs (=) after each case.
*/


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
