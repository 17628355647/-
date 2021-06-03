#define _CRT_SECURE_NO_WARNINGS 1

//写个程序实现函数PrintN，使得输入一个正整数N，打印1到N的全部正整数。

//#include <stdio.h>
//#include <time.h>
//void PrintN1(int n)  // 方法1，循环实现
//{
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		printf("%d ", i);
//	}
//}
//void PrintN2(int n)  // 方法2，递归实现。递归，对空间的占用，有的时候非常恐怖。
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
//	printf("请输入：");
//	scanf("%d", &n);
//	clock_t start, stop;  // 创建变量，记录时间打点数
//	double shijian;     // 这个变量记录时间
//	start = clock();   // 记录开始时间打点数
//	PrintN2(n);
//	stop = clock();    // 记录结束时间打点数
//	shijian = (double)((stop - start) / CLK_TCK);   // 用打点数相减，除以每秒打点数。得到总时间，单位秒
//	printf("\n%lf\n", shijian);
//}



// 写程序计算给定多项式在给定点x处的值。
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
//		arr[i] = (double)i;  // 数组初始化
//	}
//	start = clock();
//	for (i = 0; i < 10000000; i++)
//	{
//		f1(MAX - 1, arr, 1.1);   
//// 之所以要运行那么多次，是因为，f1和f2两个函数都运行的很快，clock()函数无法捕捉到ticks的变化。所以重复的多次充分运行，
//// 使得测出的总的时钟打点间隔充分长，最后计算被测函数平均每次运行时间即可。
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





// 选择排序算法的伪码描述
//void SelectionSort(int List[], int N)
//{
//	// 将N个整数List[0].....List[N-1] 进行非递减排序
//	for (int i = 0; i < N; i++)
//	{
//		//从List[i]到List[N - 1]中找最小元，并将其位置赋给MinPosition;
//		int MinPosition = ScanForMin(List, i, N - 1);
//		//将未排序部分的最小元换到有序部分的最后位置;
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





//// 算法1
//int MaxSubseqsum1(int A[], int N)
//{
//	int ThisSum, MaxSum = 0;
//	int i, j, k;
//	for (i = 0; i < N; i++)   // i是子列左端位置
//	{
//		for (j = i; j < N; j++)  // j是子列右端位置
//		{
//			ThisSum = 0;    // ThisSum保存A[i]到A[j]的子列和
//			for (k = i; k <= j; k++)
//			{
//				ThisSum += A[k];
//				if (ThisSum > MaxSum)   // 如果刚得到的结果大于MaxSum，就替换
//				{
//					MaxSum = ThisSum;
//				}
//			}
//		}
//	}
//	return MaxSum;
//}
//// 这个算法的复杂度：T()
//
//// 算法2
//int MaxSubseqsum1(int A[], int N)
//{
//	int ThisSum, MaxSum = 0;
//	int i, j, k;
//	for (i = 0; i < N; i++)   // i是子列左端位置
//	{
//		ThisSum = 0;    // ThisSum保存A[i]到A[j]的子列和
//		for (j = i; j < N; j++)  // j是子列右端位置
//		{
//			ThisSum += A[j];
//			if (ThisSum > MaxSum)   // 如果刚得到的结果大于MaxSum，就替换
//			{
//				MaxSum = ThisSum;
//			}
//		}
//	}
//	return MaxSum;
//}
//// 这个算法的复杂度：T()
//
//int MaxSubseqsum1(int A[], int N)
//{
//	int ThisSum, MaxSum;
//	int i;
//	ThisSum = MaxSum = 0;
//	for (i = 0; i < N; i++)
//	{
//		ThisSum += A[i];   // 向右累加
//		if (ThisSum > MaxSum)
//			MaxSum = ThisSum;  // 发现更大和则更新当前结果
//		else if (ThisSum < 0) // 如果当前子列和为负，则不可能使后面部分增大，抛弃之。
//			ThisSum = 0;
//	}
//}


// 数组存储
//#define MAXSIZE 100
//typedef int ElementType;  // 假设数组每个元素为int型
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
//	ElementType Data[MAXSIZE];   // 存放数据的数组
//	int Last;  // 记录数组最后一个元素所在位置
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
//		return -1;  // 没有找到返回-1
//	else
//		return i;  // 找到就返回存储位置
//}
//
//void Insert(ElementType x, int i, List Ptrl)
//{
//	int j;
//	if (Ptrl->Last == MAXSIZE - 1)
//	{
//		printf("表满了，无法插入\n");
//		return;
//	}
//	if (i<1 || i>Ptrl->Last + 2)
//	{
//		printf("位置不合法\n");
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
//		printf("不存在这元素\n");
//		return;
//	}
//	for (j = i - 1; j < Ptrl->Last; j++)
//	{
//		Ptrl->Data[j] = Ptrl->Data[j + 1];
//	}
//	Ptrl->Last--;
//	return;
//}


//链表
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
	List p = Ptrl;  // p指向表的第一个结点
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
	List ps = (List)malloc(sizeof(struct LNode));  // 构造新结点
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
		printf("参数错误\n");
		return NULL;
	}
	// 找到结点后，修改Next值
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
		printf("参数有误\n");
		return NULL;
	}
	else if (p->Next == NULL)
	{
		printf("参数有误\n");
		return NULL;
	}
	s = p->Next;
	p->Next = s->Next;
	free(s);
	s = NULL;
	return Ptrl;
}