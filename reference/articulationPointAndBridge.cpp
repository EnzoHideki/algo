int tempo = 0;
int pre[MAXN];
int dfs_low[MAXN];
int parent[MAXN];
bool articulation_vertex[MAXN];
int root;

void articulationPointAndBridge(int u) {
	dfs_low[u] = pre[u] = tempo++; // dfs_low[u] <= dfs_num[u]
	
	for (int j : adj[u]) {
		if (pre[j] == -1) { // unvisited tree edge
			parent[j] = u;
			
			if (u == root) rootChildren++; // special case if u is a root
			
			articulationPointAndBridge(j);
			
			if (dfs_low[j] >= pre[u]); 	// u is AP, you choose what to do
			
			if (dfs_low[j] > pre[u]); 	// uj is bridge, you choose what to do
			else; 						// uj is not bridge, you choose what to do
			
			dfs_low[u] = min(dfs_low[u], dfs_low[j]);
		} else if (j != dfs_parent[u]) // a back edge and not direct cycle
			dfs_low[u] = min(dfs_low[u], pre[j]);
	}
}

int main() {
	memset(pre, -1, sizeof pre);
	memset(dfs_low, 0, sizeof dfs_low);
	memset(parent, 0, sizeof parent);
	memset(articulation_vertex, false, sizeof articulation_vertex);
	
	for (int i = 0; i < V; i++)
		if (pre[i] == -1) {
			root = i; 
			rootChildren = 0; 
			articulationPointAndBridge(i);
			articulation_vertex[dfsRoot] = (rootChildren > 1); // special case
		}
}