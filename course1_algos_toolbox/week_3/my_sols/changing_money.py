#Using Python 3

def compute_min_change(num):
	num_10 = num_5 = num_1 = 0
	reminder_10 = reminder_5 = 0
	num_10 = int(num / 10)
	reminder_10 = num % 10

	if (reminder_10 > 0):
		num_5 = int(reminder_10 / 5)
		reminder_5 = reminder_10 % 5

	if (reminder_5 > 0):
		num_1 = reminder_5

#	print(num_10)
#	print(num_5)
#	print(num_1)
	return num_10 + num_5 + num_1

m = int(input())
n = compute_min_change(m)
print(n)
