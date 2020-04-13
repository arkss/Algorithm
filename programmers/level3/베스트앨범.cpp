#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(const pair<pair<string, int>, int> &a, const pair<pair<string, int>, int> &b){
    if (a.first.first == b.first.first) {
        return a.first.second > b.first.second;
    }

    return a.first.first > b.first.first;
}

bool mapToVcompare(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays){
    vector<pair<pair<string, int>, int>> v;
    map<string, int> ma;
    vector<pair<string, int>> mapToV;
    vector<int> answer;
    
    int size = genres.size();
    for (int i=0;i<size;i++){
        if (ma.count(genres[i]) > 0) ma[genres[i]] += plays[i];
        else ma.insert(make_pair(genres[i], plays[i]));
        v.push_back(make_pair(make_pair(genres[i], plays[i]), i));
    }

    sort(v.begin(), v.end(), compare);

    for (auto item=ma.begin();item!=ma.end();item++){
        mapToV.push_back(make_pair(item->first, item->second));
    }

    sort(mapToV.begin(), mapToV.end(), mapToVcompare);

    for (int i=0;i<mapToV.size();i++){
        string genre = mapToV[i].first;
        int cnt = 0;
        for (int j=0;j<size;j++){
            if (v[j].first.first == genre) {
                answer.push_back(v[j].second);
                cnt++;
                if (cnt == 2) break; 
            }
        }
    }
    return answer;
}

int main(){
    vector<int> result = solution({"classic", "pop", "classic", "classic", "pop"}, {500,600,150,800,2500});
    for (int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }
    return 0;
}