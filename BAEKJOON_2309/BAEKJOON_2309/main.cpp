#include <iostream>
#include <algorithm>

int main(int argc, const char * argv[]) {
    int arr[9];
    int i,j,k;
    int sum = 0;
    
    for (i=0;i<9;i++){
        std::cin >> arr[i];
        sum += arr[i];
    }
    
    std::sort(arr,arr+9);
    
    
    for (i=0;i<9;i++){
        for (j=0;j<9;j++){
            if (i==j)
                continue;
            if (sum - arr[i]- arr[j] == 100){
                for (k=0;k<9;k++){
                    if (k==i||k==j)
                        continue;
                    std::cout << arr[k] << std::endl;
                }
                
            }
        }
    }
}
