#define _CRT_SECURE_NO_WARNINGS 1

//#define MaxSize 100 // 存储数据元素的最大个数。
//typedef int ElementType; // 成员类型用int举例
//typedef struct SNode* Stack;
//struct SNode
//{
//	ElementType Data[MaxSize];
//	int Top;  // 记录栈顶的位置
//};
//
//void Push(Stack PtrS, ElementType item)
//{
//	if (PtrS->Top == MaxSize - 1)
//	{
//		printf("堆栈已满\n");
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
//		printf("堆栈为空\n");
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
//	// Tag 作为区分两个堆栈的标志，取值1或2，Tag为1表示第一个堆栈，反之表示第二个堆栈。
//	if (PtrS->Top2 - PtrS->Top1 == 1)  // 判断堆栈是否满
//	{
//		printf("堆栈满了\n");
//		return;
//	}
//	if(Tag ==1)  // 对第一个堆栈进行操作
//	{
//		PtrS->Data[++(PtrS->Top1)] = item;
//	}
//	else    // 对第二个堆栈进行操作
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
//			printf("堆栈1为空\n");
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
//			printf("堆栈2为空\n");
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
	// 判断堆栈是否为空，若为空返回1，否则返回0。
	return (S->Next == NULL);
}

void Push(ElementType x, Stack S)
{
	// 将元素x压入栈S中
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
		printf("堆栈为空\n");
		return NULL;
	}
	p = S->Next;
	tmp = p->Data;
	S->Next = p->Next;
	free(p);
	return tmp;
}