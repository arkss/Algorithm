#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


string int_to_string(int n){
    string result = "";
    while (1){
        int remainder = n % 10;
        result = (char)(remainder+'0') + result;
        n = n / 10;
        if (n==0) break;
    }
    return result;
}

bool compare(string a, string b){
    int a_size = a.size();
    int b_size = b.size();
    int min_size;
    string longger = "";
    if (a_size < b_size){
        min_size = a_size;
        longger = b;
    } else {
        min_size = b_size;
        longger = a;
    }
    for (int i=0;i<min_size;i++){
        if (a[i] > b[i]) return true;
        else if (a[i] < b[i]) return false;
    }
    // 완전히 같은 경우
    if (a_size == b_size) {
        cout << "완전히 같은 경우" << "\n";
        return true;
    }
    
    if (longger[0] > longger[min_size]) return false;
    else return true;
}

string solution(vector<int> numbers) {
    string answer = "";
    int size = numbers.size();
    vector<string> numbers_str;
    for (int i=0;i<size;i++){
        numbers_str.push_back(int_to_string(numbers[i]));
    }
    sort(numbers_str.begin(),numbers_str.end(), compare);
    for (int i=0;i<size;i++){
        answer += numbers_str[i];
    }

    int zero_cnt = 0;
    for (int i=0;i<size;i++){
        if (answer[i] == '0') zero_cnt++;
    }
    if (zero_cnt == size) return "0";
    return answer;
}


int main(){
    int list[2] = {40,403};
    std::vector<int> numbers(list, list+2); 
    cout << solution(numbers) << "\n";
}