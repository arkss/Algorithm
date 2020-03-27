#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());

    cout << citations[citations.size()-1] << "\n";
    int answer = 0;
    
    for (int h_index=0; h_index<=citations[citations.size()-1]; h_index++){
        int cnt = 0;
        for (int i=0;i<citations.size();i++){
            if (citations[i] >= h_index) cnt++;
        }

        if (h_index <= cnt) answer = h_index;
    }

    
    return answer;
}

int main(){
    cout << solution({3,0,6,1,5}) << "\n";

}

