#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int distance(pair <int, int> p1, pair <int, int> p2){
    
    int dis = pow(p1.first - p2.first,2) +pow(p1.second - p2.second,2) ;
    return dis;
    
}

int main(int argc, const char * argv[]) {
    
    
        int N;
        cin >> N;
    
        map <int,int> m;
    
  
        for (int i=0;i<N;i++){
            int x,y;
            cin >> x >> y;
            m.insert(make_pair(x, y));
        }
        
    cout << m[0];
        
//        int size = 0;
//        for (int i=0;i<N;i++){
//            for (int j=0;j<N;j++){
//                if (i == j) continue;
//
//            }
//        }
//
//        cout << size << endl;
    
    
    return 0;
    
}
