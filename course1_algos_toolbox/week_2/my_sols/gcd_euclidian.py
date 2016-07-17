# Uses python3

def gcd(a, b):
	if (b == 0):
		return a
	else:
		cur_remainder = a % b
		return gcd(b, cur_remainder)
		

a, b = map(int, input().split())
if (a > b):
	result = gcd(a, b)
else:
	result = gcd(b, a)
print(result)
