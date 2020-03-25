#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int x){
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int> > pq (scoville.begin(), scoville.end());

    while(1){
        //cout << pq.top() << "\n";
        if (pq.top() >= x) break;
        else  if (pq.size() == 1) return -1;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first+second*2);
        answer++;
    }
    return answer;
}

int main(){
    int k = 7;
    vector<int> scoville;
    scoville.push_back(1);
    scoville.push_back(2);
    scoville.push_back(3);
    scoville.push_back(9);
    scoville.push_back(10);
    scoville.push_back(12);
    cout << solution(scoville, k) << "\n";
}