////#include <iostream>
////
////using namespace std;
////
////int board[101][101];
////int soak[101][101];
////
////int main(int argc, const char * argv[]) {
////
////
////    return 0;
////}
//
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int parent[1000000];
//
//int Find(int x){
//    if (x==parent[x]) return x;
//    else {
//        int y = Find(parent[x]);
//        parent[x] = y;
//        return y;
//    }
//}
//
//void Union (int x, int y){
//    y = Find(y);
//    x = Find(x);
//    if (x!=y){
//        parent[y] = x;
//    }
//}
//
//
//class Edge {
//public:
//    int node[2];
//    int distance;
//
//    Edge(int a,int b,int distance){
//        this->node[0] = a;
//        this->node[1] = b;
//        this->distance = distance;
//    }
//
//    //연산자 오버로딩
//    bool operator<(const Edge &edge) const {
//        return (this->distance) < (edge.distance);
//    }
//
//
//};
//
//int main(){
//
//    // 노드 수와 엣지 수
//    int n=7;
//    int m =11;
//
//    vector <Edge> v;
//    v.push_back(Edge(1,7,12));
//    v.push_back(Edge(1,4,28));
//    v.push_back(Edge(1,2,67));
//    v.push_back(Edge(1,5,17));
//    v.push_back(Edge(2,4,24));
//    v.push_back(Edge(2,5,62));
//    v.push_back(Edge(3,5,20));
//    v.push_back(Edge(3,6,37));
//    v.push_back(Edge(4,7,13));
//    v.push_back(Edge(5,6,45));
//    v.push_back(Edge(5,7,73));
//
//    // 위의 연산자 오버로딩
//    sort(v.begin(), v.end());
//
//    for (int i=1;i<=n;i++){
//        parent[i] = i;
//    }
//
//    int sum = 0;
//    for (int i=0;i<v.size();i++){
//        if (Find(v[i].node[0]) != Find(v[i].node[1])){
//            sum += v[i].distance;
//            Union(v[i].node[0], v[i].node[1]);
//        }
//    }
//
//    cout << sum << "\n";
//}

