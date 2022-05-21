#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
class DSU{
	vector<int>par;
	vector<int>size;
	public:
	DSU(int n){
		par.resize(n);
		size.resize(n,1);
		for(int i = 0;i < n;i++){
			par[i] = i;
		}
	}
	int findPar(int u){
		if(par[u] == u) return u;
		
		return par[u] = findPar(par[u]);
	}
	void Union(int u,int v){
		u = findPar(u);
		v = findPar(v);
		
		if(size[u] > size[v]){
			par[v] = u;
			size[u] += size[v];
		}else{
			par[u] = v;
			size[v] += size[u];
		}
	}
};
static bool cmp(vector<int>&v1,vector<int>&v2){
	return v1[2] < v2[2];
}

void primsAlgorithm(vector<pair<int,int>>adj[],int n){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,0});
	vector<int>weight(n,INT_MAX);
	vector<int>visited(n,false);
	weight[0] = 0;
	//visited[0] = true;
	vector<int>par(n,-1);
	par[0] = 0;
	while(!pq.empty()){
		int node = pq.top().second;
		visited[node] = true;
		pq.pop();
		for(auto &nbr:adj[node]){
			if(visited[nbr.first] == false and weight[nbr.first] > nbr.second){
				weight[nbr.first] = nbr.second;
				pq.push({nbr.second,nbr.first});
				par[nbr.first] = node;
				//visited[nbr.first] = true;
			} 
		}
		
	}
	cout << "Edges taken: " << endl;
	for(int i = 1;i < n;i++){
		cout << i << " " << par[i] << " " << weight[i] << endl;
	}
}
int main(){
	int v,e;
	cout << "Enter number of vertices: ";
	cin >> v;
	cout << "Enter number of edges: ";
	cin >> e;
	
	vector<pair<int,int>>adj[v];
	cout << "Enter edges start vertex and end vertex and weight: " << endl;
	for(int i = 0;i < e;i++){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	primsAlgorithm(adj,v);
	
	
	return 0;
}
