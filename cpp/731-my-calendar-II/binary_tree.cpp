class MyCalendarTwo {
    class TreeNode {
    public:
        TreeNode(int start, int end): start(start), end(end), count(1) {}

        int start;
        int end;
        TreeNode* left = NULL;
        TreeNode* right = NULL;

        int count;
    };

public:
    MyCalendarTwo() {}

    bool book(int start, int end) {

        // first book
        if (this->root == NULL) {
            this->root = new TreeNode(start, end);
            return true;
        }

        if (query(start, end, this->root)) {
            // update
            update(start, end, this->root);
            return true;
        }

        return false;
    }

    bool query(int start, int end, TreeNode* node) {
        // query if the given event is legal (not causing triple booking)

        if (node == NULL) {
            return true;
        }

        if (end <= node->start) {
            return query(start, end, node->left);
        } else if (start >= node->end) {
            return query(start, end, node->right);
        } else {
            if (node->count > 1) {
                return false;
            }

            vector<int> sorted = sortInterval(start, end, node->start, node->end);
            return query(sorted[0], sorted[1], node->left) && query(sorted[2], sorted[3], node->right);
        }
    }

    void update(int start, int end, TreeNode* node) {
        // update if the event will not cause triple booking

        if (end <= node->start) {
            if (node->left) {
                update(start, end, node->left);
            } else {
                node->left = new TreeNode(start, end);
            }
        } else if (start >= node->end) {
            if (node->right) {
                update(start, end, node->right);
            } else {
                node->right = new TreeNode(start, end);
            }
        } else {
            vector<int> sorted = sortInterval(start, end, node->start, node->end);

            node->start = sorted[1];
            node->end = sorted[2];
            node->count ++;

            update(sorted[0], sorted[1], node);
            update(sorted[2], sorted[3], node);
        }

        return;
    }

    vector<int> sortInterval(int start1, int end1, int start2, int end2) {
        vector<int> result;
        if (start1 <= start2) {
            if (end1 <= start2) {
                result = vector<int> {start1, end1, start2, end2};
            } else if (end1 <= end2) {
                result = vector<int> {start1, start2, end1, end2};
            } else {
                result = vector<int> {start1, start2, end2, end1};
            }
        } else {
            if (end2 <= start1) {
                result = vector<int> {start2, end2, start1, end1};
            } else if (end2 <= end1) {
                result = vector<int> {start2, start1, end2, end1};
            } else {
                result = vector<int> {start2, start1, end1, end2};
            }
        }

        return result;
    }

    TreeNode* root = NULL;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
