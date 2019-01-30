#include <iostream>
#include <algorithm>

int main(int argc, const char * argv[]) {
    int arr[3];
    int i;
    
    for (i=0;i<3;i++){
        std::cin >> arr[i];
    }

    std::sort(arr,arr+3);
    std::cout << arr[1];
}
