#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

vector< pair<int, int> > edges;
vector<int> adjacent_nodes; //V dugaartai oroigoos ehleltei edge-uud erembelegdsen edges vector-t hed dugaaraas ehelj baigaag temdeglene
vector<int>low, discover, depth, finish;
vector< vector<int> >dfs_tree;

int steps(0);

void dfs(int dad, int child, int _depth) {
	discover[child] = low[child] = ++steps;
	depth[child] = _depth;

	for (int i = adjacent_nodes[child]; i < adjacent_nodes[child+1]; i++) {
		int grand_child = edges[i].second;

		if (dad == grand_child) continue;
		if (discover[grand_child] == -1) {
			dfs(child, grand_child, _depth+1);
			low[child] = min(low[child], low[grand_child]);
			dfs_tree[child].push_back(grand_child);
		} else { //back edge!
			low[child] = min(low[child], discover[grand_child]);
		}
	}
	finish[child] = steps++;
}

bool a_under_b(int a, int b) { //is node 'a' under subtree rooted at 'b'
	return discover[b] <= discover[a] && finish[a] <= finish[b];
}

int find_root_sub(int me, int descendant) { //under(descendant, me) ued descendant orshin baigaa sub tree-nii root-g olno
   int lo = 0, hi = dfs_tree[me].size() - 1;
   while( lo != hi ) {
      int mid = (lo+hi) / 2;

      if( discover[descendant] > finish[ dfs_tree[me][mid] ] ) lo = mid+1;
      else if( finish[descendant] < discover[ dfs_tree[me][mid] ] ) hi = mid-1;
      else lo = hi = mid;
   }
   return dfs_tree[me][lo];
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, e; scanf("%d%d", &n, &e);
	while (e--) {
		int a, b; scanf("%d%d", &a, &b); --a, --b;
		edges.push_back(make_pair(a, b));
		edges.push_back(make_pair(b, a));
	}
	dfs_tree.resize(n);
	depth.resize(n, -1);
	low.resize(n, -1);
	finish.resize(n, -1);
	discover.resize(n, -1);

	sort(edges.begin(), edges.end());

	adjacent_nodes.resize(n+1);
	adjacent_nodes[0] = 0; //test-g buh oroigoos buh oroi hurch bolohoor hiisen tul adjacent_nodes zuv! salangid componenttoi test baisan bol buruu
	for (int i = 1; i <= n; i++)
		for (adjacent_nodes[i] = adjacent_nodes[i-1]; 
			adjacent_nodes[i] < edges.size() && edges[adjacent_nodes[i]].first < i; 
			adjacent_nodes[i]++);

	dfs(-1, 0, 0);

	int q; scanf("%d", &q); while (q--) {
		int code, a, b, c, d;
		scanf("%d%d%d%d", &code, &a, &b, &c); a--, b--, c--;
		if (code == 1) {
			scanf("%d", &d); d--;

         if(a_under_b( c, d ) ) swap( c, d );

         if( low[d] < discover[d] ) printf( "yes\n" );
         else if( a_under_b(a, d) == a_under_b(b, d) ) printf( "yes\n" );
         else printf( "no\n" );
		} else {
         if( !a_under_b( a, c ) && !a_under_b( b, c ) ) printf( "yes\n" );
         else if( a_under_b( a, c ) && a_under_b( b, c ) ) {
            int e = find_root_sub( c, a );
            int f = find_root_sub( c, b );
            if( e == f ) printf( "yes\n" );
            else if( low[e] < discover[c] && low[f] < discover[c] ) printf( "yes\n" );
            else printf( "no\n" );
         } else {
            if( a_under_b( a, c ) ) swap( a, b );
            int e = find_root_sub( c, b );
            if( low[e] < discover[c] ) printf( "yes\n" );
            else printf( "no\n" );
         }
		}
	}
	return 0;
}