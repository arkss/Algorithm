#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

struct pqCompare {
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs){
    priority_queue<vector<int>, vector<vector<int>>, pqCompare> pq; 
    sort(jobs.begin(), jobs.end(), compare);
    
    int answer = 0;
    int i=0;
    int nowTime = 0;
    while (i<jobs.size() || !pq.empty()){
        if (i < jobs.size() && jobs[i][0] <= nowTime){
            pq.push(jobs[i]);
            i++;
            continue;
        }

        if (!pq.empty()){
            vector<int> job = pq.top();
            nowTime += job[1];
            answer += nowTime - job[0];
            pq.pop();
        }
        else {
            nowTime = jobs[i][0];
        }
    }
    return answer / jobs.size();
}

int main(){
    cout << solution({{2,6},{1,9},{0,3}}) << "\n";
    return 0;
}