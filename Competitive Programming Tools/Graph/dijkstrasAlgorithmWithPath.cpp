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
unordered_map<int,int> adj[100001];
vector<long long>dist(100001,1e15);
vector<int>par(100001);
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
void dijkstra(int v){
	dist[1] = 0;
	for(int i = 1;i <= v;i++){
		par[i] = i;
	}
	pq.push({0,1});
 
	while(!pq.empty()){
		int node = pq.top().second;
		int d = pq.top().first;
		pq.pop();
 
		for(auto nbr:adj[node]){
			if(d + nbr.second < dist[nbr.first]){
				dist[nbr.first] = d + nbr.second;
				par[nbr.first] = node;
				pq.push({dist[nbr.first],nbr.first});
			}
		}
 
	}
	if(dist[v] == 1e15){
		cout << -1 << endl;
		return;
	}
	int j = v;
	int it = 0;
	while(par[j] != j){
		dist[it++] = j;
		j = par[j];
	}
	dist[it] = 1;
 
	while(it >= 0){
		cout << dist[it] << " ";
		it--;
	}
	cout << endl;
 
 
}
 
int main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		
	fio();
	// int t;
	// cin>>t;
	// while(t--){
		int v,e;
		cin >> v >> e;
		for(int i = 0;i < e;i++){
			int u,v,w;
			cin >> u >> v >> w;
			if(adj[u].count(v)){
				adj[u][v] = min(adj[u][v],w);
			}else{
				adj[u][v] = w;
			}
			if(adj[v].count(u)){
				adj[v][u] = min(adj[v][u],w);
			}else{
				adj[v][u] = w;
			}
		}
		dijkstra(v);
 
	// }
	return 0;
}