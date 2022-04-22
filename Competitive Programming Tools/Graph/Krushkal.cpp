#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <climits>
#define ll long long
#define modulo 1000000007
using namespace std;
void fio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
class DSU{
	vector<int>parent;
	vector<int>size;
	int v;
public:
	DSU(int v){
		this -> v = v;
		parent.resize(v,0);
		size.resize(v,1);
		for(int i = 0; i < v;i++){
			parent[i] = i;
		}
	}
	int findParent(int u){
		if(parent[u] == u) return u;
		return parent[u] = findParent(parent[u]);
	}
	void Union(int u,int v){
		u = findParent(u);
		v = findParent(v);

		if(size[u] > size[v]){
			parent[v] = u;
			size[u] += size[v];
		}else{
			parent[u] = v;
			size[v] += size[u];
		}
	}
};
static bool cmp(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2){
	return p1.first < p2.first;
}
int main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		
	fio();
	int t;
	cin >> t;
	while(t--){
		int v;
		cin >> v;
		int e;
		cin >> e;

		vector<pair<int,pair<int,int>>>edges;

		for(int i = 0;i < e; i++){
			int u,v,w;
			cin >> u >> v >> w;
			edges.push_back({w,{u,v}});
		}

		sort(edges.begin(),edges.end(),cmp);
		DSU dsu = DSU(v);
		int minWeight = 0;
		for(int i = 0;i < e;i++){
			int p1 = dsu.findParent(edges[i].second.first);
			int p2 = dsu.findParent(edges[i].second.second);  
			if(p1 == p2){
				continue;
			}else{
				dsu.Union(p1,p2);
				minWeight += edges[i].first;
			}
		}
		cout << "Min Weight: " << minWeight << endl;
	}
	return 0;
}
