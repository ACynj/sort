#include<stdio.h>
#include<stdlib.h>
/*归并排序-递归实现*/
/*L=左边起始点位置，R=右边起始点位置，RightEnd=右边终点位置*/
void Merge(int A[],int TmpA[],int L,int R,int RightEnd) {
	/*将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列*/
	int LeftEnd, NumElements, Tmp;
	int i;
	LeftEnd = R - 1;/*左边终点位置*/
	Tmp = L;/*有序序列的起始位置*/
	NumElements = RightEnd - L + 1;
	while (L <= LeftEnd && R <= RightEnd) {
		if (A[L] <= A[R]) {
			TmpA[Tmp++] = A[L++];/*如果左边值更小，将左边元素复制到TmpA*/
		}
		else TmpA[Tmp++] = A[R++];

	}
	while (L <= LeftEnd)
	{
		TmpA[Tmp++] = A[L++];/*复制剩下的左边元素*/
	}
	while (R <= RightEnd)
	{
		TmpA[Tmp++] = A[R++];
	}
	for (i = 0; i < NumElements; i++,RightEnd--){
		A[RightEnd] = TmpA[RightEnd];/*将有序的TmpA复制回A*/
	}
}
void Msort(int A[], int TmpA[], int L, int RightEnd) {
	/*核心递归排序函数*/
	int center;
	if (L < RightEnd) {
		center = (L + RightEnd) / 2;
		Msort(A, TmpA, L, center);/*递归解决左边*/
		Msort(A, TmpA, center + 1, RightEnd);/*递归解决右边*/
		Merge(A, TmpA, L, center + 1, RightEnd);/*合并两段有序序列*/
	}
}
void MergeSort(int A[],int N) {
	/*归并排序*/
	int* TmpA;
	TmpA = (int*)malloc(N * sizeof(int));
	if (TmpA != NULL) {
		Msort(A, TmpA, 0, N - 1);
		free(TmpA);
	}
	else printf("空间不足");
}
int main() {
	int A[100];
	int N;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &A[i]);
	}
	MergeSort(A, N);
	for (int i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}

}