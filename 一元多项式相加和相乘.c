#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>

// 数据结构的设计
struct PolyNode
{
	int coef;  // 多项式系数。
	int expon;  // 多项式指数。
	struct PolyNode* link;
};
typedef struct PolyNode* Polynomial;


// 程序框架

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
	*pRear = P;  // 修改pRear的值。
}
Polynomial ReadPoly()  // 读入多项式
{
	int N = 0;
	int coef,expon;
	struct PolyNode* Rear;
	struct PolyNode* P;
	struct PolyNode* t;
	printf("请输入多项式的项数：");
	scanf("%d", &N);   // 先输入多项式多少项
	P = (struct PolyNode*)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	while (N--)
	{
		printf("输入系数和指数：");
		scanf("%d %d", &coef, &expon);  // 再一个一个的输入系数和指数
		Attach(coef, expon, &Rear);  // 构造结点。
	}
	t = P;
	P = P->link;
	free(t);
	return P;
}

Polynomial Mult(Polynomial P1, Polynomial P2)  //多项式相乘
{
	Polynomial t1, t2, P,Rear,tmp;
	int expon, coef;
	if (!P1 || !P2) // P1与P2有一个为空指针，程序结束。
		return NULL;
	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	Rear = P;
	while (t2)
	{// 先用P1第一项乘以P2，得到初始结果多项式。
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
Polynomial Add(Polynomial P1, Polynomial P2)  // 多项式相加
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
void PrintPoly(Polynomial P)    // 打印多项式
{
	int flag = 0; // 辅助调整输出格式
	if (P == NULL)
	{
		printf("多项式为空\n");
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
	// 读入多项式1
	P1 = ReadPoly();
	// 读入多项式2
	P2 = ReadPoly();
	// 乘法运算并退出
	PP = Mult(P1, P2);
	PrintPoly(PP);
	printf("\n");
	// 加法运算并退出
	PS = Add(P1, P2);
	PrintPoly(PS);
	return 0;
}