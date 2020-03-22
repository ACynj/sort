#include<stdio.h>
#include<stdlib.h>
/*�鲢����-�ݹ�ʵ��*/
/*L=�����ʼ��λ�ã�R=�ұ���ʼ��λ�ã�RightEnd=�ұ��յ�λ��*/
void Merge(int A[],int TmpA[],int L,int R,int RightEnd) {
	/*�������A[L]~A[R-1]��A[R]~A[RightEnd]�鲢��һ����������*/
	int LeftEnd, NumElements, Tmp;
	int i;
	LeftEnd = R - 1;/*����յ�λ��*/
	Tmp = L;/*�������е���ʼλ��*/
	NumElements = RightEnd - L + 1;
	while (L <= LeftEnd && R <= RightEnd) {
		if (A[L] <= A[R]) {
			TmpA[Tmp++] = A[L++];/*������ֵ��С�������Ԫ�ظ��Ƶ�TmpA*/
		}
		else TmpA[Tmp++] = A[R++];

	}
	while (L <= LeftEnd)
	{
		TmpA[Tmp++] = A[L++];/*����ʣ�µ����Ԫ��*/
	}
	while (R <= RightEnd)
	{
		TmpA[Tmp++] = A[R++];
	}
	for (i = 0; i < NumElements; i++,RightEnd--){
		A[RightEnd] = TmpA[RightEnd];/*�������TmpA���ƻ�A*/
	}
}
void Msort(int A[], int TmpA[], int L, int RightEnd) {
	/*���ĵݹ�������*/
	int center;
	if (L < RightEnd) {
		center = (L + RightEnd) / 2;
		Msort(A, TmpA, L, center);/*�ݹ������*/
		Msort(A, TmpA, center + 1, RightEnd);/*�ݹ����ұ�*/
		Merge(A, TmpA, L, center + 1, RightEnd);/*�ϲ�������������*/
	}
}
void MergeSort(int A[],int N) {
	/*�鲢����*/
	int* TmpA;
	TmpA = (int*)malloc(N * sizeof(int));
	if (TmpA != NULL) {
		Msort(A, TmpA, 0, N - 1);
		free(TmpA);
	}
	else printf("�ռ䲻��");
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