#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 123;
const int MOD = 1e9 + 7;

int a[MAXN];

int f(int n) {
    ll prod = 1;
    
    for (int i=0; i<n; i++) {
        prod = (prod*a[i]) % MOD;
    }
    
    return (int) prod;
}

int g(int n) {
    int aa = a[0];
    
    for (int i=1; i<n; i++) {
        aa = __gcd(aa, a[i]);
    }
    
    return aa;
}

int main() {
    int n; cin >> n;
    
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    int times = g(n);
    int k = f(n);
    
    ll prod = 1;
    
    for (int i=0; i<times; i++) {
        prod = (prod*k) % MOD;
    }
    
    cout << prod << endl;
    
    return 0;
}
