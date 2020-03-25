#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isEnd[101];

int solution(vector<int> priorities, int location){
    int answer = 1;
    int prev_index = 0;
    for (int i=0;i<priorities.size();i++){
        int max_value = 0;
        int max_index = 0;
        
        for (int j=prev_index;j<priorities.size()+prev_index;j++){
            int index = j % priorities.size();
            if (!isEnd[index] && max_value < priorities[index]){
                max_value = priorities[index];
                max_index = index;
            }
        }
        if (max_index == location) return answer;
        prev_index = (max_index + 1) % priorities.size();
        isEnd[max_index] = true;
        answer++;
    }
}

int main(){
    vector<int> priorities;
    priorities.push_back(3);
    priorities.push_back(3);
    priorities.push_back(4);
    priorities.push_back(2);
    
    int location = 3;
    cout << "answer: " << solution(priorities, location) << "\n";
    return 0;
}