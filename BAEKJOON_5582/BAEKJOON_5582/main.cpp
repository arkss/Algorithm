
#include <iostream>

int main(int argc, const char * argv[]) {
    std::string first;
    std::string second;
    
    std::cin >> first;
    std::cin >> second;
    
    int max_size = 0;
    int i,j,k;
    
    for (i=0;i<second.size();i++){
        for (j=0;j<first.size();j++){
            if (second.at(i) == first.at(j)){
                k = i;
                max_size = 1;
            }
            
            
            
            
                
        }
    }
    
    
}
