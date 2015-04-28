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

### 数据结构

#### 3635 Cinema in Akiba

1. 题目大意：
&emsp;&emsp;有一排座位共N个，然后有N个人，每次给一个xi，从左到右数到第xi个空位，这个空位就安排给第i个人，接着就有一系列询问要找第i个人的位置。

2. 思路：
&emsp;&emsp;用线段树或者树状数组维护前n个位置中有多少个位置已经被占用，容易得到，n个位置中空位的个数单调递增，因此，二分每个人分配到的座位号即可。

3. Link: [ZOJ 3635](acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=4803)
