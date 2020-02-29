#include <iostream>
#include <math.h>

int main(int argc, const char * argv[]) {
    std::string color[] = {"black","brown","red","orange", "yellow", "green","blue","violet","grey","white"};
    
    
    std::string first;
    std::string second;
    std::string third;

    std::cin >> first;
    std::cin >> second;
    std::cin >> third;
    
    long long result = 0;
    
    for (int i=0;i<10;i++){
        if (first.compare(color[i]) == 0)
            result += i * 10;
        if (second.compare(color[i]) == 0)
            result += i;
    }
    for (int i=0;i<10;i++){
        if (third.compare(color[i]) == 0)
            result *= pow(10,i);
    }
    
    std::cout << result;
    
}
