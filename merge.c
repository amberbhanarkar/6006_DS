#include<stdio.h>

void merge(int a[], int low, int mid, int high)
{
	int i, j, k;
	int n1 = mid-low+1;
	int n2 = high-mid;
	int a1[n1], a2[n2];
	for(i=0;i<n1;i++)
	{
		a1[i] = a[low+i];
	}
	for(j=0;j<n2;j++)
	{
		a2[j] = a[mid+j+1];
	}
	
	i=0;j=0;k=low;
	while(i<n1 && j<n2)
	{
		if(a1[i]>a2[j])
		{
			a[k] = a2[j];
			j++;
		}
		else
		{
			a[k] = a1[i];
			i++;
		}
		k++;
	}
	
	while(i<n1)
	{
		a[k] = a1[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k] = a2[j];
		j++;
		k++;
	}
}

void mergesort(int a[],int low, int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;
		mergesort(a,low, mid);
		mergesort(a,mid+1,high);
		merge(a,low, mid, high);
	}
}

void print(int a[], int size)
{
	int i;
	printf("\nSorted list is:");
	for(i=0;i<size;i++)
	{
		printf("%d",a[i]);
	}
}

void main()
{
	int num, i, ele;
	printf("\nEnter the size of array:");
	scanf("%d", &num);
	int arr[num];
	printf("\nEnter the array elements:");
	for(i=0;i<num;i++)
	{
		scanf("%d", &ele);
		arr[i] = ele;
	}
	printf("\nUnsorted array is:");
	for(i=0;i<num;i++)
	{
		printf("%d", arr[i]);
	}
	mergesort(arr,0,num-1);
	print(arr,num);
}
	 
