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
struct Graph{
	int v;
	int e;
	vector<int> *adj;
};
Graph* createGraph(int e,int v){

	Graph *G = new Graph;
	G->v = v;
	G->e = e;
	G->adj = new vector<int>[v+1];
	return G;
}

bool checkCycleDfs(int sv,int par,Graph *G,vector<int>&visited){
	visited[sv] = true;
	bool ans = false;
	for(auto item:G->adj[sv]){
		if(!visited[item]){
			ans|=checkCycleDfs(item,sv,G,visited);
		}else if(item != par) return true;
	}
	return ans;
}

int main(){
	// your code goes here
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		
	fio();

	int v,e;
	cin >> v >> e;

	Graph*G=createGraph(e,v);

	for(int i = 0;i<e;i++){
		int u,v;
		cin >> u >> v;
		G->adj[u].push_back(v);
		G->adj[v].push_back(u);
	}
	vector<int>visited(v+1,0);
	int i;
	for(i = 1;i<=v;i++){
		if(visited[i] == 0){
			if(checkCycleDfs(i,-1,G,visited)){
				cout << "Cycle Exists" <<endl;
				break;
			}
		}
	}
	if(i == v+1)
		cout << "Cycle Does Not Exists" << endl;
	delete[] G->adj;
	delete G;
	return 0;
}