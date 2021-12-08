file = open("text.txt", "r")
my_file = file.read().splitlines()

ret = 0
alpha = 0
i = 0
old_i = 0
holder = 0
answer = 0
old_answer = 554

for i in range(1998):
	answer = int(my_file[i])
	for j in range(2):
		holder = int(my_file[i + j + 1])
		answer += holder
		if j == 1:
			if answer > old_answer:
				ret += 1
			old_answer = answer
print(ret)