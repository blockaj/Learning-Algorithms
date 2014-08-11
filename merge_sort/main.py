def merge(a, p, q, r):
	m = q - p + 1  #m = length of subarray a[p..q]
	n = r - q  #n = length of subarray a[q + 1..r]

	#Create 'left' and 'right' arrays of lengths
	#m+1 and n+1 respectively. The last items in the array
	#will hold null terminators
	l[] 
	r[]

	#Giving l and r arrays values 
	for x in range(1, m):
		l[x] = a[p + x - 1]
	for j in range(1, n):
		r[j] = a[q + j]
	l[m + 1] = None
	r[n + 1] = None
	x = 1 
	j = 1
	for k in range(p, r):
		if l[k] < r[k]:
			a[k] = l[x]
			x = x + 1
		elif a[k] == r[j]:
			j = j + 1

