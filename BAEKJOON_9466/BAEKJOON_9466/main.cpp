#include <iostream>

using namespace std;

// 값을 받을 리스트
int list[100001];
// 0: 방문 x, 1: 현재 순회중, 2: 방문 완료
int visited[100001];
// 사이클이 만들어진 애들을 체크해주자.
int circled[100001];


int flag = 0;
int startIndex = 0;

// 전체 사람의 수, team 을 이룬 사람의 수
// 두 값의 차이는 team 을 이루지 못한 사람의 수
int N;
int teamNum = 0;

void dfs(int i){
    if (flag){
        startIndex = i;
        flag = 0;
    }
    // 이미 사이클을 만든 노드는 순회할 필요가 없다.
    if (circled[i]) return;
    // 이미 끝난 상황이면 순회할 필요가 없다.
    if (visited[i] == -1) return;
    
    // 방문을 안했으면
    if (!visited[i]){
        // 현재 순회중
        visited[i] = startIndex;
    }
    // 현재 순회중
    else if (visited[i] == startIndex){
        circled[i] = 1;
        teamNum++;
    }
    int nextNode = list[i];
    dfs(nextNode);
    
    visited[i] = -1;
}



int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        
        cin >> N;
        teamNum = 0;
        
        for (int i=1;i<=N;i++){
            cin >> list[i];
        }
        
        for (int i=1;i<=N;i++){
            if (!visited[i]){
                flag = 1;
                dfs(i);
                }
                
            }
        
//        for (int i=1;i<=N;i++){
//            cout << circled[i] << " " ;
//        }
//        cout << endl;
        
        cout << N-teamNum << endl;
        
        // 기본값 초기화
        for (int i=1;i<=N;i++){
            list[i] = 0;
            visited[i] = 0;
            circled[i] = 0;
        }
        teamNum = 0;
        }
    return 0;
}

/*
 
 visited에 들어온 수를 넣어준다.
 
 순회하면서 visited 가 들어온 수와 같으면 cycle 이 형성된 것.
 
 dfs가 끝나는 순간에 visited에 -1 을 넣고 더 이상 순회하지 않도록 한다.
 이미 사이클이 만들어졌어도 순회하지 않도록 한다.
 
 
 */
