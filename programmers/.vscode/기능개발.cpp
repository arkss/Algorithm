#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds){
    vector<int> days;
    vector<int> answer;
    int size = speeds.size();
    for (int i=0;i<size;i++){
        int day = (100 - progresses[i]) / speeds[i];
        days.push_back(day);
    }
 
    int cnt = 0;
    int prev_day;
    for (int i=0;i<size;i++){
        if (cnt == 0){
            prev_day = days[i];
            cnt++;
        }
        else if  (prev_day >= days[i]) cnt++;
        else {
            answer.push_back(cnt);
            prev_day = days[i];
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    return answer;
}

int main(){
    vector<int> progresses;
    vector<int> speeds;

    progresses.push_back(93);
    progresses.push_back(30);
    progresses.push_back(55);
    speeds.push_back(1);
    speeds.push_back(30);
    speeds.push_back(5);
    solution(progresses, speeds);
}