#include <iostream>
#include <vector>

using namespace std;
int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        int n;
        cin >> n;
        
        int S[101];
        int R[101];
        vector <int> check;
        for (int i=1;i<=n;i++){
            check.push_back(i);
        }

        for (int i=0;i<n;i++){
            cin >> R[i];
        }
        
        int flag = 0;
        for (int i=n-1;i>=0;i--){
            // 작은 수의 개수
            int ltNum = R[i];
            S[i] = check[ltNum];
            if (ltNum >= check.size()){
                cout << "IMPOSSIBLE" << endl;
                flag = 1;
                break;
            }
            //i번 인덱스의 원소 삭제
            check.erase(check.begin()+ltNum);
        }
 
        if (!flag){
            for (int i=0;i<n;i++){
                cout << S[i] << " " ;
            }
            cout << endl;
        }
    }
 
    return 0;
}
