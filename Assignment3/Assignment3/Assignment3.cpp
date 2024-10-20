#include <iostream>
#include "InfixToPostfixConverter.h"
#include "PostfixEvaluator.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
    string infix = "(6 + 2) * 5 - 8 / 4";
    InfixToPostfixConverter converter = InfixToPostfixConverter(infix);
    converter.convertToPostFix();
    converter.printPostfix();
    string postfix = converter.getPostfix();
    PostfixEvaluator postfixConverter = PostfixEvaluator(postfix);
    cout << postfixConverter.evaluatePostfix() << endl;

    TreeNode* root = new TreeNode('E');
    root->left = new TreeNode('X');
    root->right = new TreeNode('U');
    root->left->left = new TreeNode('A');
    root->left->right = new TreeNode('F');
    root->right->right = new TreeNode('N');
    root->left->left->left = new TreeNode('M');

    BinaryTree tree;
    tree.setRoot(root);;

    cout << "Preorder Traversal: ";
    tree.preorderTraversal(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    tree.postorderTraversal(root);
    cout << endl;

    TreeNode* root2 = new TreeNode('*');
    root2->left = new TreeNode('+');
    root2->right = new TreeNode('3');
    root2->left->left = new TreeNode('1');
    root2->left->right = new TreeNode('2');

    BinaryTree tree2;
    tree2.setRoot(root2);

    tree2.inorderTraversal(root2);
    cout << endl;
    tree2.postFix(root2);

    cout << "Preorder, postorder, and inorder next function output (in that order): " << endl;
    TreeNode* pre = tree2.preorderNext(root2, root2->left);
    cout << pre->value << endl;
    TreeNode* post = tree2.postorderNext(root2, root2->left);
    cout << post->value << endl;
    TreeNode* in = tree2.inorderNext(root2, root2->left);
    cout << in->value << endl;
}