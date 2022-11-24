#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
    BTDataType data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTNode;

typedef struct MyCircularQueue {
    BTNode** nums;
    int k;  // 队列总长度
    int front;
    int rear;
} MyCircularQueue;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);
// 二叉树销毁
void BinaryTreeDestory(BTNode* root);
// 二叉树节点个数
int BinaryTreeSize(BTNode* root);
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
// 二叉树的深度
int BinaryTreeDepth(BTNode* root);
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root);
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root);
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root);
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);


// 由于C语言没有提供数据结构 所以使用自己写好的队列
// 初始化队列
MyCircularQueue* CircularQueueCreate(int k);
// 判断是否为空
int CircularQueueIsEmpty(MyCircularQueue* obj);
// 判断是否为满
int CircularQueueIsFull(MyCircularQueue* obj);
// 添加元素
void CircularQueueEnQueue(MyCircularQueue* obj, BTNode* value);
// 删除元素
void CircularQueueDeQueue(MyCircularQueue* obj);
// 获取队头元素
BTNode* CircularQueueFront(MyCircularQueue* obj);
// 获取队尾元素
BTNode* CircularQueueRear(MyCircularQueue* obj);
// 获取队列有效长度
int CircularQueueSize(MyCircularQueue* obj);
// 销毁队列
void CircularQueueFree(MyCircularQueue* obj);