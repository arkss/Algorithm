#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    string input;
    cin >> input;
    
    vector <char> numList;
    
    int sum = 0;
    bool zeroCheck = false;
    
    for (int i=0;i<input.size();i++){
        if (input[i] == '0') zeroCheck = true;
        sum += input[i] - '0';
        numList.push_back(input[i]);
    }
    
    if (sum % 3== 0 && zeroCheck){
        sort(numList.begin(), numList.end());
        reverse(numList.begin(), numList.end());
        for (int i=0;i<numList.size();i++){
            cout << numList[i];
        }
    }
    else {
        cout << -1 << "\n";
    }
    
    return 0;
}
