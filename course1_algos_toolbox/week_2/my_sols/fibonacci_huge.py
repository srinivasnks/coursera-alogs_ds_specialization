# Uses python3


def get_fibonaccihuge(n, m):
	pisano_list = []
	fib_list = []
	fib_num = 0
	# Create a list and insert till Pisano patter is seen
	pattern_found = False
	while(pattern_found != True):
		# add_to_fib_list(fib_num - 1)
		if ((fib_num) <= 1):
			fib_list.append(fib_num)
			pisano_list.append(fib_list[fib_num] % m)
		else:
			new_fib_num = (((fib_list[0] % m) + (fib_list[1] % m)) % m)
			fib_list[0] = fib_list[1]
			fib_list[1] = new_fib_num
			#pisano_list.append(fib_list[1] % m)
			pisano_list.append(fib_list[1])
		if (fib_num > 2):
			# Check for pattern here
			if (pisano_list[fib_num] == 1 and pisano_list[fib_num - 1] == 0):
				pattern_found = True
				break
		if (fib_num >= n):
			return (fib_list[1] % m)
		fib_num += 1
	# We found the pattern. Now get the length and return the mod from pisano list
	pattern_len = len(pisano_list) - 2 # we discard the last '0 1' in the pattern
	return pisano_list[n % pattern_len]

n, m = map(int, input().split())
print(get_fibonaccihuge(n, m))
