#include <iostream>

int arr[10001];

int main(int argc, const char * argv[]) {
    int N,X;
    int i;
    
    std::cin >> N >> X;
    
    for(i=0;i<N;i++){
        std::cin >> arr[i];
        if (arr[i]<X)
            std::cout << arr[i] << " ";
    }
    
}
