#include <iostream>

using namespace std;

int min3(int a, int b, int c){
    return min(min(a,b),c);
}


int main(){
    int N,M,K;
    cin >> N >> M >> K;
    
    cout << min3((N+M-K)/3, N/2, M) << "\n";
    
}

//int main(int argc, const char * argv[]) {
//    int N,M,K;
//    cin >> N >> M >> K;
//    // 2명의 여학생과 1명의 남학생이 팀
//
//    for (int i=0;i<K;i++){
//        if (N/2 >= M){
//            N--;
//        }
//        else M--;
//    }
//
//    int teamNum;
//    teamNum = min(N/2, M);
//    cout << teamNum << "\n";
//    return 0;
//}
