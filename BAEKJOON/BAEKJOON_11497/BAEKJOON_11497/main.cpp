#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a>b;
}

int max(int a, int b){
    return a>b?a:b;
}

int max(int a,int b,int c){
    return max(max(a,b),c);
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for (int i=0;i<T;i++){
        
        int n;
        cin >> n;
        int log[n];
        for (int j=0;j<n;j++){
            cin >> log[j];
        }
        sort(log, log+n);
        sort(log, log+n , compare);
        // 홀수 개 일때
//        [9 7 5 4 2]
//        [2 5 9 7 4]
        // 짝수 개 일 때
//        [9 7 5 4 2 1]
//        [2 5 9 7 4]

        // 가장 큰 통나무와 좌 우 값 비교
        int maxDistance = max(log[0]-log[1],log[0]-log[2] );
        
        // 홀수 개 일 때
        for(int j=1;j<n-2;j++){
            maxDistance = max(maxDistance,log[j]-log[j+2] );
        }
        // 맨 앞에 놓은 통나무와 맨 뒤에 놓은 통나무 값 비교
        maxDistance = max(maxDistance, log[n-2]-log[n-1]);
        
        cout << maxDistance << endl;
//        for (int j=0;j<n;j++){
//            cout << log[j] << " ";
//        }
    
    }
}

/*

 인접한 통나무
 
 인접한 통나무의 높이 차가 최소가 되게 하자 (처음과 마지막도 연결되어잇는것이다.)
 
 N  (5 ≤ N ≤ 10,000)
 Li (1 ≤ Li ≤ 100,000)
 
 
 */
