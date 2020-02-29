//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//
//
//
//int main(int argc, const char * argv[]) {
//    int N; // 나무의 수
//    long long M; // 집에 가져가려고 하는 나무의 길이
//    int i; // 반복제어 변수
//    long long max = 0;
//    long long result = 0;
//
//    cin >> N >> M;
//
//    long long tree[N];
//    for (i=0;i<N;i++){
//        cin >> tree[i];
//        if (max < tree[i])
//            max = tree[i];
//    }
//    // 0을 시작지점으로 가장 긴 나무 길이를 끝지점으로 이분 탐색을 실시
//    long long left = 0;
//    long long right = max;
//
//    while(left <= right){
//        long long mid = (left+right) / 2;
//        long long return_tree = 0;
//        // 지정한 길이보다 큰 나무들에 한하여 짜른 길이를 return_tree 에 더해준다.
//        for(i=0;i<N;i++){
//            if (mid < tree[i])
//                return_tree += tree[i] - mid;
//        }
//        // 더해준 길이가 목표치 M 보다 작으면 right를 가운데로 이동
//        if (return_tree < M){
//            right = mid - 1;
//        }
//        // 더해준 길이가 목표치 M보다 크면 left를 가운데로 이동
//        else{
//            left = mid + 1;
//        }
//    }
//
//
//    cout << right;
//}


#include <iostream>

using namespace std;

int tree[1000000];

int main(){
    int N,M;
    cin >> N >> M;
    
    int maxTree = 0;
    
    for (int i=0;i<N;i++){
        cin >> tree[i];
        maxTree = max(maxTree, tree[i]);
    }
    
    long long left = 1;
    long long right = maxTree;
    
    
    int answer = 0;
    
    long long myTree = 0;
    
    while (left<=right){
        long long mid = (left+right)/2;
        
        myTree = 0;
        
        for (int i=0;i<N;i++){
            if (tree[i] > mid)
                myTree += tree[i]-mid;
        }
        
        if (M>myTree){
            right = mid-1;
        }
        else {
            left = mid+1;
            answer = mid;
            
        }
    }
    
    cout << answer << "\n";
    
}
