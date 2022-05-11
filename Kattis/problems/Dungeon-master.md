# Dungeon master
## URL

https://open.kattis.com/problems/dungeon



## Solution

### Approach 1:

最先开始用的DFS，后来不管怎么剪枝怎么优化都在第二个点卡TLE。果然深度比较大的时候不太适合用DFS来做，递归深度太深了。后来改成BFS，简单的BFS也会TLE，注意也要剪枝优化一下，优化位置不对也会TLE，正确位置是在每个candidate入队之前，进行访问标记，然后下面就不会重复让这个点入队了。代码如下（因为把写DFS时候的代码以及各种优化全写上去了，也就是注释部分，看上去比较乱，实际大概在100行左右）：

```c++
// Dungeon master
// 深度不记重TLE了，准备改广搜。
// 简单广搜也TLE了，准备记重剪枝优化。
// 深搜剪枝优化还是TLE，看来找最短路还是广搜优化比较合适
// BST剪枝优化的地方不对还是TLE，对了就AC了，就是在candidate入队前去做访问标记用来去重

#include <iostream>
#include <queue>

using namespace std;

class position{
public:
	int l;
	int r;
	int c;
	position() {
		this->l = 0;
		this->r = 0;
		this->c = 0;
	}
	position(int l, int r, int c) {
		this->l = l;
		this->r = r;
		this->c = c;
	}

	// 重载比较运算
	bool operator==(const position& pos) {
		return this->l == pos.l && this->r == pos.r && this->c == pos.c;
	}
};

int MAX_N = 10000000;
char maze[30][30][30];	//记录迷宫，第一维表示层，后面两维表示某一层的迷宫
bool visited[30][30][30];	//记录是否在一次深搜中被访问过
int min_cost[30][30][30];	//记录到达每个点的当前花费
int global_min = MAX_N;	//记录全局的最小路径
position start_pos, end_pos;	//起点和终点坐标
int L, R, C;	//迷宫形状
queue<position> q;


// 检查当前位置能不能走
bool check_pos(int l, int r, int c) {
	if(visited[l][r][c] == false && maze[l][r][c] != '#') {
		visited[l][r][c] = true;
		return true;
	}

	return false;
}

// 参数表示当前点位置，cost表示走到当前位置的花费
void dfs(int l, int r, int c, int cost) {
	visited[l][r][c] = true;
	if(min_cost[l][r][c] > cost)
		min_cost[l][r][c] = cost;
	if(position(l,r,c) == end_pos) {
		if(cost < global_min)
			global_min = cost;
	}
	//往上
	if(l+1<L && check_pos(l+1,r,c) && min_cost[l+1][r][c] > cost+1)	//最后一个条件是做剪枝
		dfs(l+1,r,c,cost+1);
	//往下
	if(l-1>=0 && check_pos(l-1,r,c) && min_cost[l-1][r][c] > cost+1)
		dfs(l-1,r,c,cost+1);
	//往左
	if(c-1>=0 && check_pos(l,r,c-1) && min_cost[l][r][c-1] > cost+1)
		dfs(l,r,c-1,cost+1);
	//往右
	if(c+1<C && check_pos(l,r,c+1) && min_cost[l][r][c+1] > cost+1)
		dfs(l,r,c+1,cost+1);
	//往前
	if(r-1>=0 && check_pos(l,r-1,c) && min_cost[l][r-1][c] > cost+1)
		dfs(l,r-1,c,cost+1);
	//往后
	if(r+1<R && check_pos(l,r+1,c) && min_cost[l][r+1][c] > cost+1)
		dfs(l,r+1,c,cost+1);

	visited[l][r][c] = false;	//恢复访问前的状态
	return;
}

int bfs() {
	while(!q.empty())	q.pop();	//清空队列
	q.push(start_pos);
	position cur;
	int cur_l, cur_r, cur_c;
	int step = -1;
	while(!q.empty()) {
		int size= q.size();
		step += 1;	//每次走深一步
		for(int i=0; i<size; i++) {
			cur = q.front();
			if(cur == end_pos) {
				return step;
			}
			q.pop();
			cur_l = cur.l;
			cur_r = cur.r;
			cur_c = cur.c;
			visited[cur_l][cur_r][cur_c] = true;
			// bfs再试试剪枝。。。
			// if(min_cost[cur_l][cur_r][cur_c] > step)
			// 	min_cost[cur_l][cur_r][cur_c] = step;
			// //往上
			// if(cur_l+1<L && check_pos(cur_l+1,cur_r,cur_c) && min_cost[cur_l+1][cur_r][cur_c] > step+1)
			// 	q.push(position(cur_l+1,cur_r,cur_c));
			// //往下
			// if(cur_l-1>=0 && check_pos(cur_l-1,cur_r,cur_c) && min_cost[cur_l-1][cur_r][cur_c] > step+1)
			// 	q.push(position(cur_l-1,cur_r,cur_c));
			// //往左
			// if(cur_c-1>=0 && check_pos(cur_l,cur_r,cur_c-1) && min_cost[cur_l][cur_r][cur_c-1] > step+1)
			// 	q.push(position(cur_l,cur_r,cur_c-1));
			// //往右
			// if(cur_c+1<C && check_pos(cur_l,cur_r,cur_c+1) && min_cost[cur_l][cur_r][cur_c+1] > step+1)
			// 	q.push(position(cur_l,cur_r,cur_c+1));
			// //往前
			// if(cur_r-1>=0 && check_pos(cur_l,cur_r-1,cur_c) && min_cost[cur_l][cur_r-1][cur_c] > step+1)
			// 	q.push(position(cur_l,cur_r-1,cur_c));
			// //往后
			// if(cur_r+1<R && check_pos(cur_l,cur_r+1,cur_c) && min_cost[cur_l][cur_r+1][cur_c] > step+1)
			// 	q.push(position(cur_l,cur_r+1,cur_c));
			//试试另一种剪枝策略
			//往上
			if(cur_l+1<L && check_pos(cur_l+1,cur_r,cur_c))
				q.push(position(cur_l+1,cur_r,cur_c));
			//往下
			if(cur_l-1>=0 && check_pos(cur_l-1,cur_r,cur_c))
				q.push(position(cur_l-1,cur_r,cur_c));
			//往左
			if(cur_c-1>=0 && check_pos(cur_l,cur_r,cur_c-1))
				q.push(position(cur_l,cur_r,cur_c-1));
			//往右
			if(cur_c+1<C && check_pos(cur_l,cur_r,cur_c+1))
				q.push(position(cur_l,cur_r,cur_c+1));
			//往前
			if(cur_r-1>=0 && check_pos(cur_l,cur_r-1,cur_c))
				q.push(position(cur_l,cur_r-1,cur_c));
			//往后
			if(cur_r+1<R && check_pos(cur_l,cur_r+1,cur_c))
				q.push(position(cur_l,cur_r+1,cur_c));
		}
	}

	return -1;
}


int main() {
	while(true) {
		global_min = MAX_N;
		cin >> L >> R >> C;
		if(L==0 && R==0 && C==0)	// 终止条件
			break;
		for(int i=0; i<L; i++)	// 读迷宫
			for(int j=0; j<R; j++)
				for(int k=0; k<C; k++) {
					cin >> maze[i][j][k];
					if(maze[i][j][k] == 'S')
						start_pos = position(i,j,k);
					if(maze[i][j][k] == 'E')
						end_pos = position(i,j,k);
					visited[i][j][k] = false;
					min_cost[i][j][k] = MAX_N;
				}
		// dfs(start_pos.l, start_pos.r, start_pos.c, 0);

		// if(global_min < MAX_N)	cout << "Escaped in " << global_min << " minute(s)." << endl;
		// else	cout << "Trapped!" << endl;
		int step = bfs();
		if(step != -1)	cout << "Escaped in " << step << " minute(s)." << endl;
		else	cout << "Trapped!" << endl;
	}

	return 0;
}
```

