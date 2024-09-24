#include <iostream>
using namespace std;
int printDecreasing(int num, int goal) {
  cout << num << " ";
  if (num <= goal) {
    return num;
  }
  return printDecreasing(num - 5, goal);
}

void printIncreasing(int num, int goal) {
  if (num > goal) {
    return;
  }
  cout << num << " ";
  printIncreasing(num + 5, goal);
}

void printPattern(int n) {
  if (n < 0) {
    return;
  }
  if (n == 0) {
    cout << n;
    return;
  }
  int flag = printDecreasing(n, 0);
  printIncreasing(
      flag + 5,
      n); // Starts from the value after the lowest point (0 or negative)
}
int main() {
  for (int i = -1; i < 11; i++) {
    printPattern(i);
    cout << endl;
  }

  return 0;
}
