#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    int T;
    cin >> T;
    for (int t=0;t<T;t++){
        int a,b,c;
        int abP,bcP,caP;
        cin >> a >> b >> c;
        cin >> abP >> bcP >> caP;

        int maxPrice = 0;
        for (int abNum=0;abNum<=min(a,b);abNum++){
            for (int bcNum=0;bcNum<=min(b-abNum,c);bcNum++){
                int caNum = min(a-abNum,c-bcNum);
                maxPrice = max(maxPrice, abNum *abP + bcNum*bcP + caNum *caP);
            }
        }
        cout << maxPrice << endl;
    }
    return 0;
}

/*
 
 3개의 화학제품
 
 두개씩 섞어서 판다.
 그 떄의 최대가격을 구하자.
 
 dp? 점화식을 어떻게 세워야할지 예제도 잘 모르겠다.
 
 AB 를 n 개, BC 를 m 개 만들엇다고 하면,
 A는 a-n개 C는 c-m 개
 
 CA 양은 a-n 과 c-m 중 최솟값
 
 
 
 
 [ 입력 ]
 
 A B C의 양
 AB BC CA 의 가격
 둘다 1~1000
 
 [ 출력 ]
 
 최대가격
 
 */



