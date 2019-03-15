#include<stdio.h>
void swap(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void insertion_sort(int a[], int size)
{
	int i,j, no;
	for(i=0;i<size;i++)
	{
		no = a[i];
		for(j=0;j<i;j++)
		{
			if(a[j]>no)
			{
				int temp;
				temp = a[j];
				a[j] = no;
				no = temp;
				//printf("%d %d", a[j], no);
			}
		}
	}
	printf("\nSorted array is:");
	for(i=0;i<size;i++)
	{
		printf("\n%d", a[i]);
	}
}

void main()
{
	int num, i;
	printf("\nEnter the size of array:");
	scanf("%d", &num);
	int arr[num], ele;
	printf("\nEnter the array elements:");
	for(i=0;i<num;i++)
	{
		scanf("%d", &ele);
		arr[i] = ele;
	}
	printf("\nThe array is:");
	for(i=0;i<num;i++)
	{
		printf("%d", arr[i]);
	}
	insertion_sort(arr,num);
}
