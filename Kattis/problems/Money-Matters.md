# Money Matters
## URL

https://open.kattis.com/problems/moneymatters



## Solution

### Approach 1:

开始想用索引数组直接解决，发现无论如何都要判断是否属于同一个集合，这样就会增加时间复杂度，每次检查存在于哪个集合，缺少一个合适的key来做集合的跟从而做哈希优化。最后没办法，回归图论，问题本质就是对无向图中的各个连通分量求和，若每个连通分量的和分别都为0，那么就输出possible，否则输出impossbile，DFS遍历各个连通分量即可，因为对图的深度遍历还不是很熟悉，写了挺久。并查集跟第一种策略类似，因为根节点是无规律的，并查也容易造成冗余的时间复杂度。

代码如下：

```c++
// Money Matters

#include <iostream>

using namespace std;

// return the summation of the connected component
int DFS(int s, int n, bool *visited, int **p, int *money) {
	int sum = money[s];
	for(int i=0; i<n; i++) {
		if(!visited[i] && p[s][i]) {
			visited[i] = true;
			sum += DFS(i, n, visited, p, money);
		}
	}

	return sum;
}

int main() {
	int n, m;
	cin >> n >> m;
	int **p = new int*[n];
	for(int i=0; i<n; i++) {
		p[i] = new int[n];
	}
	int *money = new int[n];
	bool *visited = new bool[n];
	int count;
	for(int i=0; i<n; i++) {
		cin >> money[i];
		visited[i] = false;
	}
	for(int i=0; i<m; i++) {
		int l, r;
		cin >> l >> r;
		p[l][r] = 1;
		p[r][l] = 1;
	}
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			visited[i] = true;
			int cur_sum = DFS(i, n, visited, p, money);
			if (cur_sum != 0) {
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
		}
	}

	cout << "POSSIBLE" << endl;

	return 0;
}
```


