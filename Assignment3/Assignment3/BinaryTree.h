#include <iostream>
#include <queue>
#include <iomanip> // for std::setw
#include <vector>
#include "TreeNode.h"
#include "InfixToPostfixConverter.h"

using namespace std;

class BinaryTree {
private:
    TreeNode* root;
    string inorderResult;

    void inorderString(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        inorderString(node->left);

        inorderResult += node->value;

        inorderString(node->right);
    }

    void preorderListTraversal(TreeNode* node, vector<TreeNode*>& preorderList) {
        if (node == nullptr) {
            return;
        }
        preorderList.push_back(node);
        preorderListTraversal(node->left, preorderList);
        preorderListTraversal(node->right, preorderList);
    }

    void postorderListTraversal(TreeNode* node, vector<TreeNode*>& postorderList) {
        if (node == nullptr) return;
        postorderListTraversal(node->left, postorderList);
        postorderListTraversal(node->right, postorderList);
        postorderList.push_back(node);
    }

    void inorderListTraversal(TreeNode* node, vector<TreeNode*>& inorderList) {
        if (node == nullptr) return;
        inorderListTraversal(node->left, inorderList);
        inorderList.push_back(node);
        inorderListTraversal(node->right, inorderList);
    }


public:
    BinaryTree() {
        root = nullptr;
    }

    TreeNode* getRoot() {
        return root;
    }

    void setRoot(TreeNode* newRoot) {
        root = newRoot;
    }

    void preorderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->value;

        preorderTraversal(node->left);
        
        preorderTraversal(node->right);
    }

    TreeNode* preorderNext(TreeNode* root, TreeNode* v) {
        vector<TreeNode*> preorderList;
        preorderListTraversal(root, preorderList);

        for (int i = 0; i < preorderList.size(); ++i) {
            if (preorderList[i] == v) {
                if (i + 1 < preorderList.size()) {
                    return preorderList[i + 1]; 
                }
                return nullptr;
            }
        }
        return nullptr;
    }

    void postorderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        postorderTraversal(node->left);

        postorderTraversal(node->right);

        cout << node->value;
    }

    TreeNode* postorderNext(TreeNode* root, TreeNode* v) {
        vector<TreeNode*> postorderList;
        postorderListTraversal(root, postorderList);

        for (int i = 0; i < postorderList.size(); ++i) {
            if (postorderList[i] == v) {
                if (i + 1 < postorderList.size()) {
                    return postorderList[i + 1];  // Return the next node
                }
                return nullptr;  // No next node (v is the last node in postorder traversal)
            }
        }
        return nullptr;  // Node v not found
    }

    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        inorderTraversal(node->left);

        cout << node->value;

        inorderTraversal(node->right);
    }

    TreeNode* inorderNext(TreeNode* root, TreeNode* v) {
        vector<TreeNode*> inorderList;
        inorderListTraversal(root, inorderList);

        for (int i = 0; i < inorderList.size(); ++i) {
            if (inorderList[i] == v) {
                if (i + 1 < inorderList.size()) {
                    return inorderList[i + 1];
                }
                return nullptr;
            }
        }
        return nullptr;
    }
    
    void postFix(TreeNode* node) {
        inorderResult = "";
        inorderString(node);
        InfixToPostfixConverter converter = InfixToPostfixConverter(inorderResult);
        converter.convertToPostFix();
        converter.printPostfix();
    }

    string getResult() {
        return inorderResult;
    }
};
