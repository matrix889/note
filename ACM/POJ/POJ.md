[TOC]

### 思路题：

#### 1.Ugly Numbers

* 题目大意：求出第n个质因子只有2,3,5的数字。

* 思路：用一个数组pre[j]表示到当前为止，乘上因子num[j]的数字对应位置的下一个位置，每一次取出Ans[i] = min(num[j]*Ans[pre[j]]),然后，对于所有的num[j]*Ans[pre[j]] == Ans[i],更新为pre[j]+1。
