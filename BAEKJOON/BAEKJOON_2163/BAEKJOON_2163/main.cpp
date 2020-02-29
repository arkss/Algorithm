#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
    int M,N;
    int result;
    cin >> M >> N;
    result = N-1 + N * (M-1);
    cout << result;
    return 0;
}
