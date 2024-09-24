#include <iostream>
#include <string.h>
using namespace std;
bool isPalindromeHelper(string str, int s, int e) {
  if (s == e) {
    return true;
  }

  if (s + 1 == e && str[s] != ' ' && str[e] != ' ') {
    if (str[s] == str[e])
      return true;
    else
      return false;
  }
  if (str[s] == ' ') {
    return isPalindromeHelper(str, s + 1, e);
  }
  if (str[e] == ' ') {
    return isPalindromeHelper(str, s, e - 1);
  }
  if (str[s] == str[e]) {
    return isPalindromeHelper(str, s + 1, e - 1);
  } else
    return false;
}

bool isPalindrome(string str) {
  int len = str.length();
  return isPalindromeHelper(str, 0, len - 1);
}
int main() { cout << isPalindrome("do geese see god"); }
