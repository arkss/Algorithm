#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int burger[3];
    int drink[2];
    int i;
    int burger_min = 2000;
    int drink_min = 2000;
    for(i=0;i<3;i++){
        cin >>burger[i];
        if (burger_min > burger[i])
            burger_min = burger[i];
    }
    for(i=0;i<2;i++){
        cin >>drink[i];
        if (drink_min > drink[i])
            drink_min = drink[i];
    }
    
    cout << burger_min + drink_min - 50;
}
