#include <iostream>
#include <vector>

using namespace std;

long long factorial(int n){
    long long answer = 1;
    for (int i=1;i<=n;i++){
        answer*=i;
    }
    return answer;
}

vector<int> solution(int n, long long k){
    vector<int> answer;
    vector<int> lines;
    for (int i=1;i<=n;i++){
        lines.push_back(i);
    }
    long long fac = factorial(n);
    k--;
    while (n>0){
        fac = fac / n;
        cout << lines[k/fac] << "\n";
        answer.push_back(lines[k/fac]);
        lines.erase(lines.begin()+k/fac);
        k %= fac;
        n--;
    }
    return answer;
}

int main(){
    int n = 3;
    long long k = 5;
    vector<int> result = solution(3,5);
    for (int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }
    return 0;
}