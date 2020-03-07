#include <iostream>
#include <vector>

using namespace std;

string solution(string number, int k){
    int rst_len = number.size() - k;
    for (int i=0;i<k;i++){
        for (int j=0;j<number.size()-1;j++){
            if (number[j] < number[j+1]){
                // j번째 문자 삭제
                number.erase(j, 1);
                break;
            }
        }
    }
    
    /*
    4433 or 4444 
    다음과 같은 경우에는 위의 코드로 삭제가 발생하지 않음.
    뒤 쪽부터 삭제
    */
    while (rst_len != number.size()){
        number.erase(number.size()-1,1);
    }
    return number;
}

int main(){
    cout << solution("333333", 4) << "\n";
    return 0;
}