/*
 아이디어
 
 가로 선을 긋는다.
 선을 긋는 범위는 y축 기준으로 가장 낮은 값부터 가장 큰 값
 가로 폭은 의미가 없다.
 직사각형이라고 생각하지 말고 압축시켜서 선분이라고 생각하자.
 
 1. 가장 낮은 곳부터 가장 높은 곳까지 우선 한 번 순회한다.
 2. 최대로 사각형을 많이 지나는 지점들을 저장한다.
 3. (2)의 지점들에 대해서 그 직선이 지나는 사각형은 고려해주지 않고
 다른 사각형들에 대해서 최대값을 찾아준다.
 
 n의 범위는 3 ≤ n ≤ 100,000
 좌표의 조건은
 −10,000,000 ≤ ux, uy, vx, vy ≤ 10,000,000.
 ux, uy, vx and vy (with ux < vx and uy > vy)
 */


#include <iostream>

using namespace std;

// [사각형의 개수][시작 점과 끝 점]
int rec[100000][2];
// 직선을 그었을 때 사각형과 만나면 1, 아니면 0
int check[100000];

typedef struct{
    int count = 0;
    int Perforated_rec[100000];
} element;

int main(int argc, const char * argv[]) {
    
    int N;
    int i,j;
    cin >> N;
    // uy 와 vy 보다 큰 값
    int ux, uy, vx, vy;
    // 사각형이 존재하는 높이의 최대, 최소
    int h_max = 0;
    int h_min = 10000000;
    // 첫번째로 선을 그엇을 때 지나는 사각형의 최대값
    int first_count_max = 0;
    int count = 0;
    
    for(i=0;i<N;i++){
        cin >> ux >> uy >> vx >> vy;
        if (h_max < uy)
            h_max = uy;
        if (h_min > vy)
            h_min = vy;
        rec[i][0] = uy;
        rec[i][1] = vy;
    }
    
    for(i=h_min;i<=h_max;i++){
        element temp;
        for(j=0;j<N;j++){
            if (i >= rec[j][1] && i<= rec[j][0]){
                temp.count++;
                
            }
            
        }
        if (first_count_max < count)
            first_count_max = count;
        check[i] = count;
    }
    
    
    
    for(i=h_min;i<=h_max;i++){
        cout << i <<":" << check[i] << endl;
    }
    
//    for (i=0;i<N;i++){
//        for(j=0;j<2;j++){
//            cout.width(2);
//            cout << rec[i][j];
//        }
//        cout << endl;
//    }
}
