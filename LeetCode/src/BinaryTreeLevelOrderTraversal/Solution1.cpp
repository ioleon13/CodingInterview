/*
 * Solution1.cpp
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 *
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 *
 * OJ's Binary Tree Serialization:
 *
 * The serialization of a binary tree follows a level order traversal, where '#' signifies
 * a path terminator where no node exists below.
 *
 * Here's an example:
 *
 *    1
 *   / \
 *  2   3
 *     /
 *    4
 *     \
 *      5
 *
 * The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
 *  Created on: 2014-11-22
 *      Author: liya
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
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

void printResult(vector<vector<int> > &order) {
	cout<<"["<<endl;
	for (int i = 0; i < order.size(); ++i) {
		cout<<"  [";
		for (int j = 0; j < order[i].size(); ++j) {
			cout<<order[i][j];
			if (j != order[i].size()-1) {
				cout<<",";
			}
		}
		if (i == order.size()-1) {
			cout<<"]"<<endl;
		} else {
			cout<<"],"<<endl;
		}
	}
	cout<<"]"<<endl;
}

vector<vector<int> > levelOrder(TreeNode *root) {
	vector<vector<int> > ret;

	if (root == NULL) {
		return ret;
	}

	vector<int> level;
	level.push_back(root->val);
	ret.push_back(level);

	//save the tree node in a vector by level order
	vector<TreeNode*> vecNode;
	queue<TreeNode*> queueTemp;
	queueTemp.push(root);
	while(queueTemp.size() > 0) {
		TreeNode *node = queueTemp.front();
		queueTemp.pop();
		vecNode.push_back(node);
		if (node == NULL) {
			continue;
		}

		queueTemp.push(node->left);
		queueTemp.push(node->right);
	}

	//traversal the vector
	int num = 2;
	int j = 0;
	for (int i = 1; i < vecNode.size(); i = j) {
		level.clear();

		int count = 0;
		for (j = i; j < i+num && j < vecNode.size(); ++j) {
			if (vecNode[j]) {
				level.push_back(vecNode[j]->val);
				count += 2;
			}
		}

		num = count;

		if (level.size() > 0) {
			ret.push_back(level);
		}
	}

	return ret;
}

int main() {
	TreeNode* tree;
	vector<vector<int> > order;

	int a[] = {1, 2, 3, 0, 0, 4, 0, 0, 5};
	tree = createTree(a, sizeof(a)/sizeof(int));
	cout << "The tree is:" << endl; // print the tree
	printTree(tree);

	order = levelOrder(tree);
	cout << "The level order traversal of the tree is:" << endl;
	printResult(order);
	return 0;
}


