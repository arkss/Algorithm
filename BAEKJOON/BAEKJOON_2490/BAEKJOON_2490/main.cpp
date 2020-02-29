#include <iostream>

int main(int argc, const char * argv[]) {
    int i,j;
    
    int zero_count = 0;
    
    
    int stick;
    // 총 3번
    for(i=0;i<3;i++){
        // '배' 가 나온 횟수를 세주자.
        zero_count = 0;
        // 4개의 윷가락의 정보를 받음
        for(j=0;j<4;j++){
            std::cin >> stick;
            if (stick == 0)
                zero_count++;
        }
        
        switch(zero_count){
            case 0:
                std::cout << "E" <<std::endl;
                break;
            case 1:
                std::cout << "A" <<std::endl;
                break;
            case 2:
                std::cout << "B" <<std::endl;
                break;
            case 3:
                std::cout << "C" <<std::endl;
                break;
            case 4:
                std::cout << "D" <<std::endl;
                break;
        }
    }
}
