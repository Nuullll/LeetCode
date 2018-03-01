class MyCalendarThree {
    class TreeNode {
    public:
        TreeNode(int start, int end): start(start), end(end), count(1) {}
        TreeNode(int start, int end, int count): start(start), end(end), count(count) {}

        int start;
        int end;
        TreeNode* left = NULL;
        TreeNode* right = NULL;

        int count;
    };

public:
    MyCalendarThree() {}

    int book(int start, int end) {

        // first book
        if (this->root == NULL) {
            this->root = new TreeNode(start, end);
            this->busyCount = 1;
        } else {
            update(start, end, this->root);
        }

        return busyCount;
    }

    void update(int start, int end, TreeNode* node, int count=1) {

        if (end <= node->start) {
            if (node->left) {
                update(start, end, node->left, count);
            } else {
                node->left = new TreeNode(start, end, count);
            }
        } else if (start >= node->end) {
            if (node->right) {
                update(start, end, node->right, count);
            } else {
                node->right = new TreeNode(start, end, count);
            }
        } else {
            // four overlapping situations
            int nodeStart = node->start;
            int nodeEnd = node->end;

            if (start <= nodeStart && nodeStart <= end && end <= nodeEnd) {
                // update overlapped interval
                node->end = end;
                node->count ++;

                // update left and right non-overlapped intervals
                update(start, node->start, node, 1);
                update(node->end, nodeEnd, node, node->count-1);    // original count
            } else if (start <= nodeStart && nodeEnd <= end) {
                node->count ++;

                update(start, node->start, node, 1);
                update(node->end, end, node, 1);
            } else if (nodeStart <= start && end <= nodeEnd) {
                node->start = start;
                node->end = end;
                node->count ++;

                update(nodeStart, node->start, node, node->count-1);
                update(node->end, nodeEnd, node, node->count-1);
            } else {
                node->start = start;
                node->count ++;

                update(nodeStart, node->start, node, node->count-1);
                update(node->end, end, node, 1);
            }

            this->busyCount = max(this->busyCount, node->count);
        }

        return;
    }

    TreeNode* root = NULL;
    int busyCount = 0;
};
