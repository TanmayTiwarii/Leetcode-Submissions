/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    const int mod = 1e9+7;
    long long func(TreeNode* root, map<TreeNode*,int long long> &sum){
        if(!root){
            return 0;
        }
        int s=0;
        if(root->left){
            sum[root->left] = func(root->left,sum);
            s+=sum[root->left];
        }  
        if(root->right){
            sum[root->right] = func(root->right,sum);
            s+=sum[root->right];
        }
        return sum[root] = root->val + s; 
    }
    void calc(TreeNode* root, map<TreeNode*,int long long> &sum,int long long &ans,int long long &total){
        if(!root){
            return;
        }
        long long mult = 0;
        if(root->left){
            mult=sum[root->left]*(total-sum[root->left]);
            ans=max(ans,mult);
            calc(root->left,sum,ans,total);
        }
        if(root->right){
            mult=sum[root->right]*(total-sum[root->right]);
            ans=max(ans,mult);
            calc(root->right,sum,ans,total);
        }

    }
    int maxProduct(TreeNode* root) {
        map<TreeNode*,int long long> sum;
        func(root,sum);
        int long long total=sum[root];
        int long long ans=0;
        calc(root,sum,ans,total);
        return ans%mod;
    }
};