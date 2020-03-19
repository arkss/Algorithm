#include <iostream>
#include <vector>

using namespace std;

string string_to_lower(string s){
    string result = "";
    for (int i=0;i<s.size();i++){
        char now = s[i];
        if ('A'<=now && now<='Z'){
            now = now + 'a'-'A';
            
        } 
        result += now;
    }
    return result;
}

int solution(int cacheSize, vector<string> cities) {
    // 최근에 들어온 데이터가 뒤에
    vector<string> cache;
    int answer = 0;

    if (cacheSize == 0) {
        return 5*cities.size();
    }
    
    for (int i=0;i<cities.size();i++){
        string now = string_to_lower(cities[i]);
        bool isCached = false;
        for (int j=0;j<cache.size();j++){
            if (now == cache[j]){
                isCached = true;
                cache.erase(cache.begin()+j);
                cache.push_back(now);
                break;
            }
        }

        if (isCached){
            answer+=1;
        } else {
            if (cacheSize == cache.size()){
                cache.erase(cache.begin());
            }
            cache.push_back(now);
            answer+=5;
        }
    }
    return answer;
}

int main(){
    vector<string> cities;
    cities.push_back("Jeju");
    cities.push_back("Pangyo");
    cities.push_back("Seoul");
    cities.push_back("NewYork");
    cities.push_back("LA");
    cities.push_back("Jeju");
    cities.push_back("Pangyo");
    cities.push_back("Seoul");
    cities.push_back("NewYork");
    cities.push_back("LA");
    cout << solution(3, cities) << "\n";

}