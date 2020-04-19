#include <iostream>
#include <vector>

using namespace std;

vector<int> answer;

void backtracking(int N, int M, int cnt){
    if (M == cnt){
        for (int i=0;i<answer.size();i++){
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i=1;i<=N;i++){
        if (!answer.empty()){
            if (answer[answer.size()-1] > i) continue;
        }
        answer.push_back(i);
        backtracking(N, M, cnt+1);
        answer.pop_back();
    }
}

int main(){
    int N, M;
    cin >> N >> M;

    backtracking(N, M, 0);
    return 0;
}