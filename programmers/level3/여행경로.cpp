#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(string from, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& temp, vector<string>& answer, int cnt){
    
    temp.push_back(from);

    if (cnt == tickets.size()){
        answer = temp;
        return true;
    }

    for (int i=0;i<tickets.size();i++){
        if (!visited[i] && tickets[i][0] == from){
            visited[i] = true;
            bool success = dfs(tickets[i][1], tickets, visited, temp, answer, cnt+1);
            if (success) return true;
            visited[i] = false;
        }
    }
    temp.pop_back();
    return false;

}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, temp;
    vector<bool> visited(tickets.size(), false);

    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, visited, temp, answer, 0);
    return answer;
}