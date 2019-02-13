#include <iostream>
using namespace std;

int Rev(int num)
{
    int th,h,t,o;

    if (num < 10)
        return num;
    else if (num < 100){
        t = num / 10;
        o = num % 10;
        num = o * 10 + t;
        return num;
    }
    else if (num < 1000){
        h = num / 100;
        num %= 100;
        t = num / 10;
        o = num % 10;
        num = o * 100 + t * 10 + h;
        return num;
    }
    else{
        th = num / 1000;
        num %= 1000;
        h = num / 100;
        num %= 100;
        t = num / 10;
        o = num % 10;
        num = o * 1000 + t * 100 + h * 10 + th;
        return num;
    }
}

int main(int argc, const char * argv[]) {
    int num1, num2;
    int result;

    cin >> num1 >> num2;

    result = Rev(Rev(num1)+Rev(num2));
    cout << result << endl;
}
