#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int parent[101];

int Find(int x){
    if (x==parent[x]) return x;
    else {
        int y = Find(parent[x]);
        parent[x] = y;
        return y;
    }
}

void Union(int x,int y){
    y = Find(y);
    x = Find(x);
    if (x!=y){
        parent[y] = x;
    }
}

class Edge {
    public:
        int node[2];
        int distance;

        Edge(int a,int b,int distance){
            this->node[0] = a;
            this->node[1] = b;
            this->distance = distance;
        }

        bool operator<(const Edge &edge) const {
            return (this->distance) < (edge.distance);
        }
};

int solution(int n, vector<vector<int>> costs){
    
    vector <Edge> v;
    for (int i=0;i<costs.size();i++){
        v.push_back(Edge(costs[i][0], costs[i][1], costs[i][2]));
    }

    sort(v.begin(), v.end());
    for (int i=0;i<n;i++){
        parent[i] = i;
    }

    int answer = 0;
    for (int i=0;i<v.size();i++){
        if (Find(v[i].node[0]) != Find(v[i].node[1])){
;
            answer += v[i].distance;
            Union(v[i].node[0], v[i].node[1]);
        }
    }

    return answer;
}

int main(){
    cout << solution(4, {{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}}) << "\n";
    return 0;
}