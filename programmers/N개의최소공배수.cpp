#include <iostream>
#include <vector>

using namespace std;

int gcd(int a,int b){
    int temp;

    while(1){
        temp = a % b;
        a = b;
        b = temp;
        if (b == 0) break;
    }

    return a;
}

int lcd(int a,int b){
    return a*b / gcd(a,b);
}

int solution(vector<int> arr){
    int answer = arr[0];
    for (int i=1;i<arr.size();i++){
        answer = lcd(answer,arr[i]);
    }

    return answer;
}

int main(){
    cout << solution({2,6,8,14}) << "\n";
    return 0;
}