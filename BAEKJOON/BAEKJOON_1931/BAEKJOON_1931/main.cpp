#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair <int,int> a, pair <int,int> b){
    if (a.second < b.second) return true;
    else if (a.second == b.second) {
        if (a.first < b.first) return true;
        else return false;
    }
    else return false;
}

int main(int argc, const char * argv[]) {
    
    pair <int,int> con[100000];
    
    int N;
    cin >> N;
    
    for (int i=0;i<N;i++){
        cin >> con[i].first >> con[i].second;
    }
    
    sort(con, con+N,compare);
    
    int conCount = 1;
    int endTime = con[0].second;
    
    for (int i=1;i<N;i++){
        if (con[i].first >= endTime){
            conCount++;
            endTime = con[i].second;
        }
    }
    
    cout << conCount << "\n";
    return 0;
}
