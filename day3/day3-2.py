with open('file.txt', 'r') as f:
    my_list = f.read().splitlines()

for line in my_list:
	if line == "1":
		print(line)