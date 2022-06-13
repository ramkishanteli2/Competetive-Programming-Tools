#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <climits>
#include <bitset>
#include <cstring>
#define ll long long
#define modulo 1000000007
using namespace std;
void fio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
int majorityElement(vector<int>&arr){
	int count = 0;
	int candidate;

	for(int i = 0;i < arr.size();i++){
		if(count == 0){
			candidate = arr[i];
		}
		if(candidate == arr[i]){
			count++;
		}else{
			count--;
		}
	}
	return candidate;

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
		int n;
		cin >> n;
		vector<int>arr(n);
		for(int i = 0;i < n;i++){
			cin >> arr[i];
		}
		cout << majorityElement(arr) << endl;
	}
	return 0;
}
