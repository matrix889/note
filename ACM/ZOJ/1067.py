#!/usr/bin/python
# Filename: 1067.py

l = []
for i in range(0, 16):
	l.append(map(int, raw_input().split()))

def sqr(x):
	return x * x
while 1:
	r = map(int, raw_input().split())
	if r[0] == -1 and r[1] == -1 and r[2] == -1:
		break
	ans = 2 ** 30
	pos = -1

	for i in range(0, 16):
		tmp = sqr(r[0]-l[i][0]) + sqr(r[1]-l[i][1]) + sqr(r[2]-l[i][2])
		if ans > tmp:
			ans = tmp
			pos = i
	print "(%d,%d,%d) maps to (%d,%d,%d)" %(r[0], r[1], r[2], l[pos][0], l[pos][1], l[pos][2])


