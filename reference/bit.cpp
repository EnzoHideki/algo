//1 - Point update Range query
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


//2 - Range update Point query
//Here, sum(i) is value at position i (sum of first i elements)
void update(int l, int r, int val) {
	update(l, val);
	update(r+1, -val);
}


//3 - Range update Range query
int bit1[MAXN];
int bit2[MAXN];

void update1(int p, int v) {
	for (; p <= n; p += p&(-p))
		bit1[p] += v; 	 
}

void update2(int p, int v) {
	for (; p <= n; p += p&(-p))
		bit2[p] += v; 	 
}

// Add v to A[a...b] 
void update(int a, int b, int v) {
	update1(a, v);	
	update1(b + 1, -v); 	
	update2(a, v * (a-1)); 	
	update2(b + 1, -v * b);
}

int sum(int bit, int b) {
	int sum = 0; 	
	for(; b > 0; b -= b & (-b))
		sum += (bit == 1 ? bit1[b] : bit2[b]);
	return sum;
}

// Return sum A[1...b]
int sum(int b) {
	return sum(1,b) * b - sum(2,b);
}
