#include <iostream>

using namespace std;

int card[101];

int main(int argc, const char * argv[]) {
    int N,M;
    
    cin >> N >> M;
    
    int i,j,k;
    int sum;
    int max = 0;
    
    for(i=0;i<N;i++){
        cin >> card[i];
    }
    // 3중 반복문으로 모든 경우를 순회해서 21이 넘지 않는 수 중 최대값을 구한다.
    for(i=0;i<N-2;i++){
        for(j=i+1;j<N-1;j++){
            for(k=j+1;k<N;k++){
                sum = card[i] + card[j] + card[k];
                if (sum > M)
                    continue;
                else if (sum > max)
                    max = sum;
            }
        }
    }
    cout << max;
    
    
    
}
