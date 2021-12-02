with open('file.txt', 'r') as f:
    my_list = f.read().splitlines()

aim = 0
forward = 0
depth = 0

for line in my_list:
	if "down" in line:
		line = line.split(" ")
		aim += int(line[1])
	elif "up" in line:
		line = line.split(" ")
		aim -= int(line[1])
	elif "forward" in line:
		line = line.split(" ")
		forward += int(line[1])
		depth += aim * int(line[1])
print(f"depth = {depth} & forward = {forward}\nMultiplied it is {depth * forward}")