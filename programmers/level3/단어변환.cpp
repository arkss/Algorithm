#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool visited[51];
int answer;

void dfs(string s, string target, vector<string> words, int cnt){
    if (s == target) {
        answer = min(answer, cnt);
        return;
    }

    for (int i=0;i<words.size();i++){
        string word = words[i];
        int diffCnt = 0;
        for (int j=0;j<s.size();j++){
            if(s[j] != word[j]){
                diffCnt++;
                if (diffCnt >= 2) break;
            }
        }
        if (!visited[i] && diffCnt == 1) {
            visited[i] = 1;
            if (word == target) visited[i] = 0;
            dfs(word, target, words, cnt+1);
        }
    }
}

int solution(string begin, string target, vector<string> words){
    memset(visited, 0, sizeof(visited));
    answer = 987654321;
    dfs(begin, target, words, 0);
    if (answer == 987654321) answer = 0;
    return answer;
}

int main(){
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot","log", "cog"}) << "\n";
    return 0;
}