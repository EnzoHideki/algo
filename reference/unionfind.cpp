void init() {
	for (int i=0; i<n; i++) {
		parent[i] = i;
	}
}

int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }

void join(int x, int y) {
	if ((x = find(x)) == (y = find(y))) return;
	
	if (rank[x] < rank[y]) {
		parent[x] = y;
	} else if (rank[x] > rank[y]) {
		parent[y] = x;
	} else if (rank[x] == rank[y]) {
		parent[x] = y;
		rank[y]++;
	}
}