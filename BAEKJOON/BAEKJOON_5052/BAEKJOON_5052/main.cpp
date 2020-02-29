#include <iostream>
#include <cstdio>

using namespace std;

struct Phone {
    char tel[10];
};

struct Trie {
    bool finish;
    Trie *next[10];

    Trie() :finish(false){
        for (int i=0;i<10;i++)
            next[i] = 0;
    }
    ~Trie(){
        for (int i=0;i<10;i++)
            if (next[i]) delete next[i];
    }

    void insert(char *key){
        if (*key == '\0') finish = true;
        else {
            int cur = *key - '0';
            if (next[cur] == NULL){
                next[cur] = new Trie();
            }
            next[cur]->insert(key+1);
        }
    }

    bool find(char *key){
        if (*key == '\0') return false;
        if (finish) return true;
        int cur = *key - '0';
        return next[cur]->find(key+1);
    }
};

int main(int argc, const char * argv[]) {

    int T;
    cin >> T;
    for (int t=0;t<T;t++){
        int n;
        cin >> n;

        Phone data[10001] = {0,};

        for (int i=0;i<n;i++){
            cin >> data[i].tel;
        }

        int flag = 0;
        Trie *root = new Trie();
        for (int i=0;i<n;i++)
            root->insert(data[i].tel);

        for (int i=0;i<n;i++){
            if (root->find(data[i].tel)){
                flag = 1;
                break;
            }
        }

        if (flag) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }


    return 0;
}
