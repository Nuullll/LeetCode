class Solution {

    class TreeNode {
    public:
        TreeNode(int val, int size=1): val(val), size(size) {}

        int val;
        int size;

        TreeNode* left = NULL;
        TreeNode* right = NULL;
    };

public:
    int smallestDistancePair(vector<int>& nums, int k) {
        TreeNode* root = new TreeNode(nums[0] - nums[1], 0);
        if (root->val < 0) {
            root->val = -root->val;
        }

        // loop through all pairs
        int distance;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                distance = nums[i] - nums[j];
                if (distance < 0) {
                    distance = -distance;
                }
                update(distance, root);
            }
        }

        return queryKthDistance(k, root);
    }

    void update(int val, TreeNode* node) {
        node->size ++;

        if (val < node->val) {
            if (node->left == NULL) {
                node->left = new TreeNode(val);
            } else {
                update(val, node->left);
            }
        } else if (val > node-> val) {
            if (node->right == NULL) {
                node->right = new TreeNode(val);
            } else {
                update(val, node->right);
            }
        }

        return;
    }

    int queryKthDistance(int k, TreeNode* node) {

        int leftSize = node->left ? node->left->size : 0;
        int rightSize = node->right ? node->right->size : 0;

        if (k <= leftSize) {
            // k-th distance falls in the left child tree
            return queryKthDistance(k, node->left);
        } else if (k <= node->size - rightSize) {
            // k-th distance hits this node
            return node->val;
        } else {
            // k-th distance falls in the right child tree
            return queryKthDistance(k - (node->size - rightSize), node->right);
        }
    }
};
