# Poker Hand
## URL

https://open.kattis.com/problems/pokerhand



## Solution

### Approach 1:

哈希，简单遍历求最大，O(n)

代码如下：

```c++
// Poker Hand

#include <iostream>
#include <map>
#include <string>

using namespace std;



int main() {
	map<char, int> hashmap;
	int maxn = 0;
	char rank, suit;
	string s;
	string tot_string = "A23456789TJQK";
	for(int i=0; i<5; i++) {
		cin >> s;
		rank = s[0];
		suit = s[1];
		if(hashmap.find(rank) == hashmap.end())
			hashmap[rank] = 1;
		else
			hashmap[rank]++;
	}
	int length = tot_string.length();
	for(int i=0; i<length; i++) {
		if(hashmap.find(tot_string[i]) != hashmap.end()) {
			if(hashmap[tot_string[i]] > maxn)
				maxn = hashmap[tot_string[i]];
		}
	}

	cout << maxn << endl;

	return 0;
}
```


