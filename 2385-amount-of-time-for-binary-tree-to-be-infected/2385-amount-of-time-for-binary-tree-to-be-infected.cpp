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
    void build(TreeNode* root,map<TreeNode*,TreeNode*> &parent){
        if(!root){
            return ;
        }
        if(root->right){
            parent[root->right]=root;
            build(root->right,parent);
        }
        if(root->left){
            parent[root->left]=root;
            build(root->left,parent);
        }
    }

    int dfs(TreeNode* root,map<TreeNode*,TreeNode*> &parent,map<TreeNode*,int> &visited){
        if(!root){
            return 0;
        }
        int ans=0;
        visited[root]=1;
        if(visited[parent[root]]==0){
            ans = max(ans, 1 + dfs(parent[root],parent,visited));
        }
        if(root->left && visited[root->left]==0){
            ans = max(ans, 1 + dfs(root->left,parent,visited));
        }
        if(root->right && visited[root->right]==0){
            ans = max(ans, 1 + dfs(root->right,parent,visited));
        }
        return ans;

    }
    TreeNode* findNode(TreeNode* root, int start){
        if(!root){
            return NULL;
        }
        if(root->val==start){
            return root;
        }
        TreeNode* left = findNode(root->left,start);
        if(left){
            return left;
        }
        TreeNode* right = findNode(root->right,start); 
        if(right){
            return right;
        }
        return NULL;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> parent;
        map<TreeNode*,int> visited;
        build(root,parent);
        visited[parent[root]]=1;
        return dfs(findNode(root,start),parent,visited);
    }
};