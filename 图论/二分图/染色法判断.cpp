//染色法判别二分图
	int n;		// n表示点数
	int h[N], e[M], ne[M], idx;		// 邻接表存储图
	int color[N];		// 表示每个点的颜色，-1表示为染色，0表示白色，1表示黑色

	// 参数：u表示当前节点，father表示当前节点的父节点（防止向树根遍历），c表示当前点的颜色
	bool dfs(int u, int father, int c)
	{
		color[u] = c;
		for (int i = h[u]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (color[j] == -1)
			{
				if (!dfs(j, u, !c)) return false;
			}
			else if (color[j] == c) return false;
		}
		
		return true;
	}

	bool check()
	{
		memset(color, -1, sizeof color);
		bool flag = true;
		for (int i = 1; i <= n; i ++ )
			if (color[i] == -1)
				if (!dfs(i, -1, 0))
				{
					flag = false;
					break;
				}
		return flag;
	}