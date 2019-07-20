#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> hilbert(int N, int M)
{
    pair<int, int> p;
    
    // W1 일 때
    if (N == 2)
    {
        switch (M)
        {
            case 0:
                p = { 1, 1 };
                return p;
            case 1:
                p = { 1, 2 };
                return p;
            case 2:
                p = { 2, 2 };
                return p;
            case 3:
                p = { 2, 1 };
                return p;
        }
    }
    // Wn-1 에 해당
    int half = N / 2;
    // Wn 에 대해 4구역으로 나누면 한 구역 half*half 개의 이동이 필요하다. 즉 M / (half*half) 을 함으로서 4개 구역 중 어디에 있을 지를 고른다.
    int quadrant = M / (half*half);
    
    switch (quadrant)
    {
            //좌하단
        case 0:
            p = hilbert(half, M % (half*half));
            // first와 second를 바꾸는건 y=x 대칭
            swap(p.first, p.second);
            return p;
            
            //좌상단
        case 1:
            p = hilbert(half, M % (half*half));
            // 위로 평행이동
            p.second += half;
            return p;
            
            //우상단
        case 2:
            p = hilbert(half, M % (half*half));
            // 대각선으로 평행이동
            p.first += half;
            p.second += half;
            return p;
            
            //우하단
        case 3:
            p = hilbert(half, M % (half*half));
            pair<int, int> temp = { 2 * half - p.second + 1, half - p.first + 1 };
            return temp;
    }
    return p;
}



int main(void)
{
    int N, M;
    cin >> N >> M;
    //0부터
    pair<int ,int> result = hilbert(N, M - 1);
    cout << result.first << " " << result.second << "\n";
    
    return 0;
}
