#include <iostream>

using namespace std;

int parent[1000000];

int Find(int a){
    if (parent[a] == a) return a;
    else {
        int b= Find(parent[a]);
        parent[a] = b;
        return b;
    }
}

void Union(int a,int b){
    b = Find(b);
    a = Find(a);
    if (a!=b)
        parent[b] = a;
}

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i=1;i<=n;i++){
        parent[i] = i;
    }

    for (int i=0;i<m;i++){
        int oper;
        int a,b;
        cin >> oper >> a >> b;
        if (oper == 0){
            Union(a,b);
        }
        else{
            if (Find(a) == Find(b)) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }

    return 0;
}

