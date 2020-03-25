#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string to_lower(string str){
    string answer = "";
    for (int i=0;i<str.size();i++){
        if ('A' <= str[i] && str[i] <= 'Z'){
            char temp = str[i] + ('a' - 'A');
            answer += temp;
        } else answer += str[i];
    }
    return answer;
}

bool compare(vector<string> a, vector<string> b){
    if (to_lower(a[0]) != to_lower(b[0])) {
        return to_lower(a[0]) < to_lower(b[0]);
    }
    return stoi(a[1]) < stoi(b[1]);
}

vector<vector<string>> split(vector<string> files){
    vector<vector<string>> answer;

    for (int i=0;i<files.size();i++){
        string file = files[i];
        string head = "";
        string number = "";
        string tail = "";
        int flag = 0; // 0: head, 1: number, 2: tail
        for (int j=0;j<file.size();j++){
            
            
            char temp = file[j];
            if ('0' <= temp && temp <= '9'){
                if (flag == 0) flag = 1;
            }  else if (flag == 1) {
                flag = 2;
            }

            if (number.size() == 5) {
                flag = 2;
            }
            if (flag == 0) head += temp;
            else if (flag == 1) number += temp;
            else if (flag == 2) tail += temp; 

            //cout << head << " " << number << " " << tail << "\n";
        }
        vector<string> split_file;
        split_file.push_back(head);
        split_file.push_back(number);
        split_file.push_back(tail);
        answer.push_back(split_file);
    }
    return answer;
}

vector<string> solution(vector<string> files) {
    vector<vector<string>> split_files = split(files);

    stable_sort(split_files.begin(), split_files.end(), compare);
    vector<string> answer;
    for (int i=0;i<split_files.size();i++){
        vector<string> file = split_files[i];
        string fileStr = "";
        for (int j=0;j<file.size();j++){
            fileStr += file[j];
        }
        answer.push_back(fileStr);
    }
    return answer;
}

int main(){
    vector<string> result;
    vector<string> files{"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};
    result = solution(files);
    for (int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }
    return 0;
}