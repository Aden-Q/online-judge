// Incognito

#include <iostream>
#include <unordered_map>



using namespace std;

int main() {
	int num;
	int n;
	int res;
	string name, category;
	cin >> num;
	unordered_map<string, int> map;
	unordered_map<string, int>::iterator it;
	for(int round=0; round<num; round++) {
		map.clear();
		res = 1;
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> name >> category;
			if(map.count(category) == 0)
				map[category] = 2;
			else
				map[category] += 1;
		}
		for(it = map.begin(); it!=map.end(); it++)
			res *= (*it).second;
		res -= 1;
		cout << res << endl;
	}


	return 0;
}