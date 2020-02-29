#include <iostream>

int main(int argc, const char * argv[]) {
    int date;
    int violation = 0;
    int car_num;
    std::cin >> date;

    for(int i=0;i<5;i++){
        std::cin >> car_num;
        if (car_num == date)
            violation ++;
    }
    std::cout << violation;
}
