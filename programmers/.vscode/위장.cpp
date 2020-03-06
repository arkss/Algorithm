#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string> > clothes){
    vector<pair<string, int> > clothes_cnt;
    for (int i=0;i<clothes.size();i++){
        string kind = clothes[i][1];
        int j = 0;
        for (j=0;j<clothes_cnt.size();j++){
            if (clothes_cnt[j].first == kind){
                clothes_cnt[j].second++;
                break;
            }
        }
        if (j == clothes_cnt.size()) {
            clothes_cnt.push_back(make_pair(kind, 1));
        }
    }
    int answer = 1;
    for (int j=0;j<clothes_cnt.size();j++){
        answer *= clothes_cnt[j].second+1;
    }
    return --answer;
}
