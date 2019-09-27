#include <iostream>
#include <cmath>

typedef long long ll;
using namespace std;

class SegmentTree{

private:
    ll* tree;
    ll* A;
    
    ll init(int index, int start, int end){
        if (start == end)
            tree[index] = A[start];
        else{
            int mid = (start+end) / 2;
            tree[index] = init(index*2+1, start, mid) + init(index*2+2,mid+1,end);
        }
        return tree[index];
    }

public:
    SegmentTree(int N, ll* A){
        int h = (int)ceil(log2(N));
        int tree_size = 1 << (h+1);
        tree = new ll[tree_size];
        
        // private A 에 매개변수 A 를 저장
        this->A = A;
        init(0,0,N-1);
    }
    // 소멸자
    ~SegmentTree(){
        delete [] tree;
    }
    
    // left 부터 right 까지의 합 구하기
    ll getSum(int index, int start, int end, int left, int right){
        if (left > end || right < start) return 0;
        else if (left <= start && right >= end){
            return tree[index];
        }
        
        int mid = (start+end) / 2;
        return getSum(index*2+1, start, mid, left, right) + getSum(index*2+2, mid+1, end, left, right);
    }
    
    void update(int changed_index, ll diff , int index, int start, int end){
        if (changed_index < start || changed_index > end)
            return;
        
        tree[index] += diff;
        
        if (start != end){
            int mid = (start+end) / 2;
            update(changed_index, diff, index*2+1, start, mid);
            update(changed_index, diff, index*2+2,mid+1, end);
        }
    }
};

int main(int argc, const char * argv[]) {
    
    ll A[1000001];
    int N,M,K;
    
    cin >> N >> M >> K;
    
    for (int i=0;i<N;i++){
        cin >> A[i];
    }
    
    int C = M + K;
    
    SegmentTree st(N,A);
    
    while (C--){
        int a,b;
        cin >> a >> b;
        if (a == 1){
            ll c;
            cin >> c;
            
            ll diff = c-A[b-1];
            A[b-1] = c;
            st.update(b-1, diff, 0, 0 , N-1);
        }
        
        else if (a==2){
            int c;
            cin >> c;
            cout << st.getSum(0,0,N-1,b-1,c-1) << "\n";
        }
    }
    
    return 0;
}
