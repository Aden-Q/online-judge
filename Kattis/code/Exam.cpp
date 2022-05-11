// Exam

#include<iostream>

using namespace std;

int main() {
	string s1, s2;
	int same, diff;
	int k;
	int corr;
	same = 0;
	diff = 0;
	cin >> k;
	cin >> s1 >> s2;
	for(int i=0; i<s1.length(); i++) {
		if(s1[i] == s2[i])
			same++;
		else
			diff++;
	}
	if(same > k)
		corr = k+diff;
	else
		corr = same + s1.length() - k;

	cout << corr << endl;

	return 0;

}