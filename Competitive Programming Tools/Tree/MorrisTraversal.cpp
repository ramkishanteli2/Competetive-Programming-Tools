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
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans;
        // Problem is Solved Using Morris Traversal
        while(root){
            if(!root->left){
                count++;
                if(count == k) ans = root->val;
                root = root->right;
            }else{
                TreeNode*prev = root->left;
                while(prev->right and prev->right != root){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = root;
                    root = root->left;
                }else{
                    count++;
                    prev->right = NULL;
                    if(count == k) ans = root->val;
                    root = root->right;
                }
            }
        }
        return ans;
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
	cin>>t;
	while(t--){

	}
	return 0;
}
