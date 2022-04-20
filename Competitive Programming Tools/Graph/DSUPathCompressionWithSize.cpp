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
int main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		
	fio();
	int v;
	cin >> v;

	DSU obj = DSU(v);
	obj.Union(0,1);
	obj.Union(1,2);
	obj.Union(4,5);
	obj.Union(0,5);

	cout << obj.findParent(1);
	cout << obj.findParent(0);
	cout << obj.findParent(3);

	// cout << "Hello" << endl;
	return 0;
}