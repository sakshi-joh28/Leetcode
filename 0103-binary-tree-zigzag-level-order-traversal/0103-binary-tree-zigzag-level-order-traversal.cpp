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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>fin;
        if(root==NULL)
            return fin;
    vector<int>ans;
        int c=0;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
             vector<int>ans;
            for(int i=0;i<size;i++)
            {
                 TreeNode * front=q.front();
                   q.pop();
            ans.push_back(front->val);
                if(front->left!=NULL)
                    q.push(front->left);
                if(front->right!=NULL)
                    q.push(front->right);
            }
            if(c==1)
            {
                reverse(ans.begin(),ans.end());
            fin.push_back(ans);
            c=0;
                          }
                         
            else{
                fin.push_back(ans);
                          c=1;
        }
                          }
        return fin;
    }
};