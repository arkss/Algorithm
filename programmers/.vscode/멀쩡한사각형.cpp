#include <iostream>

using namespace std;

int gcd(long long w, long long h){
    if (h>w){
        long long temp = w;
        w = h;
        h = temp;
    }
    while (1){
        long long temp = w;
        w = h;
        h = temp % h;
        if (h==0) break;
    }
    return w;
}

long long solution(int w, int h){
    long long w_ll = (long long)w;
    long long h_ll = (long long)h;

    int value = gcd(w_ll, h_ll);

    cout << value << "\n";

    long long answer = (w_ll * h_ll) - value * ((w_ll/value) + (h_ll/value)-1);
    return answer;
}

int main(){
    cout << solution(8,12) << "\n";
}