#include <iostream>

using namespace std;

int S = 0;

void add(int num){
    S = S | (1 << num);
}

void remove(int num){
    S = S & ~(1 << num);
}

void check(int num){
    if (S & (1<<num)) cout << 1 << "\n";
    else cout << 0 << "\n";
}

void toggle(int num){
    S = S ^ (1<< num);
}

void all(){
    S = (1<<20) -1;
}

void empty(){
    S = 0;
}

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int M;
    cin >> M;
    
    for (int i=0;i<M;i++){
        string oper;
        cin >> oper;
        
        int num;
        
        if (!(oper.compare("all")==0 || oper.compare("empty")==0)){
            cin >> num;
            num--;
        }
        
        if (oper.compare("add") == 0){
            add(num);
        }
        else if (oper.compare("remove") == 0){
            remove(num);
        }
        else if (oper.compare("check") == 0){
            check(num);
        }
        else if (oper.compare("toggle") == 0){
            toggle(num);
        }
        else if (oper.compare("all") == 0){
            all();
        }
        else if (oper.compare("empty") == 0){
            empty();
        }
    }
    return 0;
}
