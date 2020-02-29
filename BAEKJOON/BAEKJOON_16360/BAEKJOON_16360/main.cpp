#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int input;
    cin >> input;
    cin.ignore();
    for (int i=0;i<input;i++){
        string str;
        getline(cin, str);
        int len = str.length();
        if (str[len-1] == 'a')
            cout << str << 's' << endl;
        else if (str[len-1] == 'i' || str[len-1] == 'y'){
            for (int j=0;j<len-1;j++){
                cout << str[j];
            }
            cout << "ios" << endl;
        }
        else if (str[len-1] == 'l'){
            cout << str << "es" << endl;
        }
        else if (str[len-1] == 'n'){
            for (int k=0;k<len-1;k++){
                cout << str[k];
            }
            cout << "anes" << endl;
        }
        else if (str[len-1] == 'e' && str[len-2] == 'n'){
            for (int l=0;l<len-2;l++){
                cout << str[l];
            }
            cout << "anes" << endl;
        }
        else if (str[len-1] == 'o'){
            cout << str << 's' << endl;
        }
        else if (str[len-1] == 'r'){
            cout << str << "es" << endl;
        }
        else if (str[len-1] == 't'){
            cout << str << "as" << endl;
        }
        else if (str[len-1] == 'u'){
            cout << str << "s" << endl;
        }
        else if (str[len-1] == 'v'){
            cout << str << "es" << endl;
        }
        else if (str[len-1] == 'w'){
            cout << str << "as" << endl;
        }
        else{
            cout << str << "us" << endl;
        }
    }
    return 0;
}

/*
 어미가 표와 같으면 표와 매칭하여 뒤에 추가를 하고,
 어미가 표에 없으면 us 붙인다.
 ex) cup -> cupus
 
 */
