
#include <iostream>

using namespace std;



int flag;

void bfs(string str){
    // 문자열을 모두 제거했으면 flag 를 1로 설정해서 재귀적으로 타고 들어왔던 다른 함수들도 모두 1롤 return 시킨다.
    if (flag) return;
    if (!str.length()){
        flag = 1;
        return;
    }
    
    for (int i=0;i<str.length();i++){
        int index=i;
        while(index< str.length()){
            if (str[i] == str[index]) index++;
            else break;
        }
        if (index >= i+2)
            bfs(str.substr(0,i) + str.substr(index,str.length()));
            
        }
    }

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        string str;
        cin >> str;
        
        flag = 0;
        
        bfs(str);
        cout << flag << "\n";
    }
    return 0;
}


