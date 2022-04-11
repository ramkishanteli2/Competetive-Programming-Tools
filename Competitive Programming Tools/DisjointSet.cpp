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
int findPar(int i,vector<int>&par){
	if(i == par[i]) return i;
	
	return par[i] = findPar(par[i],par);
}
void Union(int i,int j,vector<int>&par,vector<int>&rank){
	i = findPar(i,par);
	j = findPar(j,par);
	if(rank[i] > rank[j]){
		par[j] = i;
	}else if(rank[i] < rank[j]){
		par[i] = j;
	}else{
		par[j] = i;
		rank[i]++;
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
		int n;
		cin >> n;
		vector<int>par(n+1,0);
		vector<int>rank(n+1,0);
		for(int i = 0;i <=n;i++) par[i] = i; 
		Union(1,2,par,rank);
		cout << findPar(2,par);
		Union(2,3,par,rank);
		cout << findPar(3,par);
		Union(4,5,par,rank);
		cout << findPar(4,par);
		Union(6,7,par,rank);
		cout << findPar(7,par);
		Union(5,6,par,rank);
		cout << findPar(5,par);
		Union(3,7,par,rank);
		cout << findPar(7,par);
		cout << endl;
		for(int i = 1; i <= n;i++){
			cout << par[i] << " ";
		}
	}
	return 0;
}
