#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string input;
    cin >> input;
    
    vector <int> numV;
    // + : 1, - : -1
    vector <int> signV;
    int answer = 0;
    
    bool minus = false;
    signV.push_back(1);
    
    int num = 0;
    
    for (int i=0;i<input.size();i++){
        if (input[i] == '+' || input[i] == '-'){
            if (input[i] == '+') signV.push_back(1);
            else signV.push_back(-1);
            numV.push_back(num);
            num = 0;
        }
        else{
            num = num * 10 + input[i]-'0';
        }
    }
    numV.push_back(num);
    
    for (int i=0;i<numV.size();i++){
        if (signV[i] == -1) minus = true;
        if (minus) answer -= numV[i];
        else answer += numV[i];
    }
    
    cout << answer << "\n";
    
    return 0;
}
