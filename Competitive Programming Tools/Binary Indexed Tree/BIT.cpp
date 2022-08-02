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
class BIT{
    vector<int>arr;
    int n;
public:
    BIT(){
        
    }
    void resize(int n){
        arr.resize(n+1,0);
        this->n = n;
    }
    void insert(int idx,int val){
        idx = idx + 1;
        while(idx <= n){
            arr[idx] += val;
            idx = idx + (idx&(-idx));
        }
    }
    int prefixSum(int idx){
        idx = idx + 1;
        int sum = 0;
        while(idx > 0){
            sum += arr[idx];
            idx = (idx&(idx-1));
        }
        return sum;
    }
    
};
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
		BIT T;
		T.resize(n);
		for(int i = 0;i < n;i++){
			T.insert(i,arr[i]);
		}
		cout << T.prefixSum(10);
	}
	return 0;
}
