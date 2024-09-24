#include <iostream>
using namespace std;
int findMax(int *arr, int length) {
  /*
   * STUDENT ANSWER
   */
  if (length == 1) {
    return arr[0];
  }
  int maxOfRest = findMax(arr, length - 1);

  return (arr[length - 1] > maxOfRest) ? arr[length - 1] : maxOfRest;
}

int main() {
  int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
  cout << findMax(arr, 10);
}
