#include <iostream>
#include <cstring>

using namespace std;

int check(char *arr)
{
    int length = strlen(arr);
    for (int i =0;i<length/2;i++){
        if (arr[i] != arr[length-1-i])
            return 0;
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    char pel[100];
    int result;
    cin >> pel;
    result = check(pel);
    
    cout << result;
}
