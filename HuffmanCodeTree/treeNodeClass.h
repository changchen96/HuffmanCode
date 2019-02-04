#pragma once
#include "symbolFreq.h"
#ifndef SYMBOLFREQ_H
#define SYMBOLFREQ_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

struct treeNode
{
	int value;
	char symbol;
	treeNode* leftNode;
	treeNode* rightNode;
	treeNode* nodeA;
	treeNode* tempNode;
	treeNode* nodeB;
	treeNode* nodeInQueue;
	bool operator()(const treeNode* nodeA, const treeNode* nodeB) const
	{
		return nodeA->value > nodeB->value;
	}
};

class treeNodeClass
{
	//creates an instance of the symbolFreq class
	symbolFreq newFreq;

private:
	//std::priority_queue <treeNode*, std::vector<treeNode*>, treeNode> temp;
	std::priority_queue <treeNode*, std::vector<treeNode*>, treeNode>* priorityQueue;
	treeNode* root;
	int space;
	string huffmanCode;
public:
	treeNodeClass();
	void pushNodesToContainer();
	void createTree();
	treeNode* mergeNode(treeNode* , treeNode*);
	treeNode* setNewNode(char, int);
	treeNode* setRootNode(treeNode*);
	void printTree(treeNode*, int);
	void printWrapper();
	void getCodes(treeNode*);
	void getCodeWrapper();
};

#endif // !TREECLASS_H