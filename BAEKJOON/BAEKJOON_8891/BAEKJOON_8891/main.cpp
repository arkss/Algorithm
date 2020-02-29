#include <iostream>

using namespace std;

long long plane[1000][1000];

pair <int,int> dotNumToPoint(int num){
    pair <int, int> point;
    int flag = 0;
    for (int x=1;x<=1000;x++){
        if (flag) break;
        for (int y=1;y<=1000;y++){
            if (num == plane[x][y]){
                point = {x,y};
                flag = 1;
                break;
            }
        }
    }
    return point;
}

int pointToDotNum(pair <int,int> point){
    int x = point.first;
    int y = point.second;
    return plane[x][y];
}

pair <int,int> pointAdd(pair <int,int> p1, pair <int,int> p2){
    pair <int,int> point;
    point.first = p1.first + p2.first;
    point.second = p1.second + p2.second;
    return point;
}


int main(int argc, const char * argv[]) {
    
    for (int x=1;x<1000;x++){
        for (int y=1;y<1000;y++){
            plane[x][y] = 1 + (y-1)*y /2 + (x-1)*y + (x-1)*x /2;
        }
    }
    
    int T;
    cin >> T;
    for (int t=0;t<T;t++){
        
        
        
        pair<int, int> point[3];
        
        
        int dotNum1, dotNum2;
        cin >> dotNum1 >> dotNum2;
        
        point[0] = dotNumToPoint(dotNum1);
        point[1] = dotNumToPoint(dotNum2);
        // cout << "point[0]: " << point[0].first << " " << point[0].second << endl;
        // cout << "point[1]: " << point[1].first << " " << point[1].second << endl;
        //    cout << "pass" << endl;
        //    point[1] = dotNumToPoint(dotNum2);
        point[2] = pointAdd(point[0], point[1]);
        //cout << "point[2]: " << point[2].first << " " << point[2].second << endl;
        int result = pointToDotNum(point[2]);
        
        cout << result << endl;
    }
    
    
}


/*
 
 2차원 평면에 무수히 많은 점이 있다.
 
 x,y 는 양의 정수
 
 각 점이 있고 각 점에는 Dot number가 부여되어있다.
 
 두 dot number의 합은 각 dot number의 좌표의 합을 구한 후 새로 생긴 좌표의 dot number를 구해준다.
 
 
[ 입력 ]
 
 t 개의 test case
 
 두 개의 dot number가 들어온다.
 
 [ 출력 ]
 
 두 개의 dot number 의 합을 출력한다.
 
 */
