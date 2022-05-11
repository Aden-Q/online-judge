// Heir's Dilemma

#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> nums;
int tot = 0;

int main() {
	int L, H;
	cin >> L >> H;
	for(int num=L; num<H+1; num++) {
		nums.clear();
		string s = to_string(num);
		bool flag = false;
		for(int i=0; i<6; i++) {
			if(s[i] == '0') {
				flag = true;
				break;
			}
			nums.insert(s[i]);
		}
		if(flag)	continue;
		if(nums.size() != 6)	continue;
		int i;
		for(i=0; i<6; i++)
			if(num%(s[i]-'0') != 0)	break;
		if(i==6)	tot++;
	}

	cout << tot << endl;

	return 0;
}