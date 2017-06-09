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
const int MAXN = 51234;

int n,m;
int v1[MAXN];

int bs1(int k) {
	int l = 0;
	int r = n-1;
	int mid = -1;
	bool found = false;

	while (l <= r) {
		mid = (l+r+1)/2;

		if (l == r) {
			if (!found && v1[mid] < k) {
				found = true;
			}

			break;
		}

		if (v1[mid] == k) {
			r = mid-1;
		} else if (v1[mid] > k) {
			r = mid-1;
		} else {
			found = true;
			l = mid;
		}
	}

	if (found) {
		return mid;
	} else {
		return -1;
	}
}

int bs2(int k) {
	int l = 0;
	int r = n-1;
	int mid = -1;
	bool found = false;

	while (l <= r) {
		mid = (l+r)/2;

		if (l == r) {
			if (!found && v1[mid] > k) {
				found = true;
			}

			break;
		}

		if (v1[mid] == k) {
			l = mid+1;
		} else if (v1[mid] > k) {
			found = true;
			r = mid;
		} else {
			l = mid+1;
		}
	}

	if (found) {
		return mid;
	} else {
		return -1;
	}
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> v1[i];
	}

	cin >> m;

	for (int i=0; i<m; i++) {
		int x; cin >> x;
		int k = bs1(x);
		int j = bs2(x);

		if (k == -1) {
			cout << 'X' << ' ';
		} else {
			cout << v1[k] << ' ';
		}

		if (j == -1) {
			cout << 'X' << endl;
		} else {
			cout << v1[j] << endl;
		}
	}
}