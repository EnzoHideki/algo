#include <iostream>

using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    
    int ans = 0;
    
    for (int i=0; i<n; i++) {
        int v; cin >> v;
        
        if (a >= b) {
            if (v > a) {
                ans++;
            } else {
                a -= v;
            }
        } else {
            if (v > b) {
                ans++;
            } else {
                b -= v;
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}