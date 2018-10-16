#include"BinTreeNor.h"

pBinTreeNor BuyNewNode(KeyType data)//�����½ڵ�
{
	pBinTreeNor NewNode = (pBinTreeNor)malloc(sizeof(BinTreeNor));
	if (NewNode == NULL)
		return NULL;
	NewNode->data = data;
	NewNode->left = NULL;
	NewNode->right = NULL;
}

void StackInit(pStack pS)//��ʼ��ջ
{
	for (int i = 0; i < MAX; i++)
	{
		pS->array[i] = NULL;
	}
	pS->size = 0;
	pS->top = -1;
}
void Pushstack(pStack pS, pBinTreeNor pRoot)//��ջ
{
	if (pS->size < MAX)
	{
		pS->top++;
		pS->array[pS->top] = pRoot;
		pS->size++;
	}
}
void PopStack(pStack pS)//��ջ
{
	if (IsEmptyStack(pS))
	{
		return;
	}
	pS->array[pS->top] = NULL;
	pS->size--;
	pS->top--;
}
pBinTreeNor TopStack(pStack pS)//ȡջ��Ԫ��
{
	if ((pS->size > 0) && (pS->size < MAX))
	{
		return pS->array[pS->top];
	}
}
int IsEmptyStack(pStack pS)//�ж�ջ�Ƿ�Ϊ��
{
	return (pS->size == 0) ? 1 : 0;//��ջ����1
}
////////////////////////////////////////////////////////////////////////
////�ݹ�ʵ�ֶ������ı���

void Preorder(pBinTreeNor pRoot)//�ݹ�ʵ���������
{
	if (pRoot)
	{
		printf("%c", pRoot->data);
		Preorder(pRoot->left);
		Preorder(pRoot->right);
	}
}
void Inorder(pBinTreeNor pRoot)//�ݹ�ʵ���������
{
	if (pRoot)
	{
		Inorder(pRoot->left);
		printf("%c", pRoot->data);
		Inorder(pRoot->right);
	}
}
void Postorder(pBinTreeNor pRoot)//�ݹ�ʵ�ֺ������
{
	if (pRoot)
	{
		Postorder(pRoot->left);
		Postorder(pRoot->right);
		printf("%c", pRoot->data);
	}
}
//////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
////�ǵݹ�ʵ�ֶ������ı���
void PreorderNor(pBinTreeNor pRoot)//�ǵݹ�ʵ���������
{
	if (pRoot == NULL)
	{
		return;//����
	}
	Stack s;
	StackInit(&s);//��ʼ��ջ
	Pushstack(&s, pRoot);
	while (!IsEmptyStack(&s))
	{
		pBinTreeNor cur = TopStack(&s);
		printf("%c", cur->data);
		PopStack(&s);
		if (cur->right)
		{
			Pushstack(&s, cur->right);
		}
		if (cur->left)
		{
			Pushstack(&s, cur->left);
		}
	}
}
//�ǵݹ�ʵ�ֶ�������������һ�ַ���
//void PreorderNor(pBinTreeNor pRoot)//�ǵݹ�ʵ���������
//{
//	if (pRoot == NULL)
//	{
//		return;//����
//	}
//	Stack s;
//	StackInit(&s);//��ʼ��ջ
//	Pushstack(&s, pRoot);
//	while (!IsEmptyStack(&s))
//	{
//		pBinTreeNor cur = TopStack(&s);
//		PopStack(&s);
//		while (cur)
//		{
//			printf("%c", cur->data);
//			if (cur->right)
//			{
//				Pushstack(&s, cur->right);
//			}
//			cur = cur->left;
//		}
//	}
//}

void InorderNor(pBinTreeNor pRoot)//�ǵݹ�ʵ���������
{
	if (pRoot == NULL)
	{
		return;//����
	}
	Stack s;
	StackInit(&s);//��ʼ��ջ
	pBinTreeNor pCur = pRoot;
	while ((!IsEmptyStack(&s))||(pCur!=NULL))
	{
		while (pCur)
		{
			Pushstack(&s, pCur);
			pCur = pCur->left;
		}
		pCur = TopStack(&s);
		printf("%c", pCur->data);
		PopStack(&s);
		pCur = pCur->right;//ǰ�治�ܼ��ж�����
	}
}
void PostorderNor(pBinTreeNor pRoot)//�ǵݹ�ʵ�ֺ������
{
	if (pRoot == NULL)
	{
		return;//����
	}
	Stack s;
	StackInit(&s);//��ʼ��ջ
	pBinTreeNor pre=NULL;//ָ��pCur�ոշ��ʹ��Ľ��
	pBinTreeNor pCur = pRoot;
	while ((!IsEmptyStack(&s)) || (pCur != NULL))
	{
		while (pCur)
		{
			Pushstack(&s, pCur);
			pCur = pCur->left;
		}
		pCur = TopStack(&s);
		if (pCur->right == NULL||pCur!=pre)
		{
			pre = pCur;
			printf("%c", pCur->data);
			PopStack(&s);
		}
		pCur = pCur->right;//ǰ�治�ܼ��ж�����
	}
}
/////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
////����������
void CreateBinTreeNor(pBinTreeNor *pRoot, char *str, int size, int *index, int invalid)//����������
{
	assert(pRoot != NULL);
	if (((*index) < size) && (str[*index] != invalid))
	{
		*pRoot = BuyNewNode(str[*index]);
		if ((*pRoot) != NULL)
		{
			(*index)++;
			CreateBinTreeNor(&(*pRoot)->left, str, size, index, invalid);//����������
			(*index)++;
			CreateBinTreeNor(&(*pRoot)->right, str, size, index, invalid);//����������
		}
	}
}
