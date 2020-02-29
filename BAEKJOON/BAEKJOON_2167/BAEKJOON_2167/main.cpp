#include <iostream>

int arr[301][301];

int main(int argc, const char * argv[]) {
    int N,M;
    int i,j,k;
    int K;
    // 시점 지점과 끝지점
    int sx,sy,ex,ey;
    int result = 0;
    
    std::cin >> N >> M;
    for (i=1;i<=N;i++){
        for (j=1;j<=M;j++){
            std::cin >> arr[i][j];
        }
    }
    
    std::cin>> K;
    
    
    for (k=0;k<K;k++){
        result = 0;
        // 단순하게 범위 내에 있는 모든 값들을 다 더해준다.
        std::cin >> sx >> sy>> ex>> ey;
        for (i=sx;i<=ex;i++){
            for(j=sy;j<=ey;j++){
                result += arr[i][j];
            }
        }
        std::cout << result << std::endl;
    }
}
