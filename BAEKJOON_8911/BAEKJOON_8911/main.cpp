#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    
    int T;
    cin >> T;
    for (int t=0;t<T;t++){
        string input;
        cin >> input;
        
        // 0: 위, 1: 오른, 2: 아래, 3: 왼
        int dir=0;
        int rightMax = 0;
        int leftMax = 0;
        int upMax = 0;
        int downMax = 0;
        pair <int,int> pos = {0,0};
        

        for (int i=0;i<input.length();i++){
            char cmd = input[i];
            switch (cmd) {
                    
                case 'R':
                    dir++;
                    dir%=4;
                    break;
                case 'L':
                    dir--;
                    dir+=4;
                    dir%=4;
                    break;
                case 'F':
                    switch (dir){
                        case 0:
                            pos.second++;
                            break;
                        case 1:
                            pos.first++;
                            break;
                        case 2:
                            pos.second--;
                            break;
                        case 3:
                            pos.first--;
                            break;
                    }
                    break;
                case 'B':
                    switch (dir){
                        case 0:
                            pos.second--;
                            break;
                        case 1:
                            pos.first--;
                            break;
                        case 2:
                            pos.second++;
                            break;
                        case 3:
                            pos.first++;
                            break;
                    }
                    break;
            }
            if (pos.first > rightMax) rightMax = pos.first;
            if (pos.first < leftMax) leftMax = pos.first;
            if (pos.second > upMax) upMax = pos.second;
            if (pos.second < downMax) downMax = pos.second;

            
        }
        cout << (rightMax-leftMax) * (upMax - downMax) << endl;
    }
    
    

    
    return 0;
}


/*
 
 F : 앞으로 1
 B : 뒤로 1
 L : 왼쪽으로 90도
 R : 오른쪽으로 90도
 
 width 와 height 를 설정하고 Turtle 이 움직일 때의 가장 작은 값과 가장 큰 값을 뺴주자.
 
 
 
 */
