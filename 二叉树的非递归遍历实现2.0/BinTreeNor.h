#pragma once

#include<Windows.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#define MAX 20

typedef char KeyType;
typedef struct BinTreeNor
{
	KeyType data;
	struct BinTreeNor *left;
	struct BinTreeNor *right;
}BinTreeNor, *pBinTreeNor;

typedef struct Stack
{
	pBinTreeNor array[MAX];
	int size;
	int top;
}Stack, *pStack;



void StackInit(pStack pS);//��ʼ��ջ
void Pushstack(pStack pS, KeyType data);//��ջ
void PopStack(pStack pS);//��ջ
pBinTreeNor TopStack(pStack pS);//ȡջ��Ԫ��
int IsEmptyStack(pStack pS);//�ж�ջ�Ƿ�Ϊ��
void CreateBinTreeNor(pBinTreeNor *pRoot, char *str, int size, int *index, int invalid);//����������
pBinTreeNor BuyNewNode(KeyType data);//�����½ڵ�
///////////////////////////////////////////////////////////////////
////�ݹ�ʵ��
void Preorder(pBinTreeNor pRoot);//�ݹ�ʵ���������
void Inorder(pBinTreeNor pRoot);//�ݹ�ʵ���������
void Postorder(pBinTreeNor pRoot);//�ݹ�ʵ�ֺ������
//////////////////////////////////////////////////////////////////
////�ǵݹ�ʵ��

void PreorderNor(pBinTreeNor pRoot);//�ǵݹ�ʵ���������
void InorderNor(pBinTreeNor pRoot);//�ǵݹ�ʵ���������
void PostorderNor(pBinTreeNor pRoot);//�ǵݹ�ʵ�ֺ������