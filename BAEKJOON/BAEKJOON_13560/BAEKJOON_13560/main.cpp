
#include <iostream>

using namespace std;

int score[10000];

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    
    for (int i=0;i<n;i++){
        cin >> score[i];
    }
    
    sort(score, score+n);
    for (int i=0;i<n;i++){
        cout << score[i] << " " ;
    }

    
    int sum = 0;
    for (int i=0;i<n;i++){
        sum += score[i];
        int matchNumber = i*(i+1) / 2;
        if (sum < matchNumber){
            cout << -1;
            return 0;
        }
    }
    if (sum == n*(n-1) /2) cout << 1;
    else cout << -1;
    
    
    return 0;
}


/*
 
 n개 팀으로 이루어진 축구리그
 
 하나의 팀은 다른 모든 팀과 1번씩 경기 -> 한 팀당 n-1 번의 경기
 
 이기면 1점 지면 0점
 
 n (2 ≤ n ≤ 10,000)
 
 
 1.
 n개에 대해서 경기수는 (n-1)*(n) /2 번
 경기수와 주어진 경기수 비교
 
 2.
 
 
 */
