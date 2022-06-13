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

int hammingWeight(uint32_t n) {
    int count = 0;
    while(n){
    	n = n & (n-1);
        count++;
    }
    return count;
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
		uint32_t n;
		cin >> n;
		cout << hammingWeight(n) << endl;
	}
	return 0;
}
