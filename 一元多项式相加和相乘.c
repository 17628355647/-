#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>

// ���ݽṹ�����
struct PolyNode
{
	int coef;  // ����ʽϵ����
	int expon;  // ����ʽָ����
	struct PolyNode* link;
};
typedef struct PolyNode* Polynomial;


// ������

int Compare(int x, int y)
{
	if (x > y)
		return 1;
	else if (x < y)
		return -1;
	else
		return 0;
}
void Attach(int coef, int expon, Polynomial* pRear)
{
	Polynomial P;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = coef;
	P->expon = expon;
	P->link = NULL;
	(*pRear)->link = P;
	*pRear = P;  // �޸�pRear��ֵ��
}
Polynomial ReadPoly()  // �������ʽ
{
	int N = 0;
	int coef,expon;
	struct PolyNode* Rear;
	struct PolyNode* P;
	struct PolyNode* t;
	printf("���������ʽ��������");
	scanf("%d", &N);   // ���������ʽ������
	P = (struct PolyNode*)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	while (N--)
	{
		printf("����ϵ����ָ����");
		scanf("%d %d", &coef, &expon);  // ��һ��һ��������ϵ����ָ��
		Attach(coef, expon, &Rear);  // �����㡣
	}
	t = P;
	P = P->link;
	free(t);
	return P;
}

Polynomial Mult(Polynomial P1, Polynomial P2)  //����ʽ���
{
	Polynomial t1, t2, P,Rear,tmp;
	int expon, coef;
	if (!P1 || !P2) // P1��P2��һ��Ϊ��ָ�룬���������
		return NULL;
	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	Rear = P;
	while (t2)
	{// ����P1��һ�����P2���õ���ʼ�������ʽ��
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
		t2 = t2->link;
	}
	t1 = t1->link;
	while (t1)
	{
		t2 = P2;
		Rear = P;
		while (t2)
		{
			expon = t1->expon + t2->expon;
			coef = t1->coef * t2->coef;
			while (Rear->link && Rear->link->expon > expon)
				Rear = Rear->link;
			if (Rear->link && Rear->link->expon == expon)
			{
				if (Rear->link->coef + coef)
					Rear->link->coef = Rear->link->coef + coef;
				else
				{
					tmp = Rear->link;
					Rear->link = tmp->link;
					free(tmp);
				}
			}
			else
			{
				tmp = (Polynomial)malloc(sizeof(struct PolyNode));
				tmp->link = Rear->link;
				tmp->coef = coef;
				tmp->expon = expon;
				Rear->link = tmp;
				Rear = Rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t2 = P;
	P = P->link;
	free(t2);
	return P;
}
Polynomial Add(Polynomial P1, Polynomial P2)  // ����ʽ���
{
	Polynomial P, PRear,t1,t2,tmp,t;
	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	PRear = P;
	while (t1 && t2)
	{
		switch (Compare(t1->expon, t2->expon))
		{
		case 1:
			tmp = (Polynomial)malloc(sizeof(struct PolyNode));
			tmp->coef = t1->coef;
			tmp->expon = t1->expon;
			tmp->link = NULL;
			PRear->link = tmp;
			PRear = tmp;
			t1 = t1->link;
			break;
		case -1:
			tmp = (Polynomial)malloc(sizeof(struct PolyNode));
			tmp->coef = t2->coef;
			tmp->expon = t2->expon;
			tmp->link = NULL;
			PRear->link = tmp;
			PRear = tmp;
			t2 = t2->link;
			break;
		case 0:
			if (((t1->coef) + (t2->coef)))
			{
				tmp = (Polynomial)malloc(sizeof(struct PolyNode));
				tmp->coef = (t1->coef) + (t2->coef);
				tmp->expon = t1->expon;
				tmp->link = NULL;
				PRear->link = tmp;
				PRear = tmp;
				t1 = t1->link;
				t2 = t2->link;
			}
			break;
		}
	}
	while (t1)
	{
		tmp = (Polynomial)malloc(sizeof(struct PolyNode));
		tmp->coef = t1->coef;
		tmp->expon = t1->expon;
		tmp->link = NULL;
		PRear->link = tmp;
		PRear = tmp;
		t1 = t1->link;
	}
	while (t2)
	{
		tmp = (Polynomial)malloc(sizeof(struct PolyNode));
		tmp->coef = t2->coef;
		tmp->expon = t2->expon;
		tmp->link = NULL;
		PRear->link = tmp;
		PRear = tmp;
		t2 = t2->link;
	}
	t = P;
	P = P->link;
	free(t);
	return P;
}
void PrintPoly(Polynomial P)    // ��ӡ����ʽ
{
	int flag = 0; // �������������ʽ
	if (P == NULL)
	{
		printf("����ʽΪ��\n");
		return;
	}
	while (P)
	{
		if (flag == 0)
			flag = 1;
		else
			printf(" ");
		printf("%d %d", P->coef, P->expon);
		P = P->link;
	}
}
int main()
{
	Polynomial P1, P2, PP, PS;
	// �������ʽ1
	P1 = ReadPoly();
	// �������ʽ2
	P2 = ReadPoly();
	// �˷����㲢�˳�
	PP = Mult(P1, P2);
	PrintPoly(PP);
	printf("\n");
	// �ӷ����㲢�˳�
	PS = Add(P1, P2);
	PrintPoly(PS);
	return 0;
}