#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string integer[2];
    char oper;
    
    cin >> integer[0];
    cin >> oper;
    cin >> integer[1];
    
    
    int len1 = integer[0].size();
    int len2 = integer[1].size();
    string answer;
    if (oper == '*'){
        
        answer += "1";
        for (int i=0;i<len1+len2-2;i++){
            answer += "0";
        }
    }
    // 두 수가 같은 경우
    else if (oper == '+' && len1 == len2){
        answer += "2";
        for (int i=0;i<len1-1;i++){
            answer += "0";
        }
    }
    else{
        
        int length;
        string temp;
        if (len1 > len2){
            temp = integer[0];
            length = len2;
        }
        else{
            temp = integer[1];
            length = len1;
        }
        
        
        for (int i=0;i<temp.size();i++){
            if(temp.size()-length==i) {
                answer += "1";
            }
            else {
                answer += temp[i];
            }
        }
    }
    cout << answer << "\n";
    return 0;
}
