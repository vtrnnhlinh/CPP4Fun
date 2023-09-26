#include <iostream>
#include <string>
using namespace std;

bool hasSpace(const std::string& str, size_t index = 0) {

    if (index == str.length())
        return false;


    if (str[index] == ' ')
        return true;


    return hasSpace(str, index + 1);
}

int findCharBeforeSpace(const std::string& s, int index = -1) {

    if (index == s.size() || s[index] == ' ')
        return index - 1;


    return findCharBeforeSpace(s, index + 1);
}

string reverseSentence(string s) {

    if (!hasSpace(s)) return s;
    
else {
        string temp = s;
        return reverseSentence(temp.erase(0, findCharBeforeSpace(s)+2)) + " " + s.substr(0, findCharBeforeSpace(s)+1);
    }
}
int main () {
  	string s = "data structure and algorithm is scary";
  	// cout << reverseSentence(s);
  	// cout << findCharBeforeSpace(s);
  	string temp2 = s.substr(0, findCharBeforeSpace(s)+1);
  	//string temp1 = s.erase(0, findCharBeforeSpace(s)+2);
  	
  	cout << temp2 << endl << s << endl;
  	cout << reverseSentence(s);
    return 0;
}