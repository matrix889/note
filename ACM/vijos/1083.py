#!/usr/bin/python
# Filename: 1083.py

g = [[] for i in range(100010)]
vis = [0 for i in range(100010)]

def bfs(x):
	global ans
	queue = [x]
	vis[x] = 1
	while len(queue) > 0:
		u = queue[0]
		del queue[0]
		# print u
		for i in range(0, len(g[u])):
			v = g[u][i]
			if vis[v] != 0:
				continue;
			vis[v] = vis[u] + 1
			if vis[v] > ans:
				ans = vis[v]
			queue.append(v)

ans = 0
a = raw_input().split()
m = int(raw_input())
for i in range(0, int(a[1])):
	v = raw_input().split()
	g[int(v[0])].append(int(v[1]))
	g[int(v[1])].append(int(v[0]))
bfs(int(a[2]))
print ans + m