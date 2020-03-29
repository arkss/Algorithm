#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int max_size = 0;
    int size = 0;

    for (int i=0;i<truck_weights.size();i++){
        size = truck_weights[i];
        while(1){
            if(q.empty()){
                q.push(size);
                max_size += size;
                answer++;
                break;
            }
            else if (q.size() == bridge_length){
                max_size -= q.front();
                q.pop();
            }
            else {
                if (size + max_size > weight){
                    q.push(0);
                    answer++;
                } 
                else {
                    q.push(size);
                    max_size += size;
                    answer++;
                    break; 
                }
            }
        }
    }
    return answer + bridge_length;
}