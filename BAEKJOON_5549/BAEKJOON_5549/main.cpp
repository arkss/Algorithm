#include <iostream>

using namespace std;

char board[1001][1001];
// dp 배열에 J O I 의 수를 저장해놓자.
int dp[1001][1001][3];

int main(int argc, const char * argv[]) {
    
    int m,n;
    cin >> m >> n;
    
    int K;
    cin >> K;
    
    // 값 저장
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            scanf("%1s", &board[i][j]);
        }
    }
    
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            for (int k=0;k<3;k++){
                dp[i][j][k] = dp[i-1][j][k] + dp[i][j-1][k] - dp[i-1][j-1][k];
            }
            if (board[i][j] == 'J'){
                dp[i][j][0]++;
            }
            else if (board[i][j] == 'O'){
                dp[i][j][1]++;
            }
            else{
                dp[i][j][2]++;
            }
        }
    }
    
    for (int i=0;i<K;i++){
        int cnt[3];
        int x1,y1,x2,y2;
        scanf("%d %d %d %d", &x1,&y1,&x2,&y2);
        
        for (int j=0;j<3;j++){
            cnt[j] =dp[x2][y2][j] - dp[x1-1][y2][j] - dp[x2][y1-1][j] + dp[x1-1][y1-1][j];
        }
    
        printf("%d %d %d\n", cnt[0], cnt[1] , cnt[2]);

        
    }

    return 0;
}
