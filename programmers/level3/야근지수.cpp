#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works){
    priority_queue <int> pq;
    for (int i=0;i<works.size();i++){
        pq.push(works[i]);
    }

    for (int i=0;i<n;i++){
        int temp = pq.top();
        if (!temp) break;
        pq.pop();
        pq.push(temp-1);
    }


    long long answer = 0;
    while(pq.size()){
        answer += pq.top() * pq.top();
        pq.pop();
    }
    return answer;
}

int main(){
    cout << solution(4, {4,3,3}) << "\n";
}