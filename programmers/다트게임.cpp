#include <iostream>
#include <vector>

using namespace std;

int solution(string dartResult){
    int answer = 0;
    vector<int> points;
    int point = 0;
    for (int i=0;i<dartResult.size();i++){
        char dartItem = dartResult[i];

        if ('0'<=dartItem && dartItem <='9'){
            points.push_back(point);
            point = dartItem-'0';
            if (dartItem == '0' && dartResult[i-1] == '1'){
                points.pop_back();
                point = 10;  
            } 
        }

        if (dartItem == 'S'){}
        else if (dartItem == 'D'){
            point = point*point;
        }
        else if (dartItem == 'T'){
            point = point*point*point;
        }
        
        if (dartItem == '*'){
            int prev = points.back();
            points.pop_back();
            points.push_back(prev * 2);
            point *= 2;
        } 
        else if (dartItem == '#'){
            point = point * (-1);
        }
        
        
        //cout << point << "\n";
    }
    points.push_back(point);
    for (int i=0;i<points.size();i++){
        //cout << points[i] << "\n";
        answer += points[i];
    }
    return answer;
}

int main(){
    cout << solution("10D2S#10S") << "\n";
}

// 1^2 + 2^3 + 3^3