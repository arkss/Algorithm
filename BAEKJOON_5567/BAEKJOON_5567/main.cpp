#include <iostream>
#include <vector>

using namespace std;

vector<int> friends[501];
int list[501];

void bfs(int node){
    for (int i=0;i<friends[node].size();i++){
        int nextNode = friends[node][i];
        list[nextNode] = 1;
        
        if (node == 1) bfs(nextNode);
    }
}


int main(int argc, const char * argv[]) {
    
    int friendNum;
    cin >> friendNum;
    
    
    
    int N;
    cin >> N;
    
    for (int i=0;i<N;i++){
        int f1, f2;
        cin >> f1 >> f2;
        
        friends[f1].push_back(f2);
        friends[f2].push_back(f1);
    }
    
    bfs(1);
    
    int friendsCount = 0;
    for (int i=2;i<=friendNum;i++){
        if (list[i]) friendsCount++;
    }
    
    cout << friendsCount << "\n";
    

    return 0;
}
