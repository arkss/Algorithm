#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        // 로봇 수
        int num;
        cin >> num;
        
        // 1이면 살아있음, 0이면 죽음
        int survival[10];
        for (int i=0;i<num;i++){
            survival[i] = 1;
        }
        // 로봇의 가위바위보 문자열
        string rsp[10];
        for (int i=0;i<num;i++){
            cin >> rsp[i];
        }
        
        // 문자열 길이만큼 가위바위보를 반복
        for (int j=0;j<rsp[0].size();j++){
            // 0: 가위, 1: 바위, 2: 보
            int rspCount[3] = {0,};
            
//            cout << "survival" << "\n";
//            for (int i=0;i<num;i++){
//                cout << survival[i] << " ";
//            }
//            cout << "\n" ;
            // 로봇 수 만큼 반복
            for (int i=0;i<num;i++){
                // 살아있는 로봇이 낸 거 체크
                if (survival[i]){
                    if (rsp[i][j] == 'S') rspCount[0]++;
                    if (rsp[i][j] == 'R') rspCount[1]++;
                    if (rsp[i][j] == 'P') rspCount[2]++;
                }
            }
            
//            cout << "rspCount" << "\n";
//            for (int a=0;a<3;a++){
//                cout<< rspCount[a] << " ";
//            }
//            cout << "\n";
            
            int survivalCount = 0;
            for (int i=0;i<num;i++){
                if (survival[i])
                    survivalCount++;
            }
            
//            cout << "survivalCount: " << survivalCount << "\n";
            
            // 다같이 하나만 낸 경우
            if (rspCount[0] == survivalCount || rspCount[1] == survivalCount || rspCount[2] == survivalCount)
                continue;
                
                    
            // 최소 2개의 경우를 냈을 경우 무얼 죽일지 선택
            
            if (rspCount[0] == 0){
                // P win, R lose
                for (int k=0;k<num;k++){
                    if (survival[k] && rsp[k][j] == 'R'){
                        survival[k] = 0;
                    }
                }
            }
            else if (rspCount[1] == 0){
                // S win, P lose
                for (int k=0;k<num;k++){
                    if (survival[k] && rsp[k][j] == 'P'){
                        survival[k] = 0;
                    }
                }
            }
            else if (rspCount[2] == 0){
                // R win, S lose
                for (int k=0;k<num;k++){
                    if (survival[k] && rsp[k][j] == 'S'){
                        survival[k] = 0;
                    }
                }
            }
            
        }
        
//        cout << "survival" << endl;
//        for (int i=0;i<num;i++){
//            cout << survival[i] << " ";
//        }
//        cout << "\n";
        
        int survivalRobot = 0;
        for (int i=0;i<num;i++){
            if (survival[i] && survivalRobot !=0) {
                survivalRobot = 0;
                break;
            }
            if (survival[i]) survivalRobot = i+1;
        }

        cout <<  survivalRobot << "\n";
        
        
    }
    
    return 0;
}


/* 첫번째 로봇의 index 는 1 */

