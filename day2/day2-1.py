with open('file.txt', 'r') as f:
    my_list = f.read().splitlines()

depth = 0
forward = 0

for line in my_list:
	if "down" in line:
		line = line.split(" ")
		depth += int(line[1])
	elif "up" in line:
		line = line.split(" ")
		depth -= int(line[1])
	elif "forward" in line:
		line = line.split(" ")
		forward += int(line[1])
print(f"depth = {depth} & forward = {forward}\nMultiplied it is {depth * forward}")