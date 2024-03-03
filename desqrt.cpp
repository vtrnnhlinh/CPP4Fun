#include <string>
#include <iostream>
int main() {
    std::string s;
    std::cin >> s;
    int result = 0;
    std::string::size_type sz;
    sz = s.find(" ");
    if (std::string::npos == sz) {
        int n = std::stoi(s);
        result = n*n;
    }
    else {
        if (sz == 4) {
            int m = std::stoi(s.substr(sz + 1));
            result = m;
        }
        else {
            int n = std::stoi(s.substr(0, sz));
            s = s.substr(n + 1);
            sz = s.find(" ");
            int m = std::stoi(s.substr(sz + 1));
            result = n*n*m;
        }
    }
    std::cout << result << std::endl;
}