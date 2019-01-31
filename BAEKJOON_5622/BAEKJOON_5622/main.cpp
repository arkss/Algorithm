//1
//2 : a b c  65 66 67
//3 : d e f  68 69 70
//4 : g h i  71 72 73
//5 : j k i  74 75 76
//6 : m n o  77 78 79
//7 : p q r s 80 81 82 83
//8 : t u v  84 85 86
//9 : w x y z 87 88 89 90
//0

//원하는 숫자 +1초, 0은 11초


#include <iostream>
#include <string.h>
int match(char s)
{
//    int num;
//    num = s - 'A';
//   다음과 같은 방식으로 숫자의 크기를 줄여줄 수 있다.
    if (s<68)
        return 3;
    else if (s<71)
        return 4;
    else if (s<74)
        return 5;
    else if (s<77)
        return 6;
    else if (s<80)
        return 7;
    else if (s<84)
        return 8;
    else if (s<87)
        return 9;
    else if (s<91)
        return 10;
    return 0;
}
int main(int argc, const char * argv[]) {
//    배열말고 string 을 이용하여서 해결할 수 있다.
    char arr[16]; // string str;
    int result = 0;
    int i;
    
    std::cin >> arr; // std::cin >> str;
    
    for (i=0;i<strlen(arr);i++){
        result += match(arr[i]);
    }
//    for (i=0;i<str.size();i++){
//        result += match(str.at(i));
//    }
    
    std::cout << result;
    
    
    
    
    
    
    
}

