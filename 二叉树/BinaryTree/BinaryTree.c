#include"BinaryTree.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int* pi) {
    if (a[*pi] == '#') {
        (*pi)++;
        return NULL;
    }
    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
    root->data = a[*pi];
    (*pi)++;
    root->left = BinaryTreeCreate(a, pi);
    root->right = BinaryTreeCreate(a, pi);
    return root;
}

// ����������
void BinaryTreeDestory(BTNode* root) {
    if (root == NULL) return;
    BinaryTreeDestory(root->left);
    BinaryTreeDestory(root->right);
    free(root);
}

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    BinaryTreePrevOrder(root->left);
    BinaryTreePrevOrder(root->right);
}

// �������������
void BinaryTreeInOrder(BTNode* root) {
    if (root == NULL) return;
    BinaryTreeInOrder(root->left);
    printf("%c ", root->data);
    BinaryTreeInOrder(root->right);
}

// �������������
void BinaryTreePostOrder(BTNode* root) {
    if (root == NULL) return;
    BinaryTreePostOrder(root->left);
    BinaryTreePostOrder(root->right);
    printf("%c ", root->data);
}

// �������ڵ����
int BinaryTreeSize(BTNode* root) {
    if (root == NULL) return 0;
    return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k) {
    if (root == NULL) return 0;
    if (k == 1) return 1;
    return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

int get_max(int a, int b) {
    if (a > b) return a;
    return b;
}

// �����������
int BinaryTreeDepth(BTNode* root) {
    if (root == NULL) return 0;
    return get_max(BinaryTreeDepth(root->left) + 1, BinaryTreeDepth(root->right) + 1);
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
    if (root == NULL) return NULL;
    if (root->data == x) return root;
    BTNode* leftNode = BinaryTreeFind(root->left, x);
    if (leftNode) return leftNode;
    BTNode* rightNode = BinaryTreeFind(root->right, x);
    if (rightNode) return rightNode;
    return NULL;
}

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root) {
    if (root == NULL) return 1;
    MyCircularQueue* Queue = CircularQueueCreate(20);
    CircularQueueEnQueue(Queue, root);

    while (!CircularQueueIsEmpty(Queue)) {
        BTNode* node = CircularQueueFront(Queue);
        if (node) {
            CircularQueueEnQueue(Queue, node->left);
            CircularQueueEnQueue(Queue, node->right);
            CircularQueueDeQueue(Queue);
        }
        else {
            break;
        }
    }

    while (!CircularQueueIsEmpty(Queue)) {
        BTNode* node = CircularQueueFront(Queue);
        if (node == NULL) {
            CircularQueueDeQueue(Queue);
        }
        else {
            CircularQueueFree(Queue);
            return 0;
        }
    }
    CircularQueueFree(Queue);
    return 1;
}

// �������
void BinaryTreeLevelOrder(BTNode* root) {
    if (root == NULL) return;
    MyCircularQueue* Queue = CircularQueueCreate(20);
    CircularQueueEnQueue(Queue, root);
    
    while (!CircularQueueIsEmpty(Queue)) {
        BTNode* node = CircularQueueFront(Queue);
        if (node->left) CircularQueueEnQueue(Queue, node->left);
        if (node->right) CircularQueueEnQueue(Queue, node->right);
        CircularQueueDeQueue(Queue);
        printf("%c ", node->data);
    }
    printf("\n");
    CircularQueueFree(Queue);
}