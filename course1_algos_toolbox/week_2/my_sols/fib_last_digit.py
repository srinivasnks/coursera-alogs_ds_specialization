# Using python 3


n = int(input())
fibArr = [None] * (n + 1)

def fillFibArr(n):
	for i in range(n + 1):
		if (i <= 1):
			fibArr[i] = i
		else:
			fibArr[i] = (fibArr[i - 1] + fibArr[i - 2]) % 10
	return fibArr[n]

fillFibArr(n)
print(fibArr[n])
