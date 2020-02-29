#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int check(string str,int length)
{

    for(int i=0;i<length/2;i++){
        if(str[i] != str[length-1-i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

int main(int argc, const char * argv[]) {

    int N;

    cin >> N;
    rewind(stdin);
    // cin.ignore()
    int i,j;

    for(i=0;i<N;i++){
        string str;

        getline(cin , str);
        int length = str.size();

//        for (j=0;j<length;j++){
//            str[j] = tolower(str[j]);
//        }
        transform(str.begin(), str.end(), str.begin(), (int(*)(int))tolower);


        check(str,length);
    }
}
