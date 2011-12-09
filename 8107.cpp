#include <stdio.h>
#include <string.h>
#define LEN 101
 
int map[LEN][LEN], ret[LEN];
 
/* 拓扑排序 */
int toposort(int (*map)[LEN], int *ret, const int len)
{
	int i, j, k, cnt, pre[LEN];
 
	cnt = 0;							/* 统计 */
	for (i = 1; i <= len; ++i)			/* 统计每个点的入度 */
	{
		pre[i] = 0;
		for (j = 1; j <= len; ++j)		/* 累加入度 */
		{
			pre[i] += map[j][i];
		}
		if (pre[i] == 0)
		{
			++cnt;
		}
	}
 
	if (cnt == 0)						/* 没有入度为零的点, 无拓扑序列 */
	{
		return 0;
	}
 
	for (k = 1; k <= len; ++k)
	{
		for (i = 1; i <= len; ++i)
		{
			if (pre[i] == 0)
			{
				break;
			}
		}
 
		if (i > len)
		{
			return 0;
		}
 
		ret[k] = i;
		pre[i] = -1;				/* 删除点 i */
		for (j = 1; j <= len; ++j)	/* 减少其候点的入度 */
		{
			pre[j] -= map[i][j];
		}
	}
 
	return 1;
}
 
int main()
{
	int len, n, src, dest, flg;
 
	while (scanf("%d%d", &len, &n), len)
	{
		memset(map, 0, sizeof(map));
		while (n--)
		{
			scanf("%d%d", &src, &dest);
			++src;
			++dest;
			map[src][dest] = 1;
		}
 
		flg = toposort(map, ret, len);
		printf("%s\n", flg ? "YES" : "NO");
	}
 
	return 0;
}
