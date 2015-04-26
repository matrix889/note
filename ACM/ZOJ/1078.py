#!/usr/bin/python
# Filename: 1078.py

def ok(base, x):
	num = []
	while x > 0:
		num.append(x % base)
		x /= base
	l = len(num)
	
	for i in range(0, l):
		if num[i] != num[l-i-1]:
			return 0;
	return 1

while 1:
	x = int(raw_input())
	if x == 0:
		break

	ok_base = []
	for i in range(2, 17):
		if ok(i, x) == 1:
			ok_base.append(i)

	if len(ok_base) == 0:
		print "Number %d is not a palindrom" %x
		continue
	print "Number %d is palindrom in basis"	% x,
	for i in range(0, len(ok_base)):
		if i < len(ok_base) - 1:
			print "%d" % ok_base[i],
		else:
			print "%d" %ok_base[i]
