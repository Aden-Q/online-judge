// Fire Net

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int wall = 1;
int space = 0;
int blockhouse = 2;
int maxc = 0;	// record the global optimal

bool finePosition(int p, vector<vector<int> > &map);
void fireNet(int p, vector<vector<int> > &map, int cur);

bool finePosition(int p, vector<vector<int> > &map) {
	// This function is use to check whether the current solution is possible.
	int row = p / map.size();
	int col = p % map.size();
	if(map[row][col] != space)	return false;
	// check four directions
	bool fine = true;
	for(int i=row-1; i>=0; i--) {
		// compare with the top few rows
		if(map[i][col] == blockhouse)	return false;
		else if(map[i][col] == wall) {
			fine = true;
			break;
		}
	}
	for(int j=col-1; j>=0; j--) {
		// compare with the left few cols
		if(map[row][j] == blockhouse)	return fine = false;
		else if(map[row][j] == wall) {
			fine = true;
			break;
		}
	}

	return fine;
}


// 1 loops DFS
void fireNet(int p, vector<vector<int> > &map, int cur) {
	// map stores the configration of the city
	// n indicates the size of map (square)
	// cur stores the local optimal of the maxmimum number of blockhous
	// p: current position, p = n*(row-1)+col
	if(cur > maxc)	maxc = cur;
	int n = map.size();
	if(p >= n*n)	return;
	if(finePosition(p, map)) {
		map[p/n][p%n] = blockhouse;
		fireNet(p+1, map, cur+1);
		map[p/n][p%n] = space;	// recover to the original state

	}
	fireNet(p+1, map, cur);	// consider next position, nothing changes

	return;
}


int main() {
	int n;
	while(cin >> n) {
		maxc = 0;	// initialize the global optimal
		cin.ignore();	// ignore '\n'
		if(n==0)	break;	// exit signal
		vector<vector<int> > map(n, vector<int>(n, space));	// initialize the map with all open space
		string s;
		for(int row=0; row<n; row++) {
			getline(cin, s);
			for(int col=0; col<n; col++)
				if(s[col]=='X')	map[row][col] = wall;
		}
		fireNet(0, map, 0);
		cout << maxc << endl;

	}

	return 0;
}