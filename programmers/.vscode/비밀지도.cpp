#include <iostream>
#include <string>
#include <vector>

using namespace std;

string decimalToBinary(int n){
    string answer = "";
    while (1){

        if (n == 0) break;
    }
    return answer;
}

vector <string> solution(int n, vector<int> arr1, vector<int> arr2){
    vector<string> answer;
    for (int i=0;i<n;i++){
        int result = arr1[i] | arr2[i];
        string temp = "";
        for (int j=0;j<n;j++){
            if (result % 2 == 0) temp=" "+temp;
            else temp="#"+temp;
            result /= 2;
        }
        answer.push_back(temp);
    }
    return answer;
}

int main(){
    int n = 5;
    vector<int> arr1;
    vector<int> arr2;
    arr1.push_back(9);
    arr1.push_back(20);
    arr1.push_back(28);
    arr1.push_back(18);
    arr1.push_back(11);

    arr2.push_back(30);
    arr2.push_back(1);
    arr2.push_back(21);
    arr2.push_back(17);
    arr2.push_back(28);
    vector<string> result;
    result = solution(n, arr1, arr2);
    for (int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }
}