class Node:
    def __init__(self, item, left=None, right=None):
        self.item = item
        self.left = left
        self.right = right

    def __str__(self):
        return f'{self.item}: {self.left} / {self.right}'


def pre_order(node, tree):
    print(tree[node].item, end="")
    if tree[node].left != '.':
        pre_order(tree[node].left, tree)
    if tree[node].right != '.':
        pre_order(tree[node].right, tree)


def in_order(node, tree):
    if tree[node].left != '.':
        in_order(tree[node].left, tree)
    print(tree[node].item, end="")
    if tree[node].right != '.':
        in_order(tree[node].right, tree)


def post_order(node, tree):
    if tree[node].left != '.':
        post_order(tree[node].left, tree)
    if tree[node].right != '.':
        post_order(tree[node].right, tree)
    print(tree[node].item, end="")


N = int(input())
tree = {}

for _ in range(N):
    item, left, right = input().split()
    tree[item] = Node(item=item, left=left, right=right)


pre_order('A', tree)
print("")
in_order('A', tree)
print("")
post_order('A', tree)
