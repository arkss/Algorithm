#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int numbers = budgets.size();

    sort(budgets.begin(),budgets.end());

    for (int i=0;i<budgets.size();i++){
        int budget = budgets[i];
        if (budget > M / numbers) return M/numbers;
        else {
            M -= budget;
            numbers--;
        }
    }

    return budgets.back();
}







int main(){
    cout << solution({120, 110, 140, 150}, 485) << "\n";
}