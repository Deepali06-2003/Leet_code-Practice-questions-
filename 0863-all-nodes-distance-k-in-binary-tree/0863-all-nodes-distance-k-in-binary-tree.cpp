/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode* , TreeNode*>map;
        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){

            TreeNode* t = q.front();
            q.pop();

            if(t->left){
                q.push(t->left);
                map[t->left] = t;
            }

            if(t->right){
                q.push(t->right);
                map[t->right] = t;
            }
        }


        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int dist =0;

        while(!q.empty()){
            int size = q.size();

            if(dist == k)break;

            dist++;

            for(int i =0;i<size;i++){
                TreeNode* t = q.front();
                q.pop();

                if(t->left && !visited.count(t->left)){
                    q.push(t->left);
                    visited.insert(t->left);
                }

                if(t->right && !visited.count(t->right)){
                    q.push(t->right);
                    visited.insert(t->right);
                }

                if(map.count(t) && !visited.count(map[t])){
                    q.push(map[t]);
                    visited.insert(map[t]);
                }
            }

        }

        vector<int>res;

        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;

    }
};