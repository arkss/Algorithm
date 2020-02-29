#include <iostream>

using namespace std;

int lan[10000];

int main(int argc, const char * argv[]) {

    int K,N;
    cin >> K >> N;

    long long maxlan = 0LL;

    for (int i=0;i<K;i++){
        cin >> lan[i];
        if (lan[i] > maxlan)
            maxlan = lan[i];
    }


    long long left = 1LL;
    long long right = maxlan;

    int answer = 0;


    while (left<=right){
        long long mid=(right+left)/2;

        long long count = 0LL;

        for (int i=0;i<K;i++){
            count += lan[i] / mid;
        }

        if (count >= N){
            answer = mid;
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }

    cout << answer << "\n";

    return 0;
}


