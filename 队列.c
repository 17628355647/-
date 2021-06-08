#define _CRT_SECURE_NO_WARNINGS 1

#include <malloc.h>
#include <stdio.h>
#define MaxSize 100
typedef int ElementType;
//struct QNode
//{
//	ElementType Data[MaxSize];
//	int rear;  //��¼���� βԪ��
//	int front; // ��¼���� ͷԪ��
//};
//typedef struct QNode* Queue;
//
//void AddQ(Queue PtrQ, ElementType item)
//{
//	if ((PtrQ->rear + 1) % MaxSize == PtrQ->front)
//	{
//		printf("������\n");
//		return;
//	}
//	PtrQ->rear = (PtrQ->rear + 1) % MaxSize;
//	PtrQ->Data[PtrQ->rear] = item;
//}
//
//ElementType DeleteQ(Queue PtrQ)
//{
//	if (PtrQ->front == PtrQ->rear)
//	{
//		printf("����Ϊ��\n");
//	}
//	else
//	{
//	//��Ϊfront�Ƕ���ͷ�ϵ�ǰһ����ʹ�ü�1����ָ�����ͷ
//		PtrQ->front = (PtrQ->front + 1) % MaxSize;
//		return PtrQ->Data[PtrQ->front];
//	}
//}




struct Node
{
	ElementType Data;
	struct Node* Next;
};
struct QNodoe
{
	struct Node* rear;    //ָ�����β���
	struct Node* front;  // ָ�����ͷ���
};

typedef struct QNodoe* Queue;
Queue PtrQ;

ElementType DeleteQ(Queue PtrQ)
{
	ElementType tmp;
	struct Node* p;
	if (PtrQ->front == NULL)
	{
		printf("����Ϊ��\n");
		return 0;
	}
	tmp = PtrQ->front->Data;
	p = PtrQ->front;
	if (PtrQ->front == PtrQ->rear)
		PtrQ->front = PtrQ->rear = NULL;
	else
		PtrQ->front = p->Next;
	free(p);
	return tmp;
}

void AddQ(Queue PtrQ, ElementType x)
{
	struct Node* p = (struct Node*)malloc(sizeof(struct Node));
	p->Data = x;
	p->Next = NULL;
	PtrQ->rear->Next = p;
	PtrQ->rear = p;
}



struct PolyNode
{
	double coef;  // ϵ��
	double expon;  // ָ��
	struct PolyNode* link;
};
typedef struct PolyNode* Polynomial;
Polynomial P1, P2;


int Compare(double x, double y)
{
	if (x > y)
		return 1;
	else if (x < y)
		return -1;
	else
		return 0;
}
void Attach(double coef, double expon, Polynomial* p)
{
	Polynomial tmp = (Polynomial)malloc(sizeof(struct PolyNode));
	tmp->coef = coef;
	tmp->expon = expon;
	tmp->link = NULL;
	(*p)->link = tmp;
	*p = tmp;
}
Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
	Polynomial front, rear, temp;
	int sum;
	rear = (Polynomial)malloc(sizeof(struct PolyNode));
	front = rear;   // ��front��¼�������ʽ����ͷ���
	while (P1 && P2)  // ����������ʽ���з����������ʱ
		switch (Compare(P1->expon, P2->expon))
		{
		case 1:
			Attach(P1->coef, P1->expon, &rear);
			P1 = P1->link;
			break;
		case -1:
			Attach(P2->coef, P2->expon, &rear);
			P2 = P2->link;
			break;
		case 0:
			sum = P1->coef + P2->coef;
			if (sum)
				Attach(sum, P1->expon, &rear);
			P1 = P1->link;
			P2 = P2->link;
			break;
		}
	// ��δ���������һ������ʽ�����н�����θ��Ƶ��������ʽ��ȥ
	for(;P1;P1=P1->link)
		Attach(P1->coef, P1->expon, &rear);
	for (; P2; P2 = P2->link)
		Attach(P2->coef, P2->expon, &rear);
	rear->link = NULL;
	temp = front;
	front = front->link;  // ��frontָ��������ʽ��һ��������
	free(temp); // �ͷ���ʱ�ձ�ͷ���
	return front;
}