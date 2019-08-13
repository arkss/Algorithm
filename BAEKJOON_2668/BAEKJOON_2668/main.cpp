#include <iostream>

using namespace std;

int N;

int maxCount;

int list[101];
int visited[101];
int cycle[101];

int bfs(int startNum, int nextNum)
{
    if (visited[nextNum])
        return 0;

    visited[nextNum] = 1;
    
    if (startNum == nextNum || bfs(startNum, list[nextNum])){
        maxCount++;
        cycle[nextNum] = 1;
        return 1;
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> list[i];
    }
    
    
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            visited[j] = cycle[j];
        }
        bfs(i, list[i]);
        
    }

    cout << maxCount << endl;
    
    
    
    
    
    for (int i=1;i<=N;i++){
        if (!cycle[i]) continue;
        cout << i << "\n";
    }
    
    return 0;
}


/*
 
 [문제]
 
 세로 두 줄 가로 N 줄
 첫째 줄에는 1~N
 둘째 줄에는 1이상 N이하 (중복허용)
 
 x 개의 col 을 뽑으면 위의 집합과 아래 집합이 일치
 x의 최대값을 구하는 문제
 
 [입력]
 
 N(1<=N<=100)
 표의 둘째 줄에 들어가는 정수들이 입력
 
 [출력]
 
 x 의 최대값, 집합을 출력
 
 
 
 */


