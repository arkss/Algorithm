#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<int> answer;

void backtracking(int N, int M, int cnt){
    if (M == cnt){
        for (int i=0;i<M;i++){
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i=0;i<arr.size();i++){
        answer.push_back(arr[i]);
        backtracking(N, M, cnt+1);
        answer.pop_back();
    }
}

int main(){
    int N,M;
    cin >> N >> M;

    for (int i=0;i<N;i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    backtracking(N, M, 0);
    return 0;
}