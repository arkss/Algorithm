#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string a, b;
    cin >> a;
    cin >> b;
    
    int aLen = a.size();
    int bLen = b.size();
    
    int aIndex = 0, bIndex = 0;
    
    bool flag = false;
    for (int i=0;i<aLen;i++){
        for (int j=0;j<bLen;j++){
            if (a[i] == b[j]){
                aIndex = i;
                bIndex = j;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    
    for (int j=0;j<bLen;j++){
        for (int i=0;i<aLen;i++){
            if (j == bIndex)
                cout << a[i];
            else if (i == aIndex)
                cout << b[j];
            else
                cout << "." ;
        }
        cout << "\n";
    }
    
    return 0;
}
