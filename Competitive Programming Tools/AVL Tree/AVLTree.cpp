#include<iostream>
using namespace std;
struct Node{
    Node * left;
    Node * right;
    int h;
    int val;
    Node(int x){
        left = NULL;
        right = NULL;
        val = x;
        h = 1;
    }
};
class AVLTree{
public:
    Node *rt;
    AVLTree(int x){
        rt = new Node(x);
    }
    int getHeight(Node *root){
        if(!root) return 0;
        return root->h;
    }
    void traversal(Node *root){
        if(!root) return;
        cout << root->val << " ";
        traversal(root->left);
        traversal(root->right);
    }
    void LRotation(Node *root,Node *par){
        Node *right = root->right;
        int l = getHeight(right->left);
        int r = getHeight(right->right);
        if(l > r){
            Node *rl = right->left;
            Node *rll = rl->left;
            Node *rlr = rl->right;
            rl->left = root;
            root->right = rll;
            rl->right = right;
            right->left = rlr;
            root->h = max(getHeight(root->left),getHeight(root->right))+1;
            right->h = max(getHeight(right->left),getHeight(right->right))+1;
            rl->h = max(getHeight(rl->left),getHeight(rl->right))+1;
            if(root == rt){
                rt = rl;
            }
            if(par){
                if(root == par->left){
                    par->left = rl;
                }else{
                    par->right = rl;
                }
            }
        }else{
            Node *temp = right->left;
            right->left = root;
            root->right = temp;
            root->h = max(getHeight(root->left),getHeight(root->right))+1;
            right->h = max(getHeight(right->left),getHeight(right->right))+1;
            if(root == rt){
                rt = right;
            }
            if(par){
                if(root == par->left){
                    par->left = right;
                }else{
                    par->right = right;
                }
            }
        }
    }
    void RRotation(Node *root,Node *par){
        Node *left = root->left;
        int l = getHeight(left->left);
        int r = getHeight(left->right);
        if(l > r){
            Node *temp = left->right;
            left->right = root;
            root->left = temp;
            root->h = max(getHeight(root->left),getHeight(root->right))+1;
            left->h = max(getHeight(left->left),getHeight(left->right))+1;
            if(root == rt){
                rt = left;
            }
            if(par){
                if(root == par->left){
                    par->left = left;
                }else{
                    par->right = left;
                }
            }
        }else{
            Node *lr = left->right;
            Node *lrl = lr->left;
            Node *lrr = lr->right;
            lr->right = root;
            lr->left = left;
            left->right = lrl;
            root->left = lrr;
            root->h = max(getHeight(root->left),getHeight(root->right))+1;
            left->h = max(getHeight(left->left),getHeight(left->right))+1;
            lr->h = max(getHeight(lr->left),getHeight(lr->right))+1;
            if(root == rt){
                rt = lr;
            }
            if(par){
                if(root == par->left){
                    par->left = lr;
                }else{
                    par->right = lr;
                }
            }
        }
    }
    void insert(Node *root,Node *par,int key){
        if(!root){
            if(key > par->val){
                par->right = new Node(key);
            }else{
                par->left = new Node(key);
            }
            return;
        }
        if(key > root->val){
            insert(root->right,root,key);
        }else{
            insert(root->left,root,key);
        }
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        root->h = max(l,r) + 1;
        if(abs(l-r) > 1){
            if(l > r){
                RRotation(root,par);
            }else{
                LRotation(root,par);
            }
        }

    }
};
int main(){
    AVLTree T(30);
    T.insert(T.rt,NULL,20);
    T.insert(T.rt,NULL,25);
    T.traversal(T.rt);
    return 0;
}
