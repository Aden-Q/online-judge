// Cetiri

#include <iostream>
#include <algorithm>

using namespace std;


int main() {
	int a[3] = {0};
	int ans;
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a+3);
	int diff1 = a[1] - a[0];
	int diff2 = a[2] - a[1];

	if(diff1 == diff2)
		cout << (a[2] + diff1) << endl;
	else if(diff1 == 2*diff2)
		cout << (a[0] + diff2) << endl;
	else
		cout << (a[1] + diff1) << endl;

	return 0;
}