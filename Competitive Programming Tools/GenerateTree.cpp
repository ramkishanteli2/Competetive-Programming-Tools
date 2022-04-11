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

unordered_map<int,vector<int>>tree;
unordered_map<int,int>parent;

void generateTree(int root,unordered_map<int,vector<int>>&adj){
	for(auto item:adj[root]){
		if(parent.count(item) == 0){
			parent[item] = root;
			tree[root].push_back(item);
			generateTree(item,adj);
		}
	}
}

void traversal(int root){
	cout << root << " ";
	for(auto item:tree[root]){
		traversal(item);
	}
}

int main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;
	int root;
	//n vertices
	cin >> n;
	cin >> root;
	int A[n-1],B[n-1];
	//Total n-1 edges will be there
	for(int i = 0;i<n-1;i++){
		cin >> A[i];
	}
	for(int i = 0;i<n-1;i++){
		cin >> B[i];
	}

	// Edges are bi-directional Map will hold the details which vertex is connected with 
	// which other vertex

	unordered_map<int,vector<int>>adj;

	for(int i = 0;i<n;i++){
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
	}

	//Now times to generate tree we will use two extra hash map tree and parent since one vertex is 
	//already included in the tree and now again child vertex is gonna call for parent so to avoid the
	//condition we store the details in the parent map so later we will not make a recursive call back

	parent[root] = -1;

	generateTree(root,adj);
	traversal(root);

}
