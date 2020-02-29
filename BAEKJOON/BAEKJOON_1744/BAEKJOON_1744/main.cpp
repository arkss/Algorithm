#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(int a, int b){
    if (a>b) return true;
    else return false;
}

int main(int argc, const char * argv[]) {
    
    vector <int> plus;
    vector <int> minus;
    
    int N;
    cin >> N;
    
    int answer = 0;
    int zeroNum = 0;
    int oneNum = 0;
    
    for (int i=0;i<N;i++){
        int input;
        cin >> input;
        if (input == 1) oneNum++;
        else if (input == 0) zeroNum++;
        else if (input > 0) plus.push_back(input);
        else minus.push_back(input);
    }
    
    sort(plus.begin(), plus.end(), compare);
    sort(minus.begin(), minus.end());
    
    answer += oneNum;
    
    plus.push_back(1);
    minus.push_back(1);
    
    for (int i=0;i<plus.size()-1;i+=2){
        answer += plus[i] * plus[i+1];
    }
    for (int i=0;i<minus.size()-1;i+=2){
        answer += minus[i] * minus[i+1];
    }
    // minus가 홀수 개 이고 0이 있을 때 하나를 0이랑 곱해 상쇄시키기
    if (minus.size()%2==0 && zeroNum >= 1){
        answer -= minus[minus.size()-2];
    }
    
    cout << answer << "\n";

    return 0;
}
