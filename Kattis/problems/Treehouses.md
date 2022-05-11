# Treehouses
## URL

https://open.kattis.com/problems/treehouses



## Solution

### Approach 1:

我以为这是个最小生成树的问题(其实本质上也是)。目的是求连接各个连通分量的最小花费。我当最小生成的变体来做的。后来才发现好像应该用并查集，而且代码会简单很多(应该不到100行)。。。

下面的代码用的还是最小生成树来做的，边权就是边的长度，用优先队列存，循环终止条件是整个图都连通。有个bug de了很久，那个bug导致一个case WA了。就是在更新索引的同时，同时访问了那个被更新的值，感觉还是代码规范不够好。在用那个值的时候，要注意一下他有没有被改变，要用的值应该做表达式右值，如果每一处做左值了，那么就需要特别注意。

代码如下：

```c++
// Treehouses
// 最小生成树
// 好像用并查集做简单很多

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

// 顶点类
typedef struct node {
	double x;
	double y;
	int index;	// 节点所属的集合类，如果多个节点连通，定义他们的index为连通图中节点的最小index
	node(double x=0, double y=0, int index=0):x(x), y(y), index(index) {};
} node;

// 边类
typedef struct edge {
	int u;	// 端点index，这边要用index不要用类，就是数组下标，作用就是索引
	int v;	// 端点index，这边要用index不要用类，就是数组下标，作用就是索引
	double length;
	edge(int u=0, int v=0, double length=0):u(u), v(v), length(length) {};
} edge;

// 优先队列比较函数，小的边长优先
struct cmp {
	bool operator()(const edge e1, const edge e2) {
		return e1.length > e2.length;
	}
};

double min_length = 0;	// 记录全局最优

// 声明
bool check_connectivity(node* nodes, int n);
void MST(node* nodes, vector<edge>& edges, int n);

// 检查所有子图的连通性
bool check_connectivity(node* nodes, int n) {
	for(int i=1; i<=n; i++) {
		if(nodes[i].index != nodes[1].index)
			return false;
	}

	return true;
}

// 最小生成树
void MST(node* nodes, vector<edge>& edges, int n) {
	priority_queue<edge, vector<edge>, cmp> q(edges.begin(), edges.end());
	edge e;
	int index;
	int l_index, r_index;
	// 终止条件是形成连通图
	while(!check_connectivity(nodes, n)) {
		e = q.top();
		// 这里做一次检查是因为，每次的更新可能会让原本在两个子图的节点变为一个子图里面的节点
		if(nodes[e.u].index == nodes[e.v].index) {
			q.pop();
			continue;
		}
		min_length += e.length;
		// 这边要提前存下来，因为我在这里发现了一个bug。。。我一边更新一边索引的话就出了bug
		l_index = nodes[e.u].index;
		r_index = nodes[e.v].index;
		index = min(l_index, r_index);
		// 更新节点所属集合
		for(int i=1; i<=n; i++) {
			if(nodes[i].index == l_index || nodes[i].index == r_index)
				nodes[i].index = index;
		}
		q.pop();
	}

	return;
}

int main() {
	int n, e, p;
	int n1, n2;
	int min_index;
	double x, y;
	int l_index, r_index;
	cin >> n >> e >> p;
	node* nodes = new node[n+1];
	// 这些节点是在同一个连通子图里的
	for(int i=1; i<=e; i++) {
		cin >> x >> y;
		nodes[i].x = x;
		nodes[i].y = y;
		nodes[i].index = 1; // 前面e个是已经连通的，index记录为1
	}
	// these nodes are isolated with each other
	for(int i=e+1; i<=n; i++) {
		cin >> x >> y;
		nodes[i].x = x;
		nodes[i].y = y;
		nodes[i].index = i; // 后面(n-e)个初始化为节点序
	}
	// 处理p对连通的节点
	for(int i=0; i<p; i++) {
		cin >> n1 >> n2;
		// 同一个bug
		l_index = nodes[n1].index;
		r_index = nodes[n2].index;
		min_index = min(l_index, r_index);
		for(int j=1; j<=n; j++) {
			if(nodes[j].index==l_index || nodes[j].index==r_index)
				nodes[j].index = min_index;
		}
	}
	// 至此输入已经处理完成
	vector<edge> edges;
	double length;
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			if(nodes[i].index==nodes[j].index)
				continue;
			length = sqrt((nodes[i].x-nodes[j].x)*(nodes[i].x-nodes[j].x) + (nodes[i].y-nodes[j].y)*(nodes[i].y-nodes[j].y));
			edges.push_back(edge(i,j,length));
		}
	}
	// 调用最小生成树函数
	MST(nodes, edges, n);

	cout << min_length << endl;

	return 0;
}
```


