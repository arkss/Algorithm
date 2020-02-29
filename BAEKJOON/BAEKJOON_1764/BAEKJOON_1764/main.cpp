#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> listen; // 얘를 지역 변수로 선언하고 매개변수로 넘겨주면 시간초과가 뜬다. 그게 그렇게 오래 걸리는건가? 재귀적으로 바이너리를 구현해서?

bool binary_search(int start,int end, string see_name)
{
    if (start > end)
        return false;
    else{
        int index = (start+end)/ 2;
        if (listen[index] == see_name)
            return true;
        
        else if (listen[index] > see_name)
            return binary_search(start,index-1,see_name);
        else
            return binary_search(index+1,end,see_name);
    }
        
}

int main(int argc, const char * argv[]) {
    int N,M;
    cin >> N >> M;
    int i,j;
    
    
//    vector<string> see;
    vector<string> answer;
    string str;
    
    // 듣지못한 사람들 vector에 값 받기
    for(i=0;i<N;i++){
        cin >> str;
        listen.push_back(str);
    }
    
    
    
    // 보지못한 사람 vector에 값 받기
//    for(j=0;j<M;j++){
//        cin >> str;
//        see.push_back(str);
//    }
    
    // 이름 순으로 정렬
    sort(listen.begin(),listen.end());
//    sort(see.begin(),see.end());
    
//    if (listen[0] < listen[1])
//        cout << "a가 b보다 작은것"; @@@@@
//    if (listen[0] > listen[1])
//        cout << "b가 a보다 작은것";
    
    for(j=0;j<M;j++){
        cin >> str;
        if (binary_search(0,listen.size()-1,str)){
            
            answer.push_back(str);
        }
    }
    
    sort(answer.begin(),answer.end());
    
    cout << answer.size() << endl;
    for(i=0;i<answer.size();i++){
        cout << answer[i] <<endl;
    }
}
