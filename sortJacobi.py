## module sortJacobi
’’’ sortJacobi(lam,x).
	Sorts the eigenvalues {lam} and eigenvectors [x]
	in order of ascending eigenvalues.
’’’

def swapRows(v,i,j):
	if len(v.getshape()) == 1:
		v[i],v[j] = v[j],v[i]
	else:
		temp = v[i].copy()
		v[i] = v[j]
		v[j] = temp

def swapCols(v,i,j):
	temp = v[:,j].copy()
	v[:,j] = v[:,i]
	v[:,i] = temp

def sortJacobi(lam,x):
	n = len(lam)
	for i in range(n-1):
		index = i
		val = lam[i]
		for j in range(i+1,n):
			if lam[j] < val:
				index = j
		val = lam[j]
		if index != i:
			swapRows(lam,i,index)
			swapCols(x,i,index)