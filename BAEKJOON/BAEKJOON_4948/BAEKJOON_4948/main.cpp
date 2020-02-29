#include <iostream>
#include <math.h>

// 에라토스테네스의 체
#define SIZE 123456*2
int arr[SIZE+1];

int main(int argc, const char *argv[])
{
    int i,j;
    int num = 1;// 각 테이트 케이스의 수를 받을 변수
    int prime_count = 0; // 소수의 수
    
    // 배열 초기화
    for(i=2;i<=SIZE;i++){
        arr[i] = i;
    }
    
    for (i=2;i<=sqrt(SIZE);i++){
        // 이미 체크된 수의 배수들은 합성수임이 자명
        if(arr[i] == 0)
            continue;
        // i를 제외한 i의 배수들을 0으로 체크
        for (j=i+i;j<=SIZE;j+=i){
            arr[j] = 0;
        }
    }
    
    while (num){
        std::cin >> num;
        if (num==0)
            break;
        prime_count = 0;
        for(i=num+1;i<=2*num;i++){
            
            if (arr[i]!=0){
                prime_count++;
            }
        }
        std::cout << prime_count <<std::endl;
    }
    
}









// 시간초과

//int main(int argc, const char * argv[]) {
//
//    int num = 1;
//    int i,j;
//    int prime_count = 0;
//
//    while (num){
//        std::cin >> num;
//        prime_count = 0;
//        for(i=num+1;i<=2*num;i++){
//            for(j=2;j<=pow(i,0.5);j++){
//                if(i%j==0)
//                    break;
//            }
//            if (j>pow(i,0.5)){
//                prime_count++;
//            }
//        }
//        std::cout << prime_count << std::endl;
//    }
//}
