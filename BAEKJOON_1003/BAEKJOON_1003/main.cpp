#include <iostream>


// 배열의 크기 어떻게 구하지?

int main(int argc, const char * argv[]) {
    int num;
    int i;
    int question[10000]; // num만 들어오는 수들을 저장
    int answer[10000][2] = {{1,0},{0,1}};
    // n행 1열에는 n에 대해서 0이 몇 번 나오는지
    // n행 2열에는 n에 대해서 1이 몇 번 나오는지 저장
    // 단 n행에 대한 기준은 0행부터 시작한다고 가정한다.
    
    
    int max = 0; // 입력되는 값들 중 최대값. 그 값까지만 구하면 된다.
    
    
    // 몇 번 반복할지
    std::cin >> num;
    
   
    
    // 들어온 수 중 최대값을 구해서 최대값 까지만 계산한다.
    for (i=0;i<num;i++){
        std::cin >> question[i];
        if (max < question[i])
            max = question[i];
    }
    
    // dp적으로 앞의 값들을 이용해서 게산
    for (i=2;i<=max;i++){
        answer[i][0] = answer[i-2][0] + answer[i-1][0];
        answer[i][1] = answer[i-2][1] + answer[i-1][1];
    }
    
    // 값 출력
    for (i=0;i<num;i++){
        int index = question[i];
        std::cout << answer[index][0] << " "<< answer[index][1] << std::endl;
    }
}
