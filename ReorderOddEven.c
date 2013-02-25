/*======================面试题====================
 调整数组顺序使奇数位于偶数前面
 */

#include <stdio.h>

void swap(int* a,int *b){
	int tmp=*a;
	*a = *b;
	*b =tmp;
}

void ReorderOddEven(int * pData,unsigned int length){

	if(pData==NULL || length == 0)
		return;
	int *pBegin = pData;

	int *pEnd = pData+length -1;

	while (pBegin< pEnd)
	{
		while (pBegin<pEnd && (*pBegin&0x1)!=0)
		{
			pBegin++;
		}

		while (pBegin<pEnd && (*pEnd &0x1)==0)
		{
			pEnd --;
		}

		if (pBegin<pEnd)
		{
			swap(pBegin,pEnd);
		}
	}

}

void print(int * pData,int length){
	for (int i =0;i<length;i++)
	{
		printf("%d ",pData[i]);
	}
	printf("\n");
}

int main(){
	int a[5]={1,2,3,4,5};
	ReorderOddEven(a,5);
	print(a,5);

}