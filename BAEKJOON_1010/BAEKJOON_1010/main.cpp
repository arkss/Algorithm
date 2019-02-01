// 조합을 이용해서 쉽게 풀 수 있지만 시간초과 걸린다.
#include <iostream>



int main(int argc, const char * argv[]) {
    int num;
    int i,j,k;
    int Lsite=0, Rsite = 0;
   
    
    int arr[31][31]={0}; // arr[N][M] 에 N,M에 해당하는 값을 대입한다.
    
    // M=1 이면 경우의 수는 무조건 하나
    // N=1 이면 경우의 수는 M개
    for (i=1;i<31;i++){
        arr[i][1] = 1;
        arr[1][i] = i;
    }
    
    // 아래 주석이 그 문제에 해당하는 알고리즘이다.
    // arr[i][j] += arr[i-1][j-1] + arr[i-1][j-1] + ... + arr[i-1][i-1];
    // 간단하게 설명하자면 N의 첫번째 site에서 M의 첫번째 site로 연결한 경우 + M의 두번째 site로 연결한 경우 + M의 세번째 site로 연결한 경우 + ... + M의 남은 site의 개수가 N이 될 때까지 저 과정을 반복하도록 한다.
    for (i=2;i<31;i++){
        for (j=1;j<31;j++){
            for(k=1;k<=j-i+1;k++){
                arr[i][j] += arr[i-1][j-k];
            }
        }
    }
    
    // 결과 출력
    std::cin >> num;
    for (i=0;i<num;i++){
        std::cin >> Lsite >> Rsite;
        std::cout << arr[Lsite][Rsite] << std::endl;
        
        
    }
    
    
}
