#include <iostream>

int main(int argc, const char * argv[]) {
    // 각 월 별 일수를 저장하는 배열
    int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    
    int i;
    int month,day;
    
    std::cin >> month >> day;
    
    // 해당 일 + 해당 달 이전까지의 달 = 총 일수
    for (i=0;i<month-1;i++){
        day+= arr[i];

    }
    // 7로 나눠준 나머지를 구하면 각 요일에 대응
    day = day % 7;
    switch(day){
        case 1:
            std::cout << "MON";
            break;
        case 2:
            std::cout << "TUE";
            break;
        case 3:
            std::cout << "WED";
            break;
        case 4:
            std::cout << "THU";
            break;
        case 5:
            std::cout << "FRI";
            break;
        case 6:
            std::cout << "SAT";
            break;
        case 0:
            std::cout << "SUN";
            break;
    }
    
    
}
