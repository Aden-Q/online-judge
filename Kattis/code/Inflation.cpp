// Inflation

#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;
    int *c = new int[n];
    for(int i=0; i<n; i++)
        cin >> c[i];
    sort(c, c+n);
    double max_ratio = 1;
    double ratio;
    for(int i=0; i<n; i++) {
        ratio = c[i]*1.0 / (i+1);
        if(ratio>=1+1e-6) {
            cout << "impossible" << endl;
            return 0;
        }
        else if(ratio < max_ratio)
            max_ratio = ratio;
    }
    cout << max_ratio << endl;

    return 0;
}
