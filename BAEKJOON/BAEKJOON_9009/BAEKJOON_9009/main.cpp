#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int fibo[45] = {0,1};
    for (int i=2;i<46;i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        int num;
        cin >> num;
        
        int maxFibo;
        vector <int> answerVector;
        while(1){
            for (int i=0;i<46;i++){
                if (num >= fibo[i]) maxFibo=fibo[i];
                else break;
            }
            num -= maxFibo;
            answerVector.push_back(maxFibo);
            if (!num) break;
            
        }
        for (int i=answerVector.size()-1;i>=0;i--){
            cout << answerVector[i] << " ";
        }
        cout << endl;
        
    }
    
    
    
    return 0;
}
