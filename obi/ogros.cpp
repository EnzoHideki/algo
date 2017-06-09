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
#define dbn(x) //cerr << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//
const int MAXN = 11234;

int n,m;
int limits[MAXN];
int awards[MAXN];

int bs(int power) {
	if (power < limits[0]) {
		return awards[0];
	}

	int l = 0;
	int r = n-2;
	int mid = -1;

	while (l <= r) {
		mid = (l+r+1)/2;

		if (limits[mid] == power || l == r) {
			return awards[mid+1];
		} else if (limits[mid] < power) {
			l = mid;
		} else {
			r = mid-1;
		}
	}

	return awards[mid+1];
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	cin >> n >> m;

	for (int i=0; i<n-1; i++) {
		cin >> limits[i];
	}
	for (int i=0; i<n; i++) {
		cin >> awards[i];
	}
	for (int i=0; i<m; i++) {
		int x; cin >> x;
		cout << bs(x) << " \n"[i==m-1];
	}
}