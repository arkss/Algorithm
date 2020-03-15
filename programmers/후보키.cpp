#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 비트로 표현했을 때 1이 몇 개 존재하는지 count
int countBits(int n){
    int ret = 0;
    while(n){
        if (n&1) ret++;
        n = n >> 1;
    }

    return ret;
}

bool comp(int a, int b){
    int x = countBits(a), y = countBits(b);
    return x>y;
}

bool check(vector<vector<string> > relation, int rowsize, int colsize, int subset){
    for (int a=0;a<rowsize-1;a++){
        for (int b=a+1;b<rowsize;b++){
            bool isSame = true;
            for (int k=0;k<colsize;k++){
                if ((subset & 1 << k) == 0) continue;
                if (relation[a][k] != relation[b][k]) {
                    isSame = false;
                    break;
                }
            }
            // 하나라도 같은 값이 있으면 isSame이 true로 남아있고 후보키로 지정할 수 없으므로 false를 return 한다.
            if (isSame) return false;
        }
    }
    return true;
}

int solution(vector<vector<string> > relation) {
    int answer = 0;
    int rowsize = relation.size();
    int colsize = relation.front().size();
    vector <int> candidates;

    for (int i=1;i< 1<< colsize;i++){
        if (check(relation, rowsize, colsize, i)){
            candidates.push_back(i);
        }
    }

    sort(candidates.begin(), candidates.end(),comp);

    // 가장 작은 1 비트로 이루어진 값을 하나 뽑은 다음에 이를 포함하는 다른 키들, 즉 최소성을 만족하지 않는 키들을 삭제해준다.
    while(!candidates.empty()){
        // 가장 작은 1 비트로 이루어진 값
        int n = candidates.back();
        candidates.pop_back();
        answer++;
        for (vector<int>::iterator it = candidates.begin();it!=candidates.end();){
            // it의 모든 1비트는 n에 이미 포함되어있음
            if ((n&*it) == n)
                it = candidates.erase(it);
            else 
                it++;
        }
    }
    return answer;
}

void print(vector<vector<string> > relation, int answer) {
    int t = solution(relation);
    if (answer == t)
        cout << "정답" << endl;
    else
        cout << "틀림" << endl;
}
 
int main() {
    print({ {"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"},
        {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"},
        {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"} }, 2);
    return 0;
}

