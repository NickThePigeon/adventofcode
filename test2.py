with open('passport_file.txt', 'r') as f:
    my_list = f.read()

array = my_list.split('\n')

pass_count = 0

passport

for i in array:
	if i[0] != '\n':
		passport[pass_count] = i
	else:
		pass_count += 1

print(passport[0])