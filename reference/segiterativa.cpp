#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n;
int seg[2 * N];

void build() {
	for (int i = n-1; i > 0; i--)
		seg[i] = seg[i*2]+seg[i*2+1];
}

void modify(int id, int x) {
	id += n;
	seg[id] = x;
	id /= 2;
	for (int i = id; i >= 1; i /= 2)
		seg[i] = seg[i*2]+seg[i*2+1];
}

int query(int l, int r) {
	int ans = 0;
	l += n, r += n;
	while (l < r) {
		if (l%2 != 0) ans += seg[l++];
		if (r%2 != 0) ans += seg[--r];
		l /= 2;
		r /= 2;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", seg + n + i);
	build();
	printf("%d\n", query(3, 11));
	modify(3, 5);
	printf("%d\n", query(3, 11));
	return 0;
}