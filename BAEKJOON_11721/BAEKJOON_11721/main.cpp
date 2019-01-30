#include <iostream>
#include <string.h>

int main(int argc, const char * argv[]) {
    char arr[101];
    int i,count = 0;
    
    std::cin >> arr;
    for (i=0;i<strlen(arr);i++){
        std::cout << arr[i];
        count++;
        if (count % 10 == 0)
            std::cout << std::endl;
    }
    
}
