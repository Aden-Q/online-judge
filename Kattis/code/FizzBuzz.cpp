// FizzBuzz
#include <iostream>

using namespace std;


int main() {
    int X, Y, N;
    cin >> X >> Y >> N;
    int *divisible_stat = new int[N+1];
    for(int i=1; i<=N; i++) {
        if(i%X == 0)
            divisible_stat[i] += 1;
        if(i%Y == 0)
            divisible_stat[i]+= 2;
    }
    for(int i=1; i<=N; i++) {
        if(divisible_stat[i] == 0)
            cout << i << endl;
        else if(divisible_stat[i] == 1)
            cout << "Fizz" << endl;
        else if(divisible_stat[i] == 2)
            cout << "Buzz" << endl;
        else
            cout << "FizzBuzz" << endl;
    }

    return 0;
}