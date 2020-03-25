#include <iostream>

using namespace std;

string decimal_to_n(int n, int num){
    string answer = "";
    while (1){
        int temp = num % n;
        num = num / n;

        switch(temp){
            case 10:
                answer = 'A' + answer;
                break;
            case 11:
                answer = 'B' + answer;
                break;
            case 12:
                answer = 'C' + answer;
                break;
            case 13:
                answer = 'D' + answer;
                break;
            case 14:
                answer = 'E' + answer;
                break;            
            case 15:
                answer = 'F' + answer;
                break;
            default:
                answer = (char)(temp+'0') + answer; 
        }
        if (num == 0) break;
    }
    return answer;
}

string solution(int n, int t, int m, int p){
    // 진법 n, 미리 구할 숫자의 갯수 t, 게임에 참가하는 인원 m, 튜브의 순서 p 

    string result = "";

    for (int i=0;i<t*m;i++){
        result += decimal_to_n(n,i);
    }   

    string answer = "";

    for (int i=0;i<result.size();i++){
        if ((i+1) % m == p % m) answer += result[i];
        if (answer.size() == t) break;
    }

    return answer;

}

int main(){
    cout << solution(16,16,2,1) << "\n";
    return 0;
}

