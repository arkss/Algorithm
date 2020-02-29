#include <iostream>

using namespace std;

// 값을 받을 리스트
int list[1000];
int checkList[1000];

void dfs(int i){
    checkList[i] = 1;
    int nextIndex = list[i];
    if (!checkList[nextIndex])
        dfs(nextIndex);
}

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        int N;
        cin >> N;
        
        for (int i=1;i<=N;i++){
            cin >> list[i];
        }
        
        int cycleNum = 0;
        
        
        for (int i=1;i<=N;i++){
            if (!checkList[i])
            {
                dfs(i);
                // 무조건 한 개는 증가한다.
                cycleNum++;
            }
        }
        
        cout << cycleNum << endl;
        for (int i=1;i<=N;i++){
            checkList[i] = 0;
        }
    }
    
    
 
    return 0;
}

/*
1 2 3 4 5 6 7 8
 
3 2 7 8 1 4 5 6
 
 
 */


