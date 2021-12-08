with open('file.txt', 'r') as f:
    my_list = f.read().splitlines()

for j in range(1):
	one = 0
	zero = 0
	for i in my_list:
		if i[0] == '0' :
			zero += 1
		elif i[0] == '1':
			one += 1
	if zero <= one and not zero == 0:
		print("0", end='')
	elif zero > one:
		print("1", end='')


#001010001110 654

#110101110001 3441

# print(654 * 3441)

#011110001111 967

#110001001100 1574

#011110001111 1935
#110001001100 3148
#1100010011
#110001001001
# print(3145 * 1935)