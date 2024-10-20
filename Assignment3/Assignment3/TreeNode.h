#pragma once

class TreeNode {
public:
    char value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }

    int getValue() {
        return value;
    }
};
