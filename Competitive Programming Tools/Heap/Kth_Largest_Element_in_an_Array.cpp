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
class Solution {
public:
    void heapify(vector<int>&nums,int i,int n)
    {
        int left = 2*i+1;
        int right = left+1;
        int smallest=i;
        
        if(left<n and right<n)
        {
            int smaller = min(nums[left],nums[right]);
            if(nums[i]>smaller)
            {
                if(smaller==nums[left])
                    smallest=left;
                else
                    smallest=right;
            }
        }
        else if(left<n and nums[i]>nums[left])
            smallest = left;
        
        if(smallest!=i)
        {
            swap(nums[smallest],nums[i]);
            heapify(nums,smallest,n);
        }
    }
    void buildHeap(vector<int>&nums,int n)
    {
        for(int i=(n-2)/2;i>=0;i--)
            heapify(nums,i,n);
    }
    int findKthLargest(vector<int>& nums, int k) {
        buildHeap(nums,k);
        for(int i=k;i<nums.size();i++)
            if(nums[0]<nums[i])
            {
                swap(nums[i],nums[0]);
                heapify(nums,0,k);
            }
        
        return nums[0];
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

    }
    return 0;
}
