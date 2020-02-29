#include <iostream>

int main(int argc, const char * argv[]) {
    int payment;
    
    std::cin >> payment;
    
    int change = 1000-payment;
    
    int count = 0;
    
    int change_money[6] = {500,100,50,10,5,1};
    
    for (int i=0;i<6;i++){
        count += int(change / change_money[i]);
        change = change % change_money[i];
    }
    std::cout << count;
}
