#include <iostream>
#include <vector>

using namespace std;

vector <int> s;
int list[13];


int k;

void dfs(int start){
    
    if (s.size() == 6){
        for (int i=0;i<6;i++){
            cout << s[i] << " ";
        }
        cout << "\n";
        return;
    }
    else {
        for (int i=start;i<k;i++){
            s.push_back(list[i]);
            dfs(i+1);
            s.pop_back();
        }
    }

}

int main(int argc, const char * argv[]) {
    
    while (1){
        
        cin >> k;
        if (!k) break;
        
        
        for (int i=0;i<k;i++){
            cin >> list[i];
        }
        dfs(0);
        cout << "\n";
    }
    
    
    return 0;
}


/*
 
 1~49 에서 6개의 수
 
 49개 수 중 k 개의 수를 골라 집합 S를 만든 다음에 그 수만 가지고 번호를 선택
 
 [ 입력 ]
 
 첫번째 수는 (6<k<13)
 마지막으로 0
 
 [ 출력 ]
 
 주어진 수들을 조합헤서 6개 숫자 뽑기 사전순으로 출력
 
 
 */
