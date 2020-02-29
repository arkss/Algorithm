

#include <iostream>
#include <math.h>

#define pi 3.141592653589 // pi 값 자세히 적어야 정답

int main(int argc, const char * argv[]) {
    int R;
    double euclid,texi; // 유클리드 기하학에서의 넓이, 택시 기하학에서의 넓이
    
    std::cin >> R;
    
    euclid = pi*R*R;
    texi = 2*R * 2*R * 1/2;
    
//    std::cout << euclid<<std::endl;  3.14159
//    std::cout << texi  <<std::endl;  2
    
// 그냥 출력할 경우 유효자리 숫자도 맞춰주지 않고, 정수부,소수부 포함 6자리로 고정되어 있다.
    
    std::cout << std::fixed; // 소수점을 고정시켜 표현
    std::cout.precision(6);  // 6자리로 고정시킴, 이 때 7번째 자리는 반올림을 통해
// 뒤에서는 std::cout << std::fixed 를 해제하기 위해서는
// std::cout.unsetf(std::ios::fixed); 를 통해서 해제가능
    
    std::cout << euclid<<std::endl; //3.141593
    std::cout << texi  <<std::endl; //2.000000
    
}
