#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string input, char delimiter){
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while(getline(ss, temp, delimiter)){
        answer.push_back(temp);
    }

    return answer;
}

bool compare(int a, int b){
    return a>b;
}

void print_arr(vector<int> arr){
    for (int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

vector<int> solution(vector<string> operations){
    vector<int> v;
    for (int i=0;i<operations.size();i++){
        vector<string> operation = split(operations[i],' ');
        string command = operation[0];
        int value = stoi(operation[1]);
        if (command == "I"){
            v.push_back(value);
            sort(v.begin(), v.end(), compare);
        }
        else if (command == "D"){
            if (v.size() == 0) continue;
            else if (value == 1){
                v.erase(v.begin());
            } 
            else {
                v.pop_back();
            }
        }

        print_arr(v);
    }
    vector<int> answer;
    if (v.size() == 0) return {0,0};
    answer.push_back(v[0]);
    answer.push_back(v[v.size()-1]);
    return answer;
}

int main(){
    vector<int> result = solution({"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"});
    for (int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }
    return 0;
}