#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <climits>
#include <bitset>
#define ll long long
#define modulo 1000000007
using namespace std;
void fio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
int main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	//Bitset is container which only stores 0's or 1's
	//Bitset container which size 5
	//Bitset indexing starts from right to left
	bitset<5>bt;
	//bitset 1 bit
	cin >> bt;
	cout << bt << endl;
	//all
	//return true if all bits set to 1 else returns false
	cout << bt.all() << endl;
	
	//any
	//return true if at least one bit is set bit else returns false
	cout << bt.any() << endl;
	
	//count
	//returns number of set bits in bt
	cout << bt.count() << endl;
	
	//flip
	//flip the bit at given position
	//10001 -> 10101
	bt.flip(2);
	cout << bt << endl;
	
	//none
	//return true if all bits are unset else return true
	//1001 -> false 0000 -> true
	cout << bt.none() << endl;
	
	//set
	//set bit at a given position
	//1001 -> 1101
	bt.set(1);
	cout << bt << endl;
	//bt.set(pos,set 0 or 1)
	bt.set(4,1);
	cout << bt << endl;
	
	//reset
	//just opposite to set it reset the bit from 1 -> 0
	
	//size
	//return the size of bitset
	cout << bt.size() << endl;

	//test
	//return that given position is set or not

	cout << bt.test(3) << endl;

	return 0;
}
