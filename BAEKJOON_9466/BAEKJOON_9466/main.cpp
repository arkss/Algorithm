#include <iostream>

using namespace std;

// 값을 받을 리스트
int list[100001];
int checkList[100001];
int circledList[100001];

int N;

int flag = 0;
int startIndex = 0;

int teamNum = 0;

void dfs(int i){
    // 맨 처음에 dfs 를 들어왔을 때만 첫번째 값을 저장
    if (flag){
        startIndex = i;
        flag = 0;
        
    }
    checkList[i] = 1;
    // 이번 사이클에 있는 index 표시
    circledList[i] = 1;
    int nextIndex = list[i];
    if (startIndex==nextIndex){
            for (int j=1;j<=N;j++){
                // 팀원의 수만큼 count
                if (circledList[j]) teamNum++;
            }
    }
    if (!checkList[nextIndex])
        dfs(nextIndex);
}

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        
        cin >> N;
        
        for (int i=1;i<=N;i++){
            cin >> list[i];
        }

        for (int i=1;i<=N;i++){
            
            // circledList 초기화
            for (int j=1;j<=N;j++){
                circledList[j] = 0;
            }
            flag = 1;
            dfs(i);
        }

        cout << N-teamNum << endl;
        
        // 기본값 초기화
        for (int i=1;i<=N;i++){
            checkList[i] = 0;
        }
        teamNum = 0;
    }
    return 0;
}




