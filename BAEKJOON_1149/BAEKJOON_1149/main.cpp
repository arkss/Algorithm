#include <iostream>

// 값을 비교하여 작은 값 return
int min(int a,int b)
{
    return a>b ? b:a;
}
int main(int argc, const char * argv[]) {
    int num;
    int i,j;
    int result;
    std::cin >> num;
    
    //  2차원 배열에 값 대입
    int arr[num][num];
    for (i=0;i<num;i++){
        for (j=0;j<3;j++){
            std::cin >> arr[i][j];
        }
    }
    
    for (i=0;i<num-1;i++){
        // 바로 위의 집이 아닌 집 중 비용이 적게 드는 집을 계속 더해 나가서 맨 아래 층에 도달했을 때
        arr[i+1][0] += min(arr[i][1],arr[i][2]);
        arr[i+1][1] += min(arr[i][0],arr[i][2]);
        arr[i+1][2] += min(arr[i][1],arr[i][0]);
    }
    //세 경우 중 최소값을 구한다.
    result = min(arr[num-1][0],arr[num-1][1]);
    result = min(arr[num-1][2],result);
    
    std::cout << result << std::endl;
    
    
    
    
    // 배열에 잘담기는 확인
//    for (i=0;i<num;i++){
//        for (j=0;j<3;j++){
//            std::cout << arr[i][j];
//        }
//        std::cout << std::endl;
//    }
    
}
