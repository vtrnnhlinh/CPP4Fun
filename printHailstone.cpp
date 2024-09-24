#include <iostream>
using namespace std;

void printHailstone(int number) {
  /*
   * STUDENT ANSWER
   */
  if (number == 1) {
    cout << 1;
  } else if (number % 2 == 0) {
    cout << number << " ";
    return printHailstone(number / 2);
  } else {
    cout << number << " ";
    return printHailstone(number * 3 + 1);
  }
}
int main() {
  printHailstone(32);
  return 0;
}
