#include <iostream>

using namespace std;

int dp[4001][4001];

int main()
{
    string first;
    string second;
    
    cin >> first;
    cin >> second;
    
    
    int i,j;
    int max_length=0;
    for(i=0;i<first.size();i++){
        for(j=0;j<second.size();j++){
            // first 문자열과 second 문자열의 단어가 같으면 각각의 전 단어까지의 공통부분문자열 길이에 +1
            if (first[i] == second[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
                // 그 길이 중 최대값을 구한다.
                if (dp[i+1][j+1] > max_length)
                    max_length = dp[i+1][j+1];
            }
        }
    }
    
    cout << max_length;
    }



// 시간초과

//#include <iostream>
//
//using namespace std;
//
//int dp[4001];
//
//int main(int argc, const char * argv[]) {
//    string first;
//    string second;
//    int i,j;
//
//    int len_max = 0;
//    int len = 0;
//
//    cin >> first;
//    cin >> second;
//
//    for(i=0;i<first.size();i++){
//        for (j=0;j<second.size();j++){
//            int fir_index = i;
//            int sec_index = j;
//            len = 0;
//            while(1){
//                if (first[fir_index] == second[sec_index]){
//                    len++;
//                    fir_index++;
//                    sec_index++;
//                    if (fir_index == first.size() || sec_index == second.size())
//                        break;
//
//                }
//                else {
//
//                    break;
//                }
//            if (len > len_max){
//                len_max = len;
//
//            }
//
//            }
//
//            }
//        }
//
//    cout << len_max;
//
//}
