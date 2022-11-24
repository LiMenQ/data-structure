#include"BinaryTree.h"

int main() {

    char* str = "ABD##E#H##CF##G##";
    int i = 0;
    BTNode* root = BinaryTreeCreate(str, &i);
    BinaryTreePrevOrder(root);
    printf("\n");
    BinaryTreeInOrder(root);
    printf("\n");
    BinaryTreePostOrder(root);
    printf("\n");
    printf("%d\n", BinaryTreeSize(root));
    printf("%d\n", BinaryTreeLeafSize(root));
    printf("%d\n", BinaryTreeDepth(root));
    BTNode* node = BinaryTreeFind(root, 'D');
    printf("%c\n", node->data);
    BinaryTreeLevelOrder(root);
    int ret = BinaryTreeComplete(root);
    printf("%d\n", ret);
    BinaryTreeDestory(root);
    return 0;
}