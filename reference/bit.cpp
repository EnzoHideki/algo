//iterative version
void update(int i, int val) {
	for (; i <= n; i += (i & -i)) bit[i] += val;
}

int sum(int i) {
	int ans = 0;
	for (; i; i -= (i & -i)) ans += bit[i];
	return ans;
}

//recursive version
void update(int i, int val) {
	if (i > n) return;
	bit[i] += val;
	update(i + (i & -i), val);
}

int sum(int i) {
	if (i == 0) return 0;
	return bit[i] + sum(i - (i & -i));
}