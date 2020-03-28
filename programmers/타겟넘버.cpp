#include <iostream>
#include <vector>

using namespace std;

int answer;

void DFS(int value,vector<int> numbers, int depth,int target){
    if (depth == numbers.size()){
        if (value == target) answer++;
        return;
    }

    DFS(value+numbers[depth], numbers, depth+1, target);
    DFS(value-numbers[depth], numbers, depth+1, target);
}

int solution(vector<int> numbers, int target){
    answer = 0;

    DFS(0,numbers,0,target);
    return answer;
}

int main(){
    cout << solution({1,1,1,1,1}, 3) << "\n";
}