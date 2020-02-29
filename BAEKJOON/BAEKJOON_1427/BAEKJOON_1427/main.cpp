// 방법 1

#include <iostream>
#include <algorithm>

using namespace std;

int compare(int a,int b)
{
    return a>b;
}

int main()
{
    char arr[10];
    cin >> arr;
    
    sort(arr, arr+strlen(arr), compare);
    
    for(int i=0;i<strlen(arr);i++){
        cout << arr[i];
    }
}


// 방법 2


//#include <iostream>
//#include <algorithm>
//#include <math.h>
//
//using namespace std;
//
//int compare(int a,int b)
//{
//    return a>b;
//}
//
//int main(int argc, const char * argv[]) {
//    int N;
//    int i;
//
//    cin >> N;
//
//    int digit = 0;
//
//    // 들어온 수의 자리수를 구하자
//    for (i=0;i<10;i++){
//        if(N >= pow(10,i))
//            continue;
//        else{
//            digit = i;
//            break;
//        }
//    }
//
//    int number[digit];
//
//
//    for(i=0;i<digit;i++){
//
//        number[i] = N / pow(10,digit-i-1);
////        cout << i <<endl;
////        cout << number[i] << endl;
////        cout << N << endl;
////        cout << pow(10,digit-i) << endl;
//        N = N % (int)pow(10,digit-i-1);
//    }
//    // 내림차순 정렬
//    sort(number,number+digit,compare);
//
//    //출력
//    for (i=0;i<digit;i++){
//        cout << number[i];
//    }
//}
