#include <iostream>

int main(int argc, const char * argv[]) {
    int A, B, C;
    std::cin >> A >> B >> C;
    
    std::cout << (A+B)%C;
    std::cout << "\n";
    std::cout << (A%C + B%C)%C;
    std::cout << "\n";
    std::cout << (A*B)%C;
    std::cout << "\n";
    std::cout << (A%C * B%C)%C;
    
    return 0;
}
