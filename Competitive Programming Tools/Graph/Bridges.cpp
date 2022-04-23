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
void dfs(int sv,int par,int &timer,vector<int>adj[],vector<int>&visited,vector<int>&tin,vector<int>&low){
	visited[sv] = true;
	tin[sv] = timer;
	low[sv] = timer;
	// cout << sv << " " << timer << endl;
	for(auto nbr:adj[sv]){
		if(!visited[nbr]){
			timer++;
			dfs(nbr,sv,timer,adj,visited,tin,low);
			low[sv] = min(low[sv],low[nbr]);
			if(tin[sv] < low[nbr]){
				cout << sv << " " << nbr << endl;
			}
		}else if(nbr != par){
			low[sv] = min(low[sv],low[nbr]);
		}
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
	cin >> t;
	while(t--){
		int n,e;
		cin >> n >> e;
		vector<int>adj[n];
		for(int i = 0;i < e;i++){
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int>tin(n,0);
		vector<int>low(n,0);
		vector<int>visited(n,false);
		int timer = 1;
		dfs(1,-1,timer,adj,visited,tin,low);
	}
	return 0;
}
