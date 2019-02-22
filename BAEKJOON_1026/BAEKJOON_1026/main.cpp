#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int a[50];
int b[50];

int com(int a, int b)
{
    return a>b;
}

int main(int argc, const char * argv[]) {
    int N;
    int i;
    
    cin >> N;
    
    for(i=0;i<N;i++){
        cin >> a[i];
    }
    
    for(i=0;i<N;i++){
        cin >> b[i];
    }
   
    
    sort(a,a+N);
    sort(b,b+N, com);
//    sort(b,b+N, greater<int>());

    
    int result =0;
    for(i=0;i<N;i++){
        result += a[i] * b[i];
    }

    cout << result;
    
    
}
