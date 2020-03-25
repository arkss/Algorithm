#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices){
    vector<int> answer;

    int size = prices.size();
    for (int i=0;i<size;i++){
        int cnt = 0;
        for (int j=i+1;j<size;j++){
            if(prices[i] <= prices[j]){
                cnt++;
            } else{
                cnt++;
                break;
            }
        }
        answer.push_back(cnt);
    }
    for (int i=0;i<size;i++){
        cout << answer[i] << "\n";
    }
    return answer;
}

int main(){
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(3);
    solution(prices);
    return 0;
}