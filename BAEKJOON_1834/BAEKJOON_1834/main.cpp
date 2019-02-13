#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    long long N;
    long long i;
    long long sum = 0;
    
    cin >> N;
    
    for (i=1;i<N;i++){
        sum += i*N + i; // N으로 나누었을 때 몫과 나머지가 같으려면 다음과 같은 형태를 만족해야 한다.
    }
    
    cout << sum;
    
    
}
