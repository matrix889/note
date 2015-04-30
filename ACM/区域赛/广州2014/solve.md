[TOC]

### E.Song Jiang’s rank list 

#### 题目大意：
给出n个将领的杀敌数和名字的拼音，将他们按照杀敌数，名字的字典序排列。

#### 思路：
直接模拟即可。

#### Link: 
[HDU 5131](http://acm.hdu.edu.cn/showproblem.php?pid=5131)

### I.Little Zu Chongzhi’s Triangles

#### 题目大意：
给出n个点，从中取出若干个点，组成若干个三角形，使得最后的总面积最大（n <= 12）。

#### 思路1：
DFS+剪枝,枚举每一条边被放到了哪一个三角形中。一个很重要的剪枝就是，保证第一个三角形的第一条边的ID要比第二个三角形的第一条边的ID大。

#### 思路2：
状态压缩DP,首先预处理出所有可能的三角形的面积大小。然后用转移方程 dp[state | state_triangle[i]] = max(dp[state] + dp[state_triangle[i])，最后,ans = max(dp[state])。

#### Link:
[HDU 5135](http://acm.hdu.edu.cn/showproblem.php?pid=5135)

### K.How Many Maos Does the Guanxi Worth

#### 题目大意：
给出n个点，m条边，求去掉某个点之后的1到n的最短路。

#### 思路：
因为n<=30,所以直接枚举去掉的点，求出最短路即可。

#### Link：
[HDU 5137](http://acm.hdu.edu.cn/showproblem.php?pid=5137)
