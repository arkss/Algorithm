#include <iostream>
#include <vector>

using namespace std;

int myLock[60][60];

void print_arr(vector<vector<int>> arr){
    for (int i=0;i<arr.size();i++){
        for (int j=0;j<arr.size();j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<vector<int>> keyRotateRight90(vector<vector<int>> key,int cnt){
    if (cnt == 0) return key;
    int keySize = key.size();
    vector<vector<int>> answer(keySize, vector<int>(keySize, 0));

    for (int k=0;k<cnt;k++){

        for (int i=0;i<keySize;i++){
            for (int j=0;j<keySize;j++){
                answer[j][keySize-1-i] = key[i][j];
            }
        }
        key = answer;
    }
    return answer;
}

bool isKey(vector<vector<int>> key, int keySize,int lockSize, int x,int y){
    for (int i=keySize-1;i<keySize-1+lockSize;i++){
        for (int j=keySize-1;j<keySize-1+lockSize;j++){
            int check = myLock[i][j];
            if (x<=i && i<x+keySize && y<=j && j<y+keySize){
                check = myLock[i][j] ^ key[i-x][j-y];
            }
            if (!check) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock){
    int keySize = key.size();
    int lockSize = lock.size();
    int myLockSize = lockSize + (keySize-1) * 2;

    for (int i=keySize-1;i<keySize-1+lockSize;i++){
        for (int j=keySize-1;j<keySize-1+lockSize;j++){
            myLock[i][j] = lock[i-(keySize-1)][j-(keySize-1)];
        }
    }

    bool keyFlag = false;

    for (int i=0;i<myLockSize-(keySize-1);i++){
        for (int j=0;j<myLockSize-(keySize-1);j++){
            for (int k=0;k<4;k++){
                vector<vector<int>> rotatedKey = keyRotateRight90(key, k);
                // cout << k*90 << "도 회전\n";
                // print_arr(rotatedKey);
                // getchar();
                if (isKey(rotatedKey, keySize,lockSize, i, j)){
                    keyFlag = true;
                    i = myLockSize-(keySize-1);
                    j = myLockSize-(keySize-1);
                }
            }
        }
    }

    return keyFlag;
}

int main(){
    cout << solution({{0,0,0},{1,0,0},{0,1,1}},{{1,1,1},{1,1,0},{1,0,1}}) << "\n";
}