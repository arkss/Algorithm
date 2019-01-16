#include <iostream> // 표준 입출력 사용 c에서 #include <stdio.h> 같은 역할
#include <queue> // 큐를 사용할 수 있도록
//
//push(element) : 큐에 원소 추가(뒤)
//pop() : 큐에 있는 원소를 삭제
//front() : 큐 제일 앞의 원소를 반환
//back() : 큐 제일 뒤의 원소를 반환
//empty() : 큐가 비어있으면 true 아니면 False
//size() : 큐 사이즈를 반환
//
using namespace std; // name space 개념은 메모장에, 아직 잘 모르겠다
int main() {
    int N,M; // 변수선언은 똑같음
    int i;
    int temp;
    int count = 0;
    queue<int> q;
    
    cin>> N >> M; // scanf("%d %d",&N,&M);
    for (i=1;i<=N;i++){
        q.push(i); // 큐에 값 넣기
    }
    cout << "<";
    while (1){
        for (i=0;i<M-1;i++){
            // 맨 앞에 있는 값을 꺼내서 맨 뒤로 보내기
            temp = q.front(); // pop 은 반환하는 값이 없어서 front를 사용해야 한다.
            q.pop();
            q.push(temp);
        }
        cout << q.front();
        q.pop();
        
        
        count++;
        
        if (count == N){
            break;
        }
        
        cout << ", ";
        
    }
    cout << ">";
    
    
    
}
