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
struct Node{
	Node * links[26];
	bool flag = false;
	Node(){
		for(int i = 0;i < 26;i++){
			links[i] = NULL;
		}
	}
	bool isEnd(){
		return flag;
	}
	bool isExists(char ch){
		return links[ch-97];
	}
	Node* put(char ch){
		return links[ch-97] = new Node();
	}
	void setEnd(){
		flag = true;
	}
};
class Trie{
private:
	Node *root;
public:
	Trie(){
		root = new Node();
	}
	void insert(string &word){
		Node *node = root;
		int n = word.size();
		for(int i = 0;i < n;i++){
			if(node->isExists(word[i]) == false){
				node = node->put(word[i]);
			}else{
				node = node -> links[word[i]-97];
			}
		}
		node -> setEnd();
	}
	bool search(string &word){
		Node *node = root;
		int n = word.size();
		for(int i = 0;i < n;i++){
			if(!node->isExists(word[i])) return false;
			node = node -> links[word[i]-97];
		}
		return node -> isEnd();
	}
	bool startWith(string &prefix){
		Node *node = root;
		int n = prefix.size();
		for(int i = 0;i < n;i++){
			if(!node->isExists(prefix[i])) return false;
			node = node -> links[prefix[i]-97];
		}
		return true;
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
		Trie t = Trie();
		t.insert("ramkishan");
		t.insert("kamlesh");
		t.insert("mahaveer");
		t.insert("dilkhush");
		cout << t.search("ramkishan") << endl;
		cout << t.startWith("ram") << endl;
	}
	return 0;
}
