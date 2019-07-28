#include <iostream>

using namespace std;

int palindromeCheck(string arr){
    int wordLen = arr.length();
    int index =0;
    for (index=0;index<wordLen/2;index++){
        if (arr[index] != arr[wordLen-index-1]) break;
    }
    if (index==wordLen/2) return 1;
    else return 0;

    
}

int main(int argc, const char * argv[]) {
    
    
    int T;
    cin >> T;
    
    for (int i=0;i<T;i++){
        int k;
        cin >> k;
        string inputArr[100];
        
        
        for (int i=0;i<k;i++){
            cin >> inputArr[i];
        }
        
        int flag = 0;
        
        for (int i=0;i<k;i++){
            for (int j=0;j<k;j++){
                // 같은 단어끼리 합칠 순 없다.
                if (i==j) continue;
                int check = palindromeCheck(inputArr[i]+inputArr[j]);
                if (check){
                    cout << inputArr[i]<< inputArr[j] << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        
        if (!flag) cout << 0 << endl;
    }
    
    

    return 0;
}

/*
 
 palindrome 문제
 
 단어를 함쳐서 palindrome 이 되는지 확인
 
 char 배열로 하면 길이를 어떻게 재야할지 므로겠어
 char inputArr[10000];
 cin >> inputArr;
 cout << sizeof(inputArr) << endl; // 10000
 cout << sizeof(inputArr[0]); // 1
 
 [ 입력 ]
 T 개의 test cases
 k 개의 단어 (1<=k<=100)
 
 단어 합의 길이는 10000 이하
 
 [ 출력 ]
 palindrome 이 만들어지면 그걸 출력
 안만들어지면 0을 출력
 
 */
