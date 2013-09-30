#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct GraphNode
{
	int nValue;
	vector<GraphNode*> vecNeighbors;
	
	GraphNode()
		: nValue(0)
	{}
	
	GraphNode(int data, int size)
		: nValue(data)
		{
			for(int i = 0; i < size; ++i)
			{
				GraphNode* node = NULL;
				vecNeighbors.push_back(node);
			}
		}
		
	GraphNode(const GraphNode& node)
		: nValue(node.nValue)
		{
			for(size_t i = 0; i < node.vecNeighbors.size(); ++i)
			{
				vecNeighbors.push_back(node.vecNeighbors[i]);
			}
		}
		
	GraphNode & operator = (const GraphNode& node)
	{
		if(this != &node)
		{
			nValue = node.nValue;
			for(size_t i = 0; i < node.vecNeighbors.size(); ++i)
			{
				vecNeighbors.push_back(node.vecNeighbors[i]);
			}
		}
		
		return *this;
	}
};


//breadth-first search
GraphNode* cloneBFS(GraphNode* root)
{
	if(NULL == root)
		return NULL;
		
	GraphNode* dupRoot = new GraphNode();
	dupRoot->nValue = root->nValue;
	
	queue<GraphNode*> que;
	que.push(root);
	
	map<GraphNode*, GraphNode*> hash;
	hash.insert(make_pair(root, dupRoot));
	
	while(!que.empty())
	{
		GraphNode* top = que.front();
		que.pop();
		vector<GraphNode*> vec = top->vecNeighbors;
		hash[top]->vecNeighbors = vector<GraphNode*>(vec.size());
		
		for(size_t i = 0; i < vec.size(); ++i)
		{
			if(NULL == vec[i])
				hash[top]->vecNeighbors[i] = NULL;
			else
			{
				if(!hash.count(vec[i]))
				{
					hash[top]->vecNeighbors[i] = new GraphNode();
					hash[top]->vecNeighbors[i]->nValue = vec[i]->nValue;
					que.push(vec[i]);
					hash.insert(make_pair(vec[i], hash[top]->vecNeighbors[i]));
				}
				else
				{
					hash[top]->vecNeighbors[i] = hash[vec[i]];
				}
			}
		}
	}
	
	return dupRoot;
}


//Depth-first search
GraphNode* cloneDFS(GraphNode* root, map<GraphNode*, GraphNode*>& hash)
{
	if(NULL == root)
	{
		return NULL;
	}
	
	if(hash.count(root))
	{
		return hash[root];
	}
	
	int nSize = root->vecNeighbors.size();
	GraphNode* dupNode = new GraphNode(root->nValue, nSize);
	
	hash.insert(make_pair(root, dupNode));
	
	for(int i = 0; i < nSize; ++i)
	{
		dupNode->vecNeighbors[i] = cloneDFS(root->vecNeighbors[i], hash);
	}
	
	return dupNode;
}


int main()
{
	//init a graph
	GraphNode* n0 = new GraphNode(0, 3);
	GraphNode* n1 = new GraphNode(1, 1);
	GraphNode* n2 = new GraphNode(2, 1);
	GraphNode* n3 = new GraphNode(3, 3);
	GraphNode* n4 = new GraphNode(4, 1);
	
	n0->vecNeighbors[0] = n1;
	n0->vecNeighbors[1] = n2;
	n0->vecNeighbors[2] = n3;
	
	n1->vecNeighbors[0] = n2;
	
	n2->vecNeighbors[0] = n3;
	
	n3->vecNeighbors[0] = n0;
	n3->vecNeighbors[1] = n1;
	n3->vecNeighbors[2] = n4;
	
	n4->vecNeighbors[0] = n3;
	
	map<GraphNode*, GraphNode*> hash;
	GraphNode* dupNode = cloneDFS(n0, hash);
	
	return 0;
}