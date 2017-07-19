#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <unistd.h>
#include <utility>
#include <vector>
#define dbc(x) cerr << x << '\n'
#define dbn(x) cerr << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//
vector<int> v;

bool contains(int n, int k) {
    string sn = to_string(n);
    string sk = to_string(k);

    int j = 0;

    for (int i=0; i<(int) sn.size(); i++) {
        if (sn[i] == sk[j]) {
            j++;
        }

        if (j == 3) return true;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    while (cin >> n) v.pb(n);

    sort(v.begin(), v.end());
    unique(v.begin(), v.end());

    int m = 100000;

    while (true) {
        bool ok = true;

        for (auto i : v) {
            if (!contains(m,i)) {
                ok = false;
                break;
            }
        }

        if (ok) break;

        m++;
    }

    cout << m << endl;
}