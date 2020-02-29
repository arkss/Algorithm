//
//  main.cpp
//  BAEKJOON_5612
//
//  Created by ark on 15/08/2019.
//  Copyright © 2019 ark. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    int carNum;
    cin >> carNum;
    
    
    int flag = 0;
    int maxNum = 0;
    
    for (int i=0;i<N;i++){
        int entr, exit;
        cin >> entr >> exit;
        
        carNum = carNum + entr - exit;
        if (carNum < 0){
            flag = 1;
            break;
        }
        
        maxNum = max(maxNum, carNum);
    }
    
    if (flag) cout << "0" << "\n";
    else cout << maxNum << "\n";
    
    
    return 0;
}

/*
 터널에 차량이 가장 많았을 때
 
 */
