#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a<b;
}

int solution(vector<int> budgets, int M){
    sort(budgets.begin(), budgets.end(), compare);

    int origin_budget = budgets[budgets.size()-1];
    
    while(M>=budgets.size()){
        for (int i=0;i<budgets.size();i++){
            if (budgets[i] > 0){
                budgets[i]--;
                M--;
            }
        }
    }
    int answer = origin_budget - budgets[budgets.size()-1];
    return answer+1;
}

int main(){
    cout << solution({120,110,140,150}, 485) << "\n";
    return 0;
}