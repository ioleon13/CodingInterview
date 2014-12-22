/*
 * Solution1.cpp
 *
 *  Created on: 2014-12-22
 *      Author: liya
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
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

int getDepth(TreeNode *root) {
	if (root == NULL) {
		return 0;
	}

	int left = 1, right = 1;

	left += getDepth(root->left);
	right += getDepth(root->right);

	return left > right ? left : right;
}

bool isBalanced(TreeNode *root) {
	if (root == NULL) {
		return true;
	}

	int left = getDepth(root->left);
	int right = getDepth(root->right);

	if (left - right > 1 || right - left > 1) {
		printf("not balanced, root:%d, left depth:%d, right depth:%d\r\n", root->val, left, right);
		return false;
	}

	return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
	TreeNode* tree;

	int a[] = { 5, 4, 8, 11, 0, 13, 4, 7, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0  };
	tree = createTree(a, sizeof(a) / sizeof(int));
	cout << "The tree is:" << endl; // print the tree
	printTree(tree);
	cout << endl;

	bool isBalance = isBalanced(tree);
	printf("The tree is balance? %s", isBalance ? "yes" : "no");
	return 0;
}



