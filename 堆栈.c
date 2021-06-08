#define _CRT_SECURE_NO_WARNINGS 1

//#define MaxSize 100 // �洢����Ԫ�ص���������
//typedef int ElementType; // ��Ա������int����
//typedef struct SNode* Stack;
//struct SNode
//{
//	ElementType Data[MaxSize];
//	int Top;  // ��¼ջ����λ��
//};
//
//void Push(Stack PtrS, ElementType item)
//{
//	if (PtrS->Top == MaxSize - 1)
//	{
//		printf("��ջ����\n");
//		return;
//	}
//	else
//	{
//		PtrS->Data[++(PtrS->Top)] = item;
//		return;
//	}
//}
//
//ElementType Pop(Stack PtrS)
//{
//	if (PtrS->Top == -1)
//	{
//		printf("��ջΪ��\n");
//		return 0;
//	}
//	else
//	{
//		return PtrS->Data[(PtrS->Top)--];
//	}
//}


//struct DStack
//{
//	ElementType Data[MaxSize];
//	int Top1;
//	int Top2;
//}S;
//void Push(struct DStack* PtrS, ElementType item,int Tag)
//{
//	// Tag ��Ϊ����������ջ�ı�־��ȡֵ1��2��TagΪ1��ʾ��һ����ջ����֮��ʾ�ڶ�����ջ��
//	if (PtrS->Top2 - PtrS->Top1 == 1)  // �ж϶�ջ�Ƿ���
//	{
//		printf("��ջ����\n");
//		return;
//	}
//	if(Tag ==1)  // �Ե�һ����ջ���в���
//	{
//		PtrS->Data[++(PtrS->Top1)] = item;
//	}
//	else    // �Եڶ�����ջ���в���
//		PtrS->Data[--(PtrS->Top2)] = item;
//}
//int main()
//{
//	S.Top1 = -1;
//	S.Top2 = MaxSize;
//
//	return 0;
//}

//ElementType Pop(struct DStack* PtrS,int Tag)
//{
//	if (Tag == 1)
//	{
//		if (PtrS->Top1 == -1)
//		{
//			printf("��ջ1Ϊ��\n");
//			return NULL;
//		}
//		else
//		{
//			return PtrS->Data[(PtrS->Top1)--];
//		}
//	}
//	else
//	{
//		if (PtrS->Top2 == MaxSize)
//		{
//			printf("��ջ2Ϊ��\n");
//			return NULL;
//		}
//		else
//		{
//			return PtrS->Data[(PtrS->Top2)++];
//		}
//	}
//}

#include <stdio.h>
#include <malloc.h>
typedef int ElementType;

typedef struct SNode* Stack;
struct SNode
{
	ElementType Data;
	struct SNode* Next;
};

Stack CreateStack()
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

int IsEmpty(Stack S)
{
	// �ж϶�ջ�Ƿ�Ϊ�գ���Ϊ�շ���1�����򷵻�0��
	return (S->Next == NULL);
}

void Push(ElementType x, Stack S)
{
	// ��Ԫ��xѹ��ջS��
	Stack p = (Stack)malloc(sizeof(struct SNode));
	p->Data = x;
	p->Next = S->Next;
	S->Next = p;
}

ElementType Pop(Stack S)
{
	Stack p;
	ElementType tmp;
	if (IsEmpty(S))
	{
		printf("��ջΪ��\n");
		return NULL;
	}
	p = S->Next;
	tmp = p->Data;
	S->Next = p->Next;
	free(p);
	return tmp;
}