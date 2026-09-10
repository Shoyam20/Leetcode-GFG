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
int result=0;
    pair<int,int> countavg(TreeNode *root )
    {
        if(root==NULL)
        {
            return {0,0};
        }

        //go left
        auto p1=countavg(root->left);
        //go right
        auto p2=countavg(root->right);

        int totalsum=p1.first+p2.first+root->val;
        int totalcount=p1.second+p2.second+1;

        if(totalsum/totalcount==root->val) result++;
        return {totalsum,totalcount};
    }
    int averageOfSubtree(TreeNode* root) {
        countavg(root);
        return result;
    }
};