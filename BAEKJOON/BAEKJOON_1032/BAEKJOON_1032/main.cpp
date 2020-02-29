#include <iostream>
#include <vector>

using namespace std;

char result[53];

void check(vector<string> v,int N)
{
    int i,j;
    // 파일의 길이 만큼
    for(i=0;i<v[0].size();i++){
        // 모든 파일을 순회
        for(j=1;j<N;j++){
            // j번째 파일 이름의 i번째 문자가 전꺼와 다르면 ?를 추가해준다.
            if (v[j-1][i] != v[j][i]){
                result[i] = '?';
                break;
            }
            // 같으면 그 문자를 추가해준다.
            else{
                result[i] = v[j][i];
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int N; // 파일 이름의 개수
    
    cin >> N;
    
    int i;
    
    vector<string> v;
    
    for(i=0;i<N;i++){
        string str;
        cin >> str;
        v.push_back(str);
    }
    
    if (N==1){
        cout << v[0];
        return 0;
    }
    
    check(v,N);
    cout << result;
}
