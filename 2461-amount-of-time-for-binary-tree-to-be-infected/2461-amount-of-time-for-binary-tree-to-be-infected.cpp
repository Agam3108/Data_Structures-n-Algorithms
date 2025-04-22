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
TreeNode* mark(TreeNode* root,int start,unordered_map<TreeNode*,TreeNode*>& parent){
    TreeNode* front = NULL;
    queue<TreeNode*> q;
    q.push(root);
    parent[root] = NULL;
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr->val == start){
            front = curr;

        }
        if(curr->left){
            q.push(curr->left);
            parent[curr->left] = curr;
        }
        if(curr->right){
            q.push(curr->right);
            parent[curr->right] = curr;
        }
    }
    return front;
}
    int amountOfTime(TreeNode* root, int start) {
         unordered_map<TreeNode* , TreeNode*> parent_track ;
         TreeNode* startNode = mark(root,start,parent_track);
         queue<TreeNode*> q;
         q.push(startNode);
         int time = 0;
         unordered_map<TreeNode*,bool> vis ;
         vis[startNode] = true;
         while(!q.empty()){
            int size = q.size();
            bool isInfected = false;
            for(int i = 0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                  q.push(curr->left);
                  vis[curr->left] = true;
                  isInfected = true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                    isInfected = true;
                }
                if(parent_track[curr] && !vis[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]] = true ;
                    isInfected = true;
                }
            }
            if(isInfected)
            time++;
         }
         return time ;
    }
};