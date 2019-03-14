#include<stdio.h>
#include<stdlib.h>

void swap(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void max_heapify(int a[], int n, int i)
{
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;
	
	if(left<n && a[left]>a[largest])
	{
		largest = left;
	}
	if(right<n && a[right]>a[largest])
	{
		largest = right;
	}
	if(largest!=i)
	{
		swap(a[i], a[largest]);
		max_heapify(a,n,largest);
	}
}

void heapsort(int a[], int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	{
		max_heapify(a,n,i);
	}
	for(i=n-1;i>=0;i++)
	{
		swap(a[0],a[i]);
		max_heapify(a,i,0);
	}
}

void print(int a[], int n)
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d", a[i]);
	}
}

void main()
{	
	int num, i;
	printf("\nEnter the size of array:");
	scanf("%d", &num);
	int arr[num], ele;
	printf("\nEnter the elements in array:");
	for(i=0;i<num;i++)
	{
		scanf("%d", &ele);
		arr[i] = ele;
	}
	printf("\nUnsorted heap array is:");
	for(i=0;i<num;i++)
	{
		printf("%d", arr[i]);
	}
	heapsort(arr,num);
	print(arr,num);
}
