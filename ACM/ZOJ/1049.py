#!/usr/bin/python
# Filename: 1049.py

import math

t = int(raw_input())

for i in range(0, t):
	a = raw_input().split()
	b = (float(a[0]) * float(a[0]) + float(a[1]) * float(a[1])) * math.pi / 100.0
	print "Property %d: This property will begin eroding in year %d." % (i+1, math.ceil(b))
print "END OF OUTPUT."

