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