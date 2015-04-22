#!/usr/bin/python
# Filename: 1037.py
import math
t = int(raw_input(""))

for i in range(0, t):
	n = raw_input().split()
	print "Scenario #%d:" % (i + 1)
	if int(n[0]) % 2 == 1 and int(n[1]) % 2 == 1:
		print "%.2f\n" % float(int(n[0]) * int(n[1]) - 1 + math.sqrt(2))
	else:
		print "%.2f\n" % float(int(n[0]) * int(n[1])) 
