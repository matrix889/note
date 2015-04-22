**ZOJ**

---

[TOC]

### 数学

####  1037 Gridland

1. 题目大意：
&emsp;&emsp;从一个n*m的矩阵的任意点出发，走过其他全部点一次且仅走过一次，最后回到原点。求走过的最短距离。东西南北的方向上的距离为1，长度单位是欧几里德距离。

2. 思路：
当n或者m为偶数时，最短路长度为n*m;当n和m同时为奇数的时候，最短路为n*m-1+sqrt(2),因为至少要走过一个斜边。

```python
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

```