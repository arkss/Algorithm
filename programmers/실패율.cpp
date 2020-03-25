#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double result[3][502];
/*
result[0][i] : 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수
result[1][i] : 스테이지에 도달한 플레이어 수
result[2][i] : 실패율
*/

int compare(pair<int, double> a, pair<int, double> b){
    if (a.second == b.second) 
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    sort(stages.begin(), stages.end());
    for (int i=0;i<stages.size();i++){
        int stages_num = stages[i];
        result[0][stages_num]++;
        for(int j=1;j<=stages_num;j++){
            result[1][j]++;
        }
    }

    vector<pair<int, double> > temp;

    for (int j=1;j<=N;j++){
        if (result[1][j] == 0) result[2][j] = 0;
        else result[2][j] = result[0][j] / result[1][j];
        temp.push_back(make_pair(j,result[2][j]));
    }

    sort(temp.begin(), temp.end(), compare);

    vector<int> answer;

    for (int i=0;i<temp.size();i++){
        answer.push_back(temp[i].first);
    }
    return answer;
}

int main(){
 int N = 5;
 vector<int> stages;
 stages.push_back(2);
 stages.push_back(1);
 stages.push_back(2);
 stages.push_back(6);
 stages.push_back(2);
 stages.push_back(4);
 stages.push_back(3);
 stages.push_back(3);

 solution(5, stages);
}


/*
[ 실패율 ]
스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수

전체 스테이지의 개수 N, 게임을 이용하는 사용자가 현재 멈춰있는 스테이지의 번호가 담긴 배열 stages가 매개변수로 주어질 때, 실패율이 높은 스테이지부터 내림차순으로 스테이지의 번호가 담겨있는 배열을 return 하도록 solution 함수를 완성하라.

5	[2, 1, 2, 6, 2, 4, 3, 3]	[3,4,2,1,5]
*/
