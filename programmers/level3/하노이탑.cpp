#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void hanoi(int start, int mid, int end, int n){
    if (n==1) {
        answer.push_back({start, end});
        return;
    }
    hanoi(start, end, mid, n-1);
    hanoi(start, mid, end, 1);
    hanoi(mid, start, end, n-1);
}

vector<vector<int>> solution(int n){

    hanoi(1,2,3,n);

    for (int i=0;i<answer.size();i++){
        cout << answer[i][0] << " " << answer[i][1]  << "\n";
    }
    return answer;
}

int main(){
    solution(2);
}