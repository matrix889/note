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
