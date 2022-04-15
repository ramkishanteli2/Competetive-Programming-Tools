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
void dijkstra(int v,vector<pair<int,int>>adj[]){
	vector<int>dist(v+1,INT_MAX);
	dist[1] = 0;
	priority_queue<pair<int,int>>pq;
	pq.push({0,1});

	while(!pq.empty()){
		int node = pq.top().second;
		int d = pq.top().first;
		pq.pop();

		for(auto nbr:adj[node]){
			int curr = nbr.first;
			int wt = nbr.second;
			if(d + wt < dist[curr]){
				dist[curr] = d + wt;
				pq.push({d+wt,curr});
			}
		}

	}
	cout << "Distance from the source 1 to other nodes are: \n";

	for(int i = 1;i <= v;i++){
		cout << dist[i] << " ";
	}

}

int main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		
	fio();
	int t;
	cin>>t;
	while(t--){
		int v,e;
		cin >> v >> e;
		vector<pair<int,int>>adj[v+1];

		for(int i = 0;i < e;i++){
			int u,v,w;
			cin >> u >> v >> w;
			adj[u].push_back({v,w});
			adj[v].push_back({u,w});
		}
		dijkstra(v,adj);

	}
	return 0;
}
