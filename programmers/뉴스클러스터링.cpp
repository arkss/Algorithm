#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string lower(string str){
    string result = "";
    for (int i=0;i<str.size();i++){
        char item = str[i];
        if ('A' <= item && item <= 'Z') result += (char)(item - 'A'+'a');
        else result += item;
    }
    return result;
}

bool check_alphabet(string str){
    bool isAlphabet = true;
    for (int i=0;i<str.size();i++){
        char temp = str[i];
        if (('a' <= temp && temp <= 'z') || ('A' <= temp && temp <= 'Z')){
            continue;
        } else {
            isAlphabet = false;
            break;
        }
    }
    return isAlphabet;
}

void print_map(map<string, int> v){
    for (map<string, int>::iterator i=v.begin();i!=v.end();i++){
        cout << i->first << " " << i->second << "\n";
    }
    cout << "\n";
}

int solution(string str1, string str2){
    map<string, int> str1Set;
    map<string, int> str2Set;

    str1 = lower(str1);
    str2 = lower(str2);

    for (int i=0;i<str1.size()-1;i++){
        string temp = str1.substr(i,2);
        if (check_alphabet(temp)) 
            if (str1Set.count(temp)) str1Set[temp]++;
            else str1Set[temp] = 1;
    }

    for (int i=0;i<str2.size()-1;i++){
        string temp = str2.substr(i,2);
         if (check_alphabet(temp)) 
            if (str2Set.count(temp)) str2Set[temp]++;
            else str2Set[temp] = 1;
    }

    int intersectionSize = 0;
    int unionSize = 0;

    for (map<string, int>::iterator i=str1Set.begin();i!=str1Set.end();){
        int flag = 0;
        for (map<string, int>::iterator j=str2Set.begin();j!=str2Set.end();){
            if (i->first == j->first) {
                cout << i->first << " " << i->second << "\n";
                cout << j->first << " " << j->second << "\n";
                intersectionSize += min(i->second, j->second);
                unionSize += max(i->second, j->second);
                str1Set.erase(i++);
                str2Set.erase(j++);
                flag = 1;
            } else {
                j++;
            }
        }
        if (!flag) {
            i++;
        }
    }

    for (map<string, int>::iterator i=str1Set.begin();i!=str1Set.end();i++){
        unionSize += i->second;
    }

    for (map<string, int>::iterator i=str2Set.begin();i!=str2Set.end();i++){
        unionSize += i->second;
    }

    double answer;
    if (!intersectionSize && !unionSize) answer = 1;
    else answer = (double)intersectionSize / unionSize;
    answer *= 65536;
    return (int)answer;
}

// 두 집합 A, B 사이의 자카드 유사도 J(A, B)는 두 집합의 교집합 크기를 두 집합의 합집합 크기로 나눈 값으로 정의된다.
// 집합 A와 집합 B가 모두 공집합일 경우에는 나눗셈이 정의되지 않으니 따로 J(A, B) = 1

int main(){
    string str1 = "handshake";
    string str2 = "shake hands";
    cout << solution(str1, str2) << "\n";
    return 0;
}