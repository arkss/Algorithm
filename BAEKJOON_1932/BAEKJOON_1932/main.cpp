#include <iostream>

int max_func(int a, int b)
{
    return a>b ? a:b;
}

int main(int argc, const char * argv[]) {

    int arr_size;
    int i, j;
    
//    std::cout << "값을 입력하세요\n";
    std::cin >> arr_size;
    
    
    int arr[arr_size][arr_size]; // 배열을 초기화 하기 위해 여기다가 0을 대입하면 왜 안되는걸까
    
    // 일단은 0으로 초기화
    for (i=0;i<arr_size;i++){
        for (j=0;j<arr_size;j++){
            arr[i][j] = 0;
        }
    }
    
    
    // 값 대입
    for (i=0;i<arr_size;i++){
        for (j=0;j<i+1;j++){
            std::cin >> arr[i][j];
        }
    }
    
    // arr_size - 1 레벨 부터 자식 노드들 중 택할 수 있는 최대값을 택한다.
    for (i=arr_size-2;i>=0;i--){
        for (j=0;j<i+1;j++){
            arr[i][j] += max_func(arr[i+1][j],arr[i+1][j+1]);
        }
    }
    
    
    
     //배열의 값 확인
//    for (i=0;i<arr_size;i++){
//        for (j=0;j<arr_size;j++){
//            std::cout.width(3);
//            std::cout << arr[i][j];
//        }
//        std::cout << "\n";
//    }
    std::cout << arr[0][0];
    
    
    
    return 0;
}
