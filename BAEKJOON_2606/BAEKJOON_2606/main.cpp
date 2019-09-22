#include <iostream>

using namespace std;

int parent[100];

int Find(int a){
    if (a==parent[a])
        return a;
    int b = Find(parent[a]);
    parent[a] = b;
    return b;
}

void Union(int a,int b){
    a = Find(a);
    b = Find(b);
    if (a!=b)
        parent[b] = a;
}

int main(int argc, const char * argv[]) {
    int N,M;
    
    cin >> N >> M;
    
    for (int i=1;i<=N;i++){
        parent[i] = i;
    }
    
    for (int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        Union(a,b);

    }
    
    int count = 0;
    
    for (int i=2;i<=N;i++){
        if (Find(1) == Find(i)) count++;
    }
    
    cout << count << "\n";
    
    return 0;
}
