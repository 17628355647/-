#define _CRT_SECURE_NO_WARNINGS 1

//д������ʵ�ֺ���PrintN��ʹ������һ��������N����ӡ1��N��ȫ����������

//#include <stdio.h>
//#include <time.h>
//void PrintN1(int n)  // ����1��ѭ��ʵ��
//{
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		printf("%d ", i);
//	}
//}
//void PrintN2(int n)  // ����2���ݹ�ʵ�֡��ݹ飬�Կռ��ռ�ã��е�ʱ��ǳ��ֲ���
//{
//	if (n)
//	{
//		PrintN2(n - 1);
//		printf("%d ", n);
//	}
//}
//int main()
//{
//	int n = 0;
//	printf("�����룺");
//	scanf("%d", &n);
//	clock_t start, stop;  // ������������¼ʱ������
//	double shijian;     // ���������¼ʱ��
//	start = clock();   // ��¼��ʼʱ������
//	PrintN2(n);
//	stop = clock();    // ��¼����ʱ������
//	shijian = (double)((stop - start) / CLK_TCK);   // �ô�������������ÿ���������õ���ʱ�䣬��λ��
//	printf("\n%lf\n", shijian);
//}



// д��������������ʽ�ڸ�����x����ֵ��
//double f(int n, double a[], double x)
//{
//	int i = 0;
//	double p = a[n];
//	for (i = n; i > 0; i--)
//	{
//		p = a[i - 1] + x * p;
//	}
//	return p;
//}

//#include <math.h>
//#include <stdio.h>
//#include <time.h>
//#define MAX 10
//double f1(int n, double a[], double x)
//{
//	int i = 0;
//	double p = a[0];
//	for (i = 1; i <= n; i++)
//	{
//		p += (a[i] * pow(x, i));
//	}
//	return p;
//}
//double f2(int n, double a[], double x)
//{
//	double p = a[n];
//	int i = 0;
//	for (i = n; i > 0; i--)
//	{
//		p = a[i - 1] + p * x;
//	}
//	return p;
//}
//clock_t start, stop;
//double duration;
//int main()
//{
//	double arr[MAX];
//	int i = 0;
//	for (i = 0; i < MAX; i++)
//	{
//		arr[i] = (double)i;  // �����ʼ��
//	}
//	start = clock();
//	for (i = 0; i < 10000000; i++)
//	{
//		f1(MAX - 1, arr, 1.1);   
//// ֮����Ҫ������ô��Σ�����Ϊ��f1��f2�������������еĺܿ죬clock()�����޷���׽��ticks�ı仯�������ظ��Ķ�γ�����У�
//// ʹ�ò�����ܵ�ʱ�Ӵ������ֳ��������㱻�⺯��ƽ��ÿ������ʱ�伴�ɡ�
//	}
//	stop = clock();
//	duration = ((double)(stop - start)) / CLK_TCK/10000000;
//	printf("ticks1 = %lf\n", (double)(stop - start));
//	printf("duration1 = %6.2e\n", duration);
//
//
//	start = clock();
//	for (i = 0; i < 10000; i++)
//	{
//		f2(MAX - 1, arr, 1.1);
//	}
//	stop = clock();
//	duration = ((double)(stop - start)) / CLK_TCK/10000000;
//	printf("ticks2 = %lf\n", (double)(stop - start));
//	printf("duration2 = %6.2e\n", duration);
//	
//}





// ѡ�������㷨��α������
//void SelectionSort(int List[], int N)
//{
//	// ��N������List[0].....List[N-1] ���зǵݼ�����
//	for (int i = 0; i < N; i++)
//	{
//		//��List[i]��List[N - 1]������СԪ��������λ�ø���MinPosition;
//		int MinPosition = ScanForMin(List, i, N - 1);
//		//��δ���򲿷ֵ���СԪ�������򲿷ֵ����λ��;
//		Swap(List[i], List[MinPosition]);
//	}
//}


//void printn(int n)
//{
//	if (n)
//	{
//		printn(n - 1);
//		printf("%d\n", n);
//	}
//	return;
//}
//
//double f(int n, double a[], double x)
//{
//	int i = 0;
//	double p = a[n];
//	for (i = n; i > 0; i--)
//	{
//		p = a[i - 1] + p * x;
//	}
//	return p;
//}





//// �㷨1
//int MaxSubseqsum1(int A[], int N)
//{
//	int ThisSum, MaxSum = 0;
//	int i, j, k;
//	for (i = 0; i < N; i++)   // i���������λ��
//	{
//		for (j = i; j < N; j++)  // j�������Ҷ�λ��
//		{
//			ThisSum = 0;    // ThisSum����A[i]��A[j]�����к�
//			for (k = i; k <= j; k++)
//			{
//				ThisSum += A[k];
//				if (ThisSum > MaxSum)   // ����յõ��Ľ������MaxSum�����滻
//				{
//					MaxSum = ThisSum;
//				}
//			}
//		}
//	}
//	return MaxSum;
//}
//// ����㷨�ĸ��Ӷȣ�T()
//
//// �㷨2
//int MaxSubseqsum1(int A[], int N)
//{
//	int ThisSum, MaxSum = 0;
//	int i, j, k;
//	for (i = 0; i < N; i++)   // i���������λ��
//	{
//		ThisSum = 0;    // ThisSum����A[i]��A[j]�����к�
//		for (j = i; j < N; j++)  // j�������Ҷ�λ��
//		{
//			ThisSum += A[j];
//			if (ThisSum > MaxSum)   // ����յõ��Ľ������MaxSum�����滻
//			{
//				MaxSum = ThisSum;
//			}
//		}
//	}
//	return MaxSum;
//}
//// ����㷨�ĸ��Ӷȣ�T()
//
//int MaxSubseqsum1(int A[], int N)
//{
//	int ThisSum, MaxSum;
//	int i;
//	ThisSum = MaxSum = 0;
//	for (i = 0; i < N; i++)
//	{
//		ThisSum += A[i];   // �����ۼ�
//		if (ThisSum > MaxSum)
//			MaxSum = ThisSum;  // ���ָ��������µ�ǰ���
//		else if (ThisSum < 0) // �����ǰ���к�Ϊ�����򲻿���ʹ���沿����������֮��
//			ThisSum = 0;
//	}
//}


// ����洢
//#define MAXSIZE 100
//typedef int ElementType;  // ��������ÿ��Ԫ��Ϊint��
//struct PolyNode
//{
//	int coef;
//	int expon;
//	struct PolyNode* link;
//};
//
//typedef struct LNode* List;
//struct LNode
//{
//	ElementType Data[MAXSIZE];   // ������ݵ�����
//	int Last;  // ��¼�������һ��Ԫ������λ��
//};
//struct LNode L;
//List Ptrl;
//
//List MakeEmpty()
//{
//	List Ptrl;
//	Ptrl = (List)malloc(sizeof(struct LNode));
//	Ptrl->Last = -1;
//	return Ptrl;
//}
//
//int Find(ElementType x, List Ptrl)
//{
//	int i = 0;
//	while (i <= Ptrl->Last && Ptrl->Data[i] != x)
//	{
//		i++;
//	}
//	if (i > Ptrl->Last)
//		return -1;  // û���ҵ�����-1
//	else
//		return i;  // �ҵ��ͷ��ش洢λ��
//}
//
//void Insert(ElementType x, int i, List Ptrl)
//{
//	int j;
//	if (Ptrl->Last == MAXSIZE - 1)
//	{
//		printf("�����ˣ��޷�����\n");
//		return;
//	}
//	if (i<1 || i>Ptrl->Last + 2)
//	{
//		printf("λ�ò��Ϸ�\n");
//		return;
//	}
//	for (j = Ptrl->Last; j >= i - 1; j--)
//	{
//		Ptrl->Data[j + 1] = Ptrl->Data[j];
//	}
//	Ptrl->Data[i - 1] = x;
//	Ptrl->Last++;
//}
//
//void Delete(int i, List Ptrl)
//{
//	int j = 0;
//	if (i<1 || i>Ptrl->Last + 1)
//	{
//		printf("��������Ԫ��\n");
//		return;
//	}
//	for (j = i - 1; j < Ptrl->Last; j++)
//	{
//		Ptrl->Data[j] = Ptrl->Data[j + 1];
//	}
//	Ptrl->Last--;
//	return;
//}


//����
#define ElementType int
#include <stdio.h>
typedef struct LNode* List;
struct LNode
{
	ElementType Data;
	List Next;
};
struct LNode L;
List Ptrl;


int Length(List Ptrl)
{
	List p = Ptrl;  // pָ���ĵ�һ�����
	int j = 0;
	while (p)
	{
		p = p->Next;
		j++;
	}
	return j;
}
List FindKth(int K, List Ptrl)
{
	List p = Ptrl;
	int i = 1;
	while (p != NULL && i < K)
	{
		p = p->Next;
		i++;
	}
	if (i == K)
		return p;
	else
		return NULL;
}
List Find(ElementType x, List Ptrl)
{
	List p = Ptrl;
	while (p != NULL && p->Data != x)
	{
		p = p->Next;
	}
	return p;
}

List Insert(ElementType x, int i,List Ptrl)
{
	List p = Ptrl;
	List ps = (List)malloc(sizeof(struct LNode));  // �����½��
	ps->Data = x;
	int j = 0;
	if (i == 1)
	{
		ps->Next = p;
		return ps;
	}
	p = FindKth(i - 1, Ptrl);
	if (p == NULL)
	{
		printf("��������\n");
		return NULL;
	}
	// �ҵ������޸�Nextֵ
	ps->Next = p->Next;
	p->Next = ps;
	return Ptrl;
}

List Delete(int i, List Ptrl)
{
	List s,p;
	if (i == 1)
	{
		s = Ptrl;
		if (Ptrl != NULL)
		{
			Ptrl = Ptrl->Next;
		}
		else
			return NULL;
		free(s);
		return Ptrl;
	}
	p = FindKth(i - 1, Ptrl);
	if (p == NULL)
	{
		printf("��������\n");
		return NULL;
	}
	else if (p->Next == NULL)
	{
		printf("��������\n");
		return NULL;
	}
	s = p->Next;
	p->Next = s->Next;
	free(s);
	s = NULL;
	return Ptrl;
}