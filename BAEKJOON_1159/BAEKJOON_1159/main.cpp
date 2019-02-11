#include <iostream>

using namespace std;
char player[151][31];

int alphabet[123];

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    int i;
    
    
    for (i=0;i<N;i++){
        // 각 이름을 받아서 player 2차원 배열에 넣어주고
        cin >> player[i];
        // alphabet 배열에 player이름 맨 앞글자를 index로 1 더해준다.
        alphabet[player[i][0]]++;
    }
    
    int count = 0;
    for(i='a';i<='z';i++){
        // 성이 5번 이상 나왔으면
        if (alphabet[i]>=5)
            // 문자로 바꿔서 출력하고
            cout << char(i);
        else {
            // 한 번도 출력이 없으면 저런 말을 출력
            count++;
            if (count == 26)
                cout << "PREDAJA";
        }
        
        
    }
    
}
