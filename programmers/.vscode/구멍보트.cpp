#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int compare(int a, int b){
    return a>b;
}

int solution(vector<int> people, int limit){
    sort(people.begin(), people.end(), compare);
    int answer = 0;
    int size = people.size();
    int j = size-1;
    for (int i=0;i<j;i++){
        int first = people[i];
        int second_limit = limit - first;

        int second = people[j];
        if (second_limit >= second){
            j--;
            answer++;
        } else {
            answer++;
        } 
    }
    return answer;
}

int main(){
    vector<int> people;
    int limit = 100;
    people.push_back(40);
    people.push_back(40);
    people.push_back(60);
    people.push_back(60);
    cout << solution(people, limit) << "\n";
}