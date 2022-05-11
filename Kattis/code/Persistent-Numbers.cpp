// Persistent Numbers

#include <iostream>
#include <string>


using namespace std;

const int N = 1005;
string s1(N,'\0');
char ch[N] = {'\0'};
int ans[3005];	// 这边需要控制长度，原因是，输入为1000位的话，输出可能比那个要大得多，鉴于测试样例只有3个，我直接调到3005过了就没再调上去。。

// 做一次大数除，能整除则记录商返回true，把商拷贝回原来的大数字符串，不能整除则不做任何修改返回false
bool big_integer_division(int divisor) {
	int mod = 0;	// 记录余数
	for(int i=0; s1[i] != '\0'; i++) {
		mod = mod*10 + s1[i]-'0';
		ch[i] = mod/divisor + '0';
		mod %= divisor;
	}
	if(mod != 0)	// 没有除尽
		return false;

	int j = string(ch).find_first_not_of('0');	// 去掉商数中的所有的先导0
	for(int i=j; i<N; i++) {
		s1[i-j] = ch[i];	// 把商数拷贝回原数组
	}
	for(int i=0; i<N; i++)
		ch[i] = '\0';

	return true;
}

int main() {
	// 大数除法
	while(cin >> s1) {
		int j = 0;
		if(s1[0]=='-' && s1[1]=='1')
			break;
		if(s1[1] == '\0') {	// 只有一位数的情况，直接输出'1'+那位数
			cout << '1' << s1[0] << endl;
			continue;
		}
		for(int i=9; i>1; i--) {	// 从上到下验证整除性
			while(big_integer_division(i)) {
				ans[j++] = i;	// 记录除数
			}
		}

		if(s1[0] == '1' && s1[1]=='\0')	{
			for(int i=j-1; i>=0; i--)
				cout << ans[i];
			cout << endl;
		}
		else	cout << "There is no such number." << endl;
	}

	return 0;
}