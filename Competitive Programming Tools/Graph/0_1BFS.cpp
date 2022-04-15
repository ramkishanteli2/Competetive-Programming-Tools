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

void _01BFS(int v,vector<pair<int,int>>adj[]){
	
	vector<int>dist(v+1,INT_MAX);
	dist[1] = 0;
	deque<pair<int,int>>dq;
	dq.push_front({1,0});
	while(!dq.empty()){
		int curr = dq.front().first;
		int d = dq.front().second;
		dq.pop_front();

		for(auto nbr:adj[curr]){
			if(d + nbr.second < dist[nbr.first]){
				dist[nbr.first] = d + nbr.second;
				if(nbr.second == 0){
					dq.push_front({nbr.first,dist[nbr.first]});
				}else{
					dq.push_back({nbr.first,dist[nbr.first]});
				}
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
		_01BFS(v,adj);

	}
	return 0;
}
