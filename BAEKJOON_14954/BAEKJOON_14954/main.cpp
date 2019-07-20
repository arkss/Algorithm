#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int list[1000000] = {0,};
    
    int num;
    cin >> num;
    //  to_string 구글링
    string str = to_string(num);
    
    int len = str.length();
    int index = 0;
    int flag = 0;
    while (1){
        int result = 0;
        for (int i=0;i<len;i++){
            int temp = int(str[i] - '0');
            result += temp * temp;
        }
        if (result == 1){
            cout << "HAPPY" << endl;
            break;
        }
        
        for (int j=0;j<index;j++){
            if (result == list[j]){
                flag = 1;
                break;
            }
        }
        
        if (flag){
            cout << "UNHAPPY" << endl;
            break;
        }
        list[index] = result;
        index++;
        str = to_string(result);
        len = str.length();
    }
    
    
    return 0;
}


/*
 5 -> 25 -> 29 -> 85 -> 64+25=89 -> 64+81=145 -> 1+16+25=42 -> 20 -> 4
 
 계산하다가 1이 나오면 happy
 
 
 이미 나왔던 수가 다시 나올 경우에 unhappy 를 판별할 수 있다.
 어떻게 이미 나왔던 수인지 확인을 해줄 수 있을까?
 list 에 하나씩 저장하면서 매 연산마다 앞에 값들을 다 확인해준다.
 
 최대값을 생각해보자. 큰 수로 시작해도 한 단게만 거쳐도 값이 많이 작아지네.
 999,999,999 -> 81*9 = 729
 
 
 */
