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
//Using Kahn's Algorithm
void topoBFS(int sv,Graph*G,vector<int>&inDegree){
	queue<int>q;
	q.push(sv);
	/*
		* Initially we push all the vertex having indegree as zero
		* We know the vertex having indegree zero will be the first vertex to be 
		  taken out.
		* we pop that vertex having indegree zero and checks for its adjacent 
		  whenever and we decrease the indegree of adjacents and whenever we found 
		  a vertex with indegree zero then we push that vertex into queue
		* We repeat this process until our queue is non empty
	*/
	while(!q.empty()){
		int curr = q.front();
		cout << curr << " ";
		q.pop();
		for(auto item:G->adj[curr]){
			inDegree[item]--;
			if(inDegree[item] == 0){
				q.push(item);
			}
		}
	}
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
	vector<int>inDegree(v+1,0);
	for(int i = 0;i<e;i++){
		int u,v;
		cin >> u >> v;
		G->adj[u].push_back(v);
		inDegree[v]++;
		// G->adj[v].push_back(u);
	}
	vector<int>visited(v+1,0);
	for(int i = 0;i<v;i++){
		if(inDegree[i] == 0){
			topoBFS(i,G,inDegree);
		}
	}
	delete[] G->adj;
	delete G;
	return 0;
}