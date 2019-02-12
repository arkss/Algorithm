#include <iostream>
#include <queue>

using namespace std;

int arr1[1002][1002]; // 그래프를 2차원 배열로 표현
int arr2[1002][1002]; // 그래프를 2차원 배열로 표현
int visited1[1002];
int visited2[1002];

void DFS(int now, int N)
{
    int i;
    // 시작노드 방문으로 처리 후 출력
    visited1[now] = 1;
    cout << now << " ";
    
    for (i=1;i<=N;i++){
        if (arr1[now][i] == 1 && visited1[i] == 0){
            DFS(i,N);
        }
    }
}

void BFS(int now, int N)
{
    queue<int>q;
    int i;
    
    // 방문한 노드로 표시
    visited2[now] = 1;
    cout << now << " ";
    q.push(now);
    
    while(1){
        // 맨 앞의 원소를 현재 위치로 하고 큐에서 제거
        now = q.front();
        q.pop();
        for(i=1;i<=N;i++){
            // 간선이 있고 정점에 방문을 안했으면
            if (arr2[now][i] == 1 && visited2[i] ==0){
                visited2[i] = 1;
                cout << i << " ";
                // 간선으로 넘어간 곳의 정점을 queue에 삽입
                q.push(i);
            }
        }
        // 큐가 비었으면 종료한다.
        if (q.empty())
            break;
    }
}



int main(int argc, const char * argv[]) {
    int N, M, start, now; // 정점의 개수, 간선의 개수, 시작 정점, 현재 정점
    cin >> N >> M >> start;
    
    int i;
    int vertex1 ,vertex2;
    
    for(i=0;i<M;i++){
        cin >> vertex1 >> vertex2;
        arr1[vertex1][vertex2] = 1; // 간선을 연결
        arr1[vertex2][vertex1] = 1; // 대칭 부분도 연결
        arr2[vertex1][vertex2] = 1;
        arr2[vertex2][vertex1] = 1;
    }
    
    now = start;

    
    // 현재 시작하는 노드와 정점의 개수
    DFS(now,N);
    cout << endl;
    BFS(now,N);
}

