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

bool compare(const string &a, const string &b) {
	return a + b > b + a ? true : false;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> strArr;
	for (int i = 0; i < numbers.size(); i++) {
		strArr.push_back(int_to_string(numbers.at(i)));
	}
	sort(strArr.begin(),strArr.end(),cmp);
	for (string str : strArr) {
		answer += str;
	}
	if (answer[0] == '0')
		return "0";
	return answer;
}


int main(){
    int list[2] = {40,403};
    std::vector<int> numbers(list, list+2); 
    cout << solution(numbers) << "\n";
}