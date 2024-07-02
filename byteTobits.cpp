#include <iostream>
using namespace std;

int main() {
    uint8_t byteData = 0x08;

    for (int i = 0; i < 8; i++) {
        int bit = (byteData >> i) & 1;
        cout << bit;
    }
    return 0;
}
