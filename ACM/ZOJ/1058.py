#!/usr/bin/python
# Filename: 1058.py

def readline():
	s = raw_input()
	while len(s) == 0:
		# print s
		s = raw_input()
	return s

t1 = int(readline())
while t1 > 0:
	a = []
	t1 = t1 - 1
	# print "wha %d" % t1
	for i in range(0, 5):
		b = map(float, readline().split())
		a.append(b)

	while 1:
		t = readline().split()
		n = int(t[0])
		if n == 0:
			break
		m = float(t[n + 1])
		m = m * a[0][int(t[1])-1]
		m = int(m * 100 + 0.5)
		m /= 100.0

		for i in range(1, n):
			l = int(t[i])
			r = int(t[i+1])
			rad = a[l-1][r-1]
			m = m * rad
			m = int(m * 100 + 0.5)
			m /= 100.0
		m = m * a[int(t[n])-1][0]
		m = int(m * 100 + 0.5)
		m /= 100.0

		print "%.2f" % m
	if t1 > 0:
		print