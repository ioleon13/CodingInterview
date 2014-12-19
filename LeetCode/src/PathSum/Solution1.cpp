/*
 * Solution1.cpp
 *
 *  Created on: 2014-12-19
 *      Author: liya
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *             5
 *            / \
 *           4   8
 *          /   / \
 *         11  13  4
 *        /  \      \
 *       7    2      1
 *
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTree(int a[], int n) {
	if (n <= 0) {
		return NULL;
	}

	TreeNode** tree = new TreeNode*[n];

	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			tree[i] = NULL;
			continue;
		}
		tree[i] = new TreeNode(a[i]);
	}

	int pos = 1;
	for (int i = 0; i < n && pos < n; ++i) {
		if (tree[i]) {
			tree[i]->left = tree[pos++];
			if (pos < n) {
				tree[i]->right = tree[pos++];
			}
		}
	}

	return tree[0];
}

void printTree(TreeNode *root) {
	if(root == NULL) {
		printf("# ");
		return;
	}

	printf("%d ", root->val);

	printTree(root->left);
	printTree(root->right);
}

bool hasPathSum(TreeNode *root, int sum) {
	if (root == NULL) {
		//printf("error: root is null");
		return false;
	}

	if (root->left == NULL && root->right == NULL) {
		printf("the leaf is:%d\r\n", root->val);
		if (root->val == sum) {
			printf("It has a root-to-leaf path, the leaf is:%d\r\n", root->val);
			return true;
		}
	}
	//printf("the node is:%d\r\n", root->val);

	return hasPathSum(root->left, sum-root->val)
			|| hasPathSum(root->right, sum-root->val);

	/*if (root->left != NULL) {
		return hasPathSum(root->left, sum-root->val);
	} else{
		return hasPathSum(root->right, sum-root->val);
	}*/

	//return false;
}

int main() {
	TreeNode* tree;

	int a[] = { 5, 4, 8, 11, 0, 13, 4, 7, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0  };
	tree = createTree(a, sizeof(a) / sizeof(int));
	cout << "The tree is:" << endl; // print the tree
	printTree(tree);
	cout << endl;

	bool bHasPath = hasPathSum(tree, 22);
	printf("Has or not: %s\r\n", bHasPath ? "yes" : "no");
	return 0;
}



