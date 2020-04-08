#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight){
    sort(weight.begin(), weight.end());
    int answer = 1;
    for (int i=0;i<weight.size();i++){
        if (answer >= weight[i])
            answer += weight[i];
    }
    return answer;
}

int main(){
    cout << solution({3,1,6,2,7,30,1}) << "\n";
}