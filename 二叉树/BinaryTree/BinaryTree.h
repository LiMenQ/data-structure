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
    int k;  // �����ܳ���
    int front;
    int rear;
} MyCircularQueue;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);
// ����������
void BinaryTreeDestory(BTNode* root);
// �������ڵ����
int BinaryTreeSize(BTNode* root);
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
// �����������
int BinaryTreeDepth(BTNode* root);
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root);
// �������������
void BinaryTreeInOrder(BTNode* root);
// �������������
void BinaryTreePostOrder(BTNode* root);
// �������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);


// ����C����û���ṩ���ݽṹ ����ʹ���Լ�д�õĶ���
// ��ʼ������
MyCircularQueue* CircularQueueCreate(int k);
// �ж��Ƿ�Ϊ��
int CircularQueueIsEmpty(MyCircularQueue* obj);
// �ж��Ƿ�Ϊ��
int CircularQueueIsFull(MyCircularQueue* obj);
// ���Ԫ��
void CircularQueueEnQueue(MyCircularQueue* obj, BTNode* value);
// ɾ��Ԫ��
void CircularQueueDeQueue(MyCircularQueue* obj);
// ��ȡ��ͷԪ��
BTNode* CircularQueueFront(MyCircularQueue* obj);
// ��ȡ��βԪ��
BTNode* CircularQueueRear(MyCircularQueue* obj);
// ��ȡ������Ч����
int CircularQueueSize(MyCircularQueue* obj);
// ���ٶ���
void CircularQueueFree(MyCircularQueue* obj);