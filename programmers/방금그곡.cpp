#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    return answer;
}

string changeMelody(string melody){
    string changed = "";
    for (int i=0;i<melody.size();i++){
        if (melody[i] != '#')
            changed += melody[i];
        else {
            char prev = changed[changed.size()-1];
            if (prev == 'C') changed[changed.size()-1] = 'c';
            else if (prev == 'D') changed[changed.size()-1] = 'd';
            else if (prev == 'F') changed[changed.size()-1] = 'f';
            else if (prev == 'G') changed[changed.size()-1] = 'g';
            else if (prev == 'A') changed[changed.size()-1] = 'a';
        }
    }

    return changed;
}

string solution(string m, vector<string> musicinfos){
    m = changeMelody(m);
    vector<pair<string,string> > answer;
    for (int i=0;i<musicinfos.size();i++){
        string musicinfo = musicinfos[i];
        vector<string> musicinfo_vector = split(musicinfo, ',');
        string start_time = musicinfo_vector[0];
        string end_time = musicinfo_vector[1];
        string title = musicinfo_vector[2];
        string melody = changeMelody(musicinfo_vector[3]);

        int t = stoi(end_time.substr(0,2)) - stoi(start_time.substr(0,2));
        int minute = stoi(end_time.substr(3,2)) - stoi(start_time.substr(3,2));

        int total_time = t*60 + minute;
        string play = "";
        for (int i=0;i<total_time;i++){
            play += melody[i%melody.size()];
        }
        //cout << "play: " << play << "\n";
//play : CDEFGABCDEFGAB 14
// m : ABCDEFG 7 
        //cout << "play: " << play << "\n";
        if (play.size() < m.size()) continue;
        for (int j=0;j<play.size()-m.size()+1;j++){
            // cout << play.size() << " " << m.size() << "\n";
            // cout << play[j] << "\n";
            if (play.substr(j,m.size()) == m) {
                answer.push_back(make_pair(title, musicinfo_vector[3]));
                break;
            }
        }    
    }
    if (answer.empty()) return "(None)";  

    int maxV =0;
    string rst = "";
    
    for (int i=0;i<answer.size();i++){
        string titleTemp = answer[i].first;
        string melodyTemp = answer[i].second;

        if (maxV < melodyTemp.size()){
            maxV = melodyTemp.size();
            rst = titleTemp;
        }
    }
    return rst;
}

int main(){
    vector<string> musicinfos;
    musicinfos.push_back("12:00,12:14,HELLO,CDEFGAB");
    musicinfos.push_back("13:00,13:05,WORLD,ABCDEF");

    cout << solution("ABCDEFG", musicinfos) << "\n";
    return 0;
}

// [12:00,12:14,HELLO,CDEFGAB, 13:00,13:05,WORLD,ABCDEF]
// C, C#, D, D#, E, F, F#, G, G#, A, A#, B 
// 방금그곡 서비스에서는 음악 제목, 재생이 시작되고 끝난 시각, 악보를 제공한다.
// 네오가 기억한 멜로디와 악보에 사용되는 음은 C, C#, D, D#, E, F, F#, G, G#, A, A#, B 12개이다.
// 각 음은 1분에 1개씩 재생된다. 음악은 반드시 처음부터 재생되며 음악 길이보다 재생된 시간이 길 때는 음악이 끊김 없이 처음부터 반복해서 재생된다. 음악 길이보다 재생된 시간이 짧을 때는 처음부터 재생 시간만큼만 재생된다.
// 음악이 00:00를 넘겨서까지 재생되는 일은 없다.
// 조건이 일치하는 음악이 여러 개일 때에는 라디오에서 재생된 시간이 제일 긴 음악 제목을 반환한다. 재생된 시간도 같을 경우 먼저 입력된 음악 제목을 반환한다.
// 조건이 일치하는 음악이 없을 때에는 `(None)`을 반환한다.