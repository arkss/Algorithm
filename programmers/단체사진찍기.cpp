#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef struct node {
    char p1;
    char p2;
    char command;
    int distance;
} node;

vector<char> people;
bool visited[8];
int answer;

void permutation(string line,vector<node> nodes, int cnt){
    if (cnt == 8){
        for (int i=0;i<nodes.size();i++){
            int p1Index, p2Index;
            for (int j=0;j<line.size();j++){
                if (line[j] == nodes[i].p1) p1Index = j;
                else if (line[j] == nodes[i].p2) p2Index = j;
            }
            
            if (nodes[i].command == '='){
                if (!(abs(p1Index-p2Index)-1 == nodes[i].distance)) return;
            }
            else if (nodes[i].command == '<'){
                if (!(abs(p1Index-p2Index)-1 < nodes[i].distance)) return;
            }
            else if (nodes[i].command == '>'){
                if (!(abs(p1Index-p2Index)-1 > nodes[i].distance)) return;
            }

        }
        answer++;
        return;
    }

    for (int i=0;i<8;i++){
        if (!visited[i]){
            visited[i] = 1;
            permutation(line+people[i], nodes, cnt+1);
            visited[i] = 0;
        }
    }
}

int solution(int n, vector<string> data){
    answer = 0;
    people.push_back('A');
    people.push_back('C');
    people.push_back('F');
    people.push_back('J');
    people.push_back('M');
    people.push_back('N');
    people.push_back('R');
    people.push_back('T');

    vector<node> nodes;
    for (int i=0;i<data.size();i++){
        nodes.push_back({data[i][0], data[i][2], data[i][3], data[i][4]-'0'});
    }

    memset(visited, 0, sizeof(visited));

    permutation("", nodes, 0);

    return answer;
}

int main(){
    cout << solution(2, {"N~F=0", "R~T>2"}) << "\n";
}