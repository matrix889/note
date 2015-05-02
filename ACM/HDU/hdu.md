[TOC]
### 动态规划
#### 1051 Zipper

1. 题目大意:
&emsp;&emsp;给出三个字符串,问前两个能不能在不改变各个字符相对位置的前提下,组成第三个字符.

2. 思路:
&emsp;&emsp;用dp[i][j]表示第一个字符串的前i个和第二个字符串的前j个,能不能组成第三个字符串的前i+j个前缀.
$$dp_{[i,j]} = dp_{[i-1,j]}{(a[i] == c[i+j])} &ensp; || &ensp; dp_{[i,j-1]}(b[j] == c[i+j])$$

3. Link:
[HDU 1501](http://acm.hdu.edu.cn/showproblem.php?pid=1501)

### 图论
#### 1599 find the mincost route

1. 题目大意：
&emsp;&emsp; 给出一个有n个顶点，n条边的无向图，求它的最小环。

2. 思路：
&emsp;&emsp;floyed求最小环模板题，需要注意的有两点，第一就是两个点之间可能不止一条边，第二就是，不能将INF设置为0x3f3f3f3f，因为这样INF*3之后超出了int的范围。

3. Link:
[HDU 1599](http://acm.hdu.edu.cn/showproblem.php?pid=1599)

### 思路题
#### 1759 Matrix Revolution

1. 题目大意：
&emsp;&emsp;对于一个矩阵A，求$A+A^2+\cdots+A^k$,(A为n*n的矩阵，A中的元素值$\leq$0,k>n)，求结果矩阵中有多少个非0元素。

2. 思路：
&emsp;&emsp;用矩阵来表示一个图，则矩阵A表示图中有没有长度两个点之间有没有长度为1的路径，$A^2$表示有没有长度为2的路径，$\cdots$以此类推，所以之间建图后，进行n次的bfs，即可求出答案。

3. Code:
[1759.cpp](1759.cpp)

4. Link:
[HDU 1759](http://acm.hdu.edu.cn/showproblem.php?pid=1759)
