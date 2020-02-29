#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int> submit1 = {1,2,3,4,5};
vector <int> submit2 = {2,1,2,3,2,4,2,5};
vector <int> submit3 = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers){
    int answer1 = 0;
    int answer2 = 0;
    int answer3 = 0;

    for (int i=0;i<answers.size();i++){
        if (submit1[i%submit1.size()] == answers[i]) answer1++;
        if (submit2[i%submit2.size()] == answers[i]) answer2++;
        if (submit3[i%submit3.size()] == answers[i]) answer3++;
    }
    
    vector<int> answer;
    int maxAnswer = max(max(answer1, answer2), answer3);

    if (maxAnswer == answer1) answer.push_back(1);
    if (maxAnswer == answer2) answer.push_back(2);
    if (maxAnswer == answer3) answer.push_back(3);

    return answer;
}

int main(){
    vector<int> answers;
    answers.push_back(1);
    answers.push_back(2);
    answers.push_back(3);
    answers.push_back(4);
    answers.push_back(5);
    solution(answers);
    return 0;
}


/*
    1번 수포자 : 12345
    2번 수포자 : 21232425
    3번 수포자 : 3311224455
*/