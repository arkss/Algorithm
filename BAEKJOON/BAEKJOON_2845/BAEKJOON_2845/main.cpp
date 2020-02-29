#include <iostream>

int main(int argc, const char * argv[]) {
    int num,area;
    int article[5];
    int i;
    
    std::cin >> num >> area;
    
    for(i=0;i<5;i++){
        std::cin >> article[i];
        std::cout << article[i]-num*area  << std::endl;
    }
}
