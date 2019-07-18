#include <iostream>

int country[1002][3];

int main(int argc, const char * argv[]) {
    int count;
    int country_num;
    int result;
    int gold, silver, bronze;
    
    std::cin >> count >> result ;
    
    for (int i=0;i<count;i++){
        std::cin >>country_num >> gold >> silver >> bronze;
        country[country_num][0] = gold;
        country[country_num][1] = silver;
        country[country_num][2] = bronze;
    }
    
}
