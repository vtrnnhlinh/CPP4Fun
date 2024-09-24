#include <iostream>
#include <string.h>
using namespace std;
int calPower(int base, int exponent) {
  if (exponent == 0) {
    return 1;
  }
  return base * calPower(base, exponent - 1);
}

int myArrayToInt(char *str, int n) {
  if (n == 0) {
    return 0; // Base case: all digits processed
  }
  // Process current digit and recursively convert the rest
  return (str[0] - '0') * calPower(10, n - 1) + myArrayToInt(str + 1, n - 1);
}
int main() {
  char str[] = "2020";
  printf("%d", myArrayToInt(str, 4));
}
