#include <iostream>
#include <vector>

using namespace std;

bool check[26];

void clear_check(int skill_size){
    for (int i=0;i<skill_size;i++) check[i] = 0;
}

void print_check(int skill_size){
    for (int i=0;i<skill_size;i++){
        cout << check[i] << " ";
    } 
    cout << "\n";
}
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i=0;i<skill_trees.size();i++){
        string user = skill_trees[i]; // AECB
        bool failFlag = 0;
        for (int j=0;j<user.size();j++){
            char now = user[j]; // A, E, C, B
            bool checkFlag = 0;
            for (int k=0;k<skill.size();k++){
                if (skill[k] == now){
                    check[k] = 1;
                    if (k > 0 && !check[k-1]){
                        failFlag = 1;
                        break;
                    }
                    checkFlag = 1;
                } 
            }
        }
        if (!failFlag) {
            answer++;
        }

        clear_check(skill.size());
    }
    
    return answer;
}

int main(){
    cout << solution("CBD", {"BACDE", "CBADF", "AECB", "BDA"}) << "\n";
}