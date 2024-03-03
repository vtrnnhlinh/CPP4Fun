#include <iomanip>
#include <iostream>
#include <string>
 
void print(int id, std::string::size_type n, std::string const& s)
{
    std::cout << id << ") ";
    if (std::string::npos == n)
        std::cout << "not found! n == npos\n";
    else
        std::cout << "found @ n = " << n << ", substr(" << n << ") = "
                  << std::quoted(s.substr(n)) << '\n';
}
 
int main()
{
    std::string::size_type n;
    std::string const s = "2 sqrt 2"; /*
                             ^  ^  ^
                             1  2  3          */
 
    // search from beginning of string
    n = s.find(" ");
    std::cout << "n = " << n << std::endl;
    int m = std::stoi(s.substr(n + 1));
    std::cout << "m = " << m << std::endl;
    if (n != 4) {
        int num = std::stoi(s.substr(0, n));
        
        std::cout << "num = " << num << std::endl;
    }
}