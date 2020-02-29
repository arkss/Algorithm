#include <iostream>

typedef struct TreeNode{
    char left, right;
} TreeNode;

// 영어 대문자로 index를 나타내도 문제없을 정도의 배열
TreeNode arr[91];

// 중위 순회
void inorder(char root)
{
    if (root != '.'){
        inorder(arr[root].left);
        std::cout << root;
        inorder(arr[root].right);
    }
}

// 전위 순회
void preorder(char root)
{
    if (root != '.'){
        std::cout << root;
        preorder(arr[root].left);
        preorder(arr[root].right);
    }
}

// 후위 순회
void postorder(char root)
{
    if (root != '.'){
        postorder(arr[root].left);
        postorder(arr[root].right);
        std::cout << root;
    }
}

int main(int argc, const char * argv[]) {
    int num;
    int i;

    std::cin >> num;
    
    

    char n1,n2,n3;

    for(i=0;i<num;i++){
        std::cin >> n1 >> n2 >> n3;
        arr[n1].left = n2;
        arr[n1].right = n3;
    }
    
    preorder('A');
    std::cout << '\n';
    inorder('A');
    std::cout << '\n';
    postorder('A');
    std::cout << '\n';
    return 0;
}
