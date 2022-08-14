
class Solution {
public:
    /**
     * @param root: a TreeNode
     * @return: a list of integer
     */
    vector<int>ans;
    // void traversal(TreeNode * root){
    //     if(!root) return;
    //     cout << root->val << " ";
    //     traversal(root->left);
    //     traversal(root->right);
    // }
    void leftTraversal(TreeNode *root,int level){
        if(!root) return;
        if(!root->left and !root->right){
            return;
        }
        ans.push_back(root->val);
        if(root->left)
            leftTraversal(root->left,level+1);
        else
            leftTraversal(root->right,level+1);
    }
    void leaf(TreeNode *root){
        if(!root) return;
        if(!root->left and !root->right){
            ans.push_back(root->val);
            return;
        }
        leaf(root->left);
        leaf(root->right);
    }
    void rightTraversal(TreeNode *root,int level){
        if(!root) return;
        if(!root->left and !root->right){
            return;
        }
        if(root->right)
            rightTraversal(root->right,level+1);
        else
            rightTraversal(root->left,level+1);
        ans.push_back(root->val);
    }
    vector<int> boundaryOfBinaryTree(TreeNode *root) {
        // write your code here
        if(!root) return {};
        if(!root->left and !root->right) return {root->val};
        ans.push_back(root->val);
        // traversal(root);
        leftTraversal(root->left,0);
        leaf(root);
        rightTraversal(root->right,0);
        return ans;
    }
};