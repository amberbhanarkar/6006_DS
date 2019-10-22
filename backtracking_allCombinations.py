def printCombination(arr,n,r):
	data = [0]*r
	combinationUtil(arr,n,r,0,data,0)
	
def combinationUtil(arr,n,r,index,data,i):
	if index==r:
		for j in range(r):
			print(data[j], end=" ")
		print()
		return
	if i>=n:
		return
		
	data[index]=arr[i]
	combinationUtil(arr,n,r,index+1,data,i+1)
	while (arr[i] == arr[i+1]):
        	i=i+1 
	combinationUtil(arr,n,r,index,data,i+1)


if __name__=="__main__":
	lis = []
	n = int(input())
	while n>0:
		y = int(input())
		lis.append(y)
		n=n-1
	r = int(input())
	printCombination(lis,n,r)
