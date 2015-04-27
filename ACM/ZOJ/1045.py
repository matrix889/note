#!/usr/bin/python
# Filename: 1045.py

def sgn(x):
	eps = 0.0001
	m = 0
	if x > eps:
		m = 1
	elif x < -eps:
		m = -1
	else:
		m = 0
	return m

while 1:
	a = float(raw_input())
	if sgn(a) == 0:
		break
	b = 0.0
	n = 2
	while b < a:
		b += 1.00 / n 
		# print n
		n = n + 1
	print "%d card(s)" % (n - 2)
