#include <iostream>
#include <math.h>

int main(int argc, const char * argv[]) {
    
    int num = 1;
    int i,j;
    int prime_count = 0;
    
    while (num){
        std::cin >> num;
        prime_count = 0;
        for(i=num+1;i<=2*num;i++){
            for(j=2;j<=pow(i,0.5);j++){
                if(i%j==0)
                    break;
            }
            if (j>pow(i,0.5)){
                prime_count++;
            }
        }
        std::cout << prime_count << std::endl;
    }
}
