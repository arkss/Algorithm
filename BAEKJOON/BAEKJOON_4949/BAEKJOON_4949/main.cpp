//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//
//
//int main(int argc, const char * argv[]) {
//
//    int flag = 0;
//
//    while (1){
//        stack <char> st;
//        string s;
//        getline(cin, s);
//        if (s == "."){
//            return 0;
//        }
//        int printFlag = 0;
//        for (int i=0;i<s.size();i++){
//
//            if (s[i] == '(' || s[i] == '['){
//                st.push(s[i]);
//            }
//
//            else if (s[i] == ')'){
//                if (st.empty() || st.top() != '('){
//                    //cout << s[i] << "\n";
//                    cout << "no\n";
//                    printFlag = 1;
//                    break;
//                }
//                st.pop();
//            }
//            else if (s[i] == ']'){
//                if ( st.empty() || st.top() != '['){
//                    //cout << s[i] << "\n";
//                    cout << "no\n";
//                    printFlag = 1;
//                    break;
//                }
//                st.pop();
//            }
//        }
//        if (!printFlag && !st.empty()) {
//            cout << "no\n";
//            printFlag = 1;
//        }
//
//        if (!printFlag){
//             cout << "yes\n";
//        }
//
//    }
//
//    return 0;
//}





#include <iostream>
#include <stack>

using namespace std;

int main(){
    while (1){
        stack <char> st;
        string s;
        getline(cin, s);
        
        if (s=="."){
            break;
        }
        int flag = 0;
        for (int i=0;i<s.size();i++){
            char c = s[i];
            if (c == '(' || c=='['){
                st.push(c);
            }
            else if (c == ')'){
                if (st.empty() || st.top()!='('){
                    flag = 1;
                    break;
                }
                st.pop();
            }
            else if (c == ']'){
                if (st.empty() || st.top()!='['){
                    flag = 1;
                    break;
                }
                st.pop();
            }
        }
        
        if (flag || !st.empty()) cout << "no\n";
        else cout << "yes\n";
        
    }
    
    return 0;
    
}
