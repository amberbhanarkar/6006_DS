def String(lis):
	return ''.join(lis)
	
def permute(a,l,r):
	if l==r:
		print(String(a))
	else:
		for i in range(l,r+1):
			a[l],a[i]=a[i],a[l]
			permute(a,l+1,r)
			a[l],a[i]=a[i],a[l]
			
if __name__=="__main__":
	n = int(input())
	lis = []
	while n>0:
		n = n-1
		y = input()
		lis.append(y)
	n = len(lis)
	permute(lis,0,n-1)
