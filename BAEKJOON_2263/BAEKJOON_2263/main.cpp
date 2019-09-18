#include <iostream>

using namespace std;

int inorder[100000];  // L -> root -> R
int postorder[100000]; // L -> R -> root
int pos[100001];
//preorder : root -> L -> R

void solve(int in_start, int in_end, int po_start, int po_end){
    if (in_start > in_end || po_start > po_end) return;
    
    int root = postorder[po_end];
    cout << root << " ";
    int index = pos[root];
    int length = index-in_start;
    
    solve(in_start,index-1,po_start,po_start+length-1);
    solve(index+1, in_end,po_start+length, po_end-1);
}
int main(int argc, const char * argv[]) {

    int n;
    cin >> n;

    for (int i=0;i<n;i++){
        cin >> inorder[i];
    }
    for (int i=0;i<n;i++){
        cin >> postorder[i];
    }
    for (int i=0;i<n;i++){
        // pos 배열은 해당 값이 몇 번째에 위치하는지 O(1) 만에 구할 수 있다.
        pos[inorder[i]] = i;
        // ex) pos[4] = 0; : 4 값은 inorder 배열에서 0번째에 위치
    }
    

    solve(0,n-1,0,n-1);
    return 0;
}

