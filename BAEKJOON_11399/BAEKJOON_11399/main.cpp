#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int time[1000];
    
    int N;
    cin >> N;
    
    for (int i=0;i<N;i++){
        cin >> time[i];
    }
    
    sort(time, time+N);
    
    int totalTime = 0;
    int tempTime = 0;
    
    for (int i=0;i<N;i++){
        tempTime += time[i];
        totalTime += tempTime;
    }
    
    cout << totalTime << "\n";
    
    return 0;
}
