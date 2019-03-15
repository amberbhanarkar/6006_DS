#include<stdio.h>

int peak_finding(int a1[],int n, int low, int high)
{
	low = 0;
	high = n;
	int mid = n/2;
	if(a1[mid-1]>a1[mid])
	{
		peak_finding(a1[], mid, low, mid-1);
		return mid;
	}
	else if(a1[mid-1]<a1[mid])
	{
		peak_finding(a1[], mid, mid+1, high);
		return mid;
	}
	else
	{
		return mid;
	}
}

void main()
{
	int num, i, size;
	printf("\nEnter the sixe of array:");
	scanf("%d", &size);
	int a[size];
	printf("\nEnter the array elements:");
	for(i=0;i<size;i++)
	{
		scanf("%d", &num);
		a[i] = num;
	}
	int low = 0, high = size;
	printf("\nOur array is:");
	for(i=0;i<size;i++)
	{
		printf("%d", a[i]);
	}
	peak_finding(a[],size,low,high);
}


		
	
