#include<stdio.h>

/*
���η��������Сֵ
*/
void SearchMaxAndMin(int *arr,int start,int end,int *min,int *max)
{
	if(arr == NULL)
		return;
	if(end-start <=1)
	{
		if(arr[start]>arr[end])
		{
			*max = arr[start];
			*min = arr[end];
		}
		else
		{
			*max = arr[end];
			*min = arr[start];
		}
		return;
	}

	int maxL,minL;
	int maxR,minR;
	SearchMaxAndMin(arr,start,(start+end)>>1,&minL,&maxL);    //����������Сֵ
	SearchMaxAndMin(arr,((start+end)>>1)+1,end,&minR,&maxR);  //���ұ������Сֵ

	if(maxL>maxR)
		*max = maxL;
	else
		*max = maxR;
	if(minL<minR)
		*min = minL;
	else
		*min = minR;
}

int main()
{
	int min,max;
	int arr[9] = {4,3,0,9,1,5,-3,8,2};
	SearchMaxAndMin(arr,0,8,&min,&max);
	printf("%d %d\n",min,max);
	return 0;
}