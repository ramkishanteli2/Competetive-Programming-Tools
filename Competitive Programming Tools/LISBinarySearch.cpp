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
int LIS(vector<int>&vec){
	int n = vec.size();
	vector<int>temp;
	temp.push_back(vec[0]);

	for(int i = 1; i < n;i++){
		if(vec[i] > temp.back()){
			temp.push_back(vec[i]);
		}else{
			int j = lower_bound(temp.begin(),temp.end(),vec[i]) - temp.begin();
			temp[j] = vec[i];
		}
	}
	return temp.size();

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
		vector<int>vec(n);
		for(int i = 0; i < n;i++){
			cin >> vec[i];
		}

		cout << LIS(vec) << endl;

	}
	return 0;
}
