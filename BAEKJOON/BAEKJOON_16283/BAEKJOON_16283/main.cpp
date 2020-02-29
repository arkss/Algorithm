#include <iostream>

using namespace std;

int main(){
    int a,b,n,w;
    cin >> a >> b >> n >> w;
    
    int ans_cnt = 0;
    
    int aNum, bNum;
    
    for (int i=1;i<n;i++){
        if (a*i + b*(n-i) == w){
            ans_cnt++;
            aNum = i;
            bNum = n-i;
        }
        
    }
    
    if (ans_cnt == 1 )
        cout << aNum << " " << bNum << "\n";
    else
        cout << "-1" << "\n";
}

