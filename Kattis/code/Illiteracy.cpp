// Illiteracy

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <algorithm>
// #include <time.h>

using namespace std;

unordered_map<char, char> rotatemap = {
	{'A', 'B'},
	{'B', 'C'},
	{'C', 'D'},
	{'D', 'E'},
	{'E', 'F'},
	{'F', 'A'}
};
unordered_map<string, int> smap;

int BFS(string start_seq, string target_seq);
string pushIcon(string seq, int position);

string pushIcon(string seq, int position) {
	if(seq[position] == 'A') {
		if(position == 0)
			seq[position+1] = rotatemap[seq[position+1]];
		else if(position == 7)
			seq[position-1] = rotatemap[seq[position-1]];
		else {
			seq[position+1] = rotatemap[seq[position+1]];
			seq[position-1] = rotatemap[seq[position-1]];
		}
	}
	else if(seq[position] == 'B') {
		if(position != 0 && position != 7)
			seq[position+1] = seq[position-1];
	}
	else if(seq[position] == 'C') {
		seq[7-position] = rotatemap[seq[7-position]];
	}
	else if(seq[position] == 'D') {
		if(position < 4) {
			for(int i=0; i<position; i++)
				seq[i] = rotatemap[seq[i]];
		}
		else {
			for(int i=position+1; i<8; i++)
				seq[i] = rotatemap[seq[i]];
		}
	}
	else if(seq[position] == 'E') {
		if(position != 0 && position != 7) {
			int y = min(position, 7-position);
			seq[position-y] = rotatemap[seq[position-y]];
			seq[position+y] = rotatemap[seq[position+y]];
		}

	}
	else if(seq[position] == 'F') {
		if(position%2 == 0)	seq[(position+8)/2] = rotatemap[seq[(position+8)/2]];
		else	seq[(position-1)/2] = rotatemap[seq[(position-1)/2]];
	}

	return seq;
}

int BFS(string start_seq, string target_seq) {
	// 层数高就不行了，22那个明显TLE了，简单memorization也不行，还得优化
	int step = -1;
	queue<string> q;
	q.push(start_seq);
	string cur_seq;
	while(!q.empty()) {
		step++;
		int size = q.size();
		// cout << size << endl;
		for(int i=0; i<size; i++) {
			cur_seq = q.front();
			if(cur_seq == target_seq)	return step;
			for(int j=0; j<8; j++) {
				string s = pushIcon(cur_seq, j);	// constant time op
				if(!smap.count(s)) {
					smap[s] = step;
					q.push(s);
				}
			}
			q.pop();
		}
	}

	return step;
}


int main() {
	// simple BFS
	string start_seq, target_seq;
	cin >> start_seq >> target_seq;
	// clock_t start, end;
	// start = clock();
	int ans = BFS(start_seq, target_seq);
	// end = clock();
	cout << ans << endl;
	// cout<<(double)(end-start)/CLOCKS_PER_SEC << endl;

	return 0;
}