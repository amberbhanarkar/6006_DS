def generateSubsequences(sequence):
	generateAllSubsequences(sequence,[],0)
	
def generateAllSubsequences(sequence, current_subsequence, index):
	if index==len(sequence):
		print(current_subsequence)
		return
	generateAllSubsequences(sequence, current_subsequence, index+1)
	current_subsequence.append(sequence[index])
	generateAllSubsequences(sequence, current_subsequence, index+1)
	current_subsequence.pop()

if __name__=="__main__":
	sequence = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
	generateSubsequences(sequence)
