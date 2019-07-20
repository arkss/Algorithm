#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> city(100000);
// 각 city 에 대해서 neighbor 가 몇 개 있는지
vector<int> neighborList(100000);
vector<int> countList(100000);

int dfs(int cityIndex){
    if (countList[cityIndex])
        return countList[cityIndex];
    // 자기자신이 있으므로 길이는 1부터 시작
    int count = 1;
    // neighbor의 수 만큼 순회
    for (int i=0;i<neighborList[cityIndex];i++){
        // neighbor city
        int adjCityIndex = city[cityIndex][i];
        // neighbor city 의 이웃의 수가 현재 city보다 많으면,
        if (neighborList[cityIndex] < neighborList[adjCityIndex]){
            count = max(dfs(adjCityIndex)+1 , count);
        }
    }
    countList[cityIndex] = count;
    return count;
}
int main(int argc, const char * argv[]) {
    int n,m;
    //(1 ≤ n ≤ 100,000, n-1 ≤ m ≤ 300,000)
    cin >> n >> m;

    int c1, c2;
    for (int i=0;i<m;i++){
        cin >> c1 >> c2;
        
        // 인접리스트 구현
        city[c1].push_back(c2);
        city[c2].push_back(c1);
        
        // 이웃의 개수 추가
        neighborList[c1]++;
        neighborList[c2]++;
    }
    
    int result=0;
    for (int i=0;i<n;i++){
        result = max(dfs(i), result);
    }
    
    cout << result << endl;
    
    return 0;
}


/*
 도시 사이에는 one road
 
 모든 도로는 bidirectional
 
 연결되는 도로가 있으면 두 도시는 neighbors
 
 각 도시는 최소 1개 이상의 이웃
 
 player 는 어디서든 시작 가능
 
 (c0, c1, …, cm-1) -> 정복할 도시
 
 ci 와 c(i+1) 은 neighbors
 
 i 가 커질수록 neighbors의 수가 많은 도시
 
 예시의 답은 (2,5,4,1)
 
 n 은 도시 수, m 은 도로 수
 (1 ≤ n ≤ 100,000, n-1 ≤ m ≤ 300,000)
 
 출력은 정복할 수 있는 도시 리스트의 최대 길이
 
 
< idea >
 0 1
 0 4
 1 2
 1 3
 1 4
 1 5
 2 5
 3 4
 4 5
 
다음과 같이 입력이 들어올떄, 숫자를 카운트하면 각 도시의 neighbor 수를 구할 수 있다.
 
다음으로는 인접 리스트를 만들어준다.
 

 
 
 */
