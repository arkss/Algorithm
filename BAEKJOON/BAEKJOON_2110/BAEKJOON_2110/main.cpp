#include <iostream>
#include <algorithm>

using namespace std;

int home[200000];

int main(){
    int N,C;
    cin >> N >> C;
    
    for (int i=0;i<N;i++){
        cin >> home[i];
    }
    
    sort(home, home+N);
    
    int answer = 0;
    
    long long left = 1;
    // 두 공유기 사이의 최대 거리는 맨 뒤와 맨 앞의 차이
    long long right= home[N-1]-home[0];
    
    while (left<=right){
        long long mid = (left+right)/2;
        
        int count=1;
        
        int start = home[0];
        
        for (int i=1;i<N;i++){
            int distance = home[i] - start;
            if (distance >= mid){
                count++;
                start = home[i];
            }
        }
        
        if (count>=C){
            left = mid+1;
            answer = mid;
        }
        else {
            right = mid-1;
        }
    }
    cout << answer << "\n";
}
