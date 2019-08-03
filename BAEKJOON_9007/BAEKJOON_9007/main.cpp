
#include <iostream>
#include <algorithm>

using namespace std;


int abs(int num){
    if (num<0) num = -num;
    return num;
}

int main(int argc, const char * argv[]) {

    int T;
    cin >> T;
    
    for (int t=0;t<T;t++){
        int table[4][1000];
        int goal,numInCanoe;
        cin >> goal >> numInCanoe;
        
        for (int i=0;i<4;i++){
            for (int j=0;j<numInCanoe;j++){
                cin >> table[i][j];
            }
        }
        
        int list1[1000000];
        int list2[1000000];
        
        for (int i=0;i<numInCanoe;i++){
            for (int j=0;j<numInCanoe;j++){
                list1[i*numInCanoe+j] = table[0][i] + table[1][j];
                list2[i*numInCanoe+j] = table[2][i] + table[3][j];
            }
        }
        
        int length = numInCanoe*numInCanoe;
        
        sort(list1, list1+ length);
        sort(list2, list2+ length);
        
        int minValue = 999999999;
        int result = 0;
        int flag = 0;
        for (int i=0;i<length;i++){
            int goal2 = goal - list1[i];
            
            int left=0,right=length-1;
            while (left<=right){
                int point = (left+ right) / 2;
                
                // 목표치에 대한 편차가 같으면 작은 값을 택한다.
                if(minValue == abs(goal2 - list2[point]) && result > list1[i] + list2[point]) {
                    result = list1[i] + list2[point];
                }
                else if (minValue > abs(goal2 - list2[point])){
                    minValue = abs(goal2 - list2[point]);
                    result = list1[i] + list2[point];
                }
                
                
                if (goal2 < list2[point]){
                    right = point-1;
                }
                else if (goal2 > list2[point]){
                    left = point+1;
                }
                else {
                    cout << goal << endl;
                    flag = 1;
                    break;
                }
                
            }
            if (flag) break;
        }
        
        if (!flag){
            cout << result << endl;
        }
        
    }
    
    return 0;
}
