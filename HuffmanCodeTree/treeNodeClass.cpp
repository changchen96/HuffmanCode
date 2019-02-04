#include "stdafx.h"
#include "treeNodeClass.h"
#ifndef TREENODECLASS_H
#define TREENODECLASS_H
#define SPACING  5
//allocation the priority queue dynamically
treeNodeClass::treeNodeClass()
{
	this->priorityQueue = new std::priority_queue<treeNode*, std::vector<treeNode *>, treeNode>;
}
//push nodes to queue
void treeNodeClass::pushNodesToContainer()
{
	string filename = "ToCompress.txt";
	newFreq.sortCount(filename);
	newFreq.sortFinal();
	for (int i = 0; i < newFreq.finalTable.size(); i++)
	{
		treeNode *newNode = setNewNode(newFreq.finalTable[i].first, newFreq.finalTable[i].second);
		priorityQueue->push(newNode);
	}
}
//sets a new node
treeNode* treeNodeClass::setNewNode(char newSymbol, int newValue)
{
	treeNode* newNode = new treeNode;
	newNode->symbol = newSymbol;
	newNode->value = newValue;
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;
	return newNode;
}
//sets the root node
treeNode * treeNodeClass::setRootNode(treeNode *tempNode)
{
	treeNode* rootNode = new treeNode;
	root = rootNode;
	return rootNode;
}
//creates the tree for display
void treeNodeClass::createTree()
{
	while (priorityQueue->size() > 1)
	{
		treeNode* node1 = priorityQueue->top();
		priorityQueue->pop();
		treeNode* node2 = priorityQueue->top();
		priorityQueue->pop();
		priorityQueue->push(mergeNode(node1, node2));
	}
	root = priorityQueue->top();
	priorityQueue->pop();
	delete priorityQueue;
}

//merge nodes together
treeNode* treeNodeClass::mergeNode(treeNode* nodeA, treeNode* nodeB)
{
	treeNode* mergedNode = new treeNode;
	mergedNode->leftNode = nodeA;
	mergedNode->rightNode = nodeB;
	mergedNode->value = nodeA->value + nodeB->value;
	setRootNode(mergedNode);
	return mergedNode;

}
//prints the binary tree
void treeNodeClass::printTree(treeNode* root, int space)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		space += SPACING;
		printTree(root->rightNode, space);
		//std::cout << "\n" << endl;
		for (int j = SPACING; j < space; j++)
		{
			std::cout << " ";
		}
		std::cout << root->symbol << "|" << root->value << std::endl;

		printTree(root->leftNode, space);
	}
}
//called from the main function
void treeNodeClass::printWrapper()
{
	printTree(root, 0);
}
//retrieves the huffman codes
void treeNodeClass::getCodes(treeNode* root)
{
	if (root->leftNode == NULL && root->rightNode == NULL)
	{
		cout << root->symbol << "|" << huffmanCode << endl;
		huffmanCode.pop_back();
		return;
	}
	if (root->leftNode != NULL)
	{
		huffmanCode.push_back('0');
		getCodes(root->leftNode);
	}
	if (root->rightNode != NULL)
	{
		huffmanCode.push_back('1');
		getCodes(root->rightNode);
	}
	if (huffmanCode.size())
	{
		huffmanCode.pop_back();
	}
	return;
}

void treeNodeClass::getCodeWrapper()
{
	getCodes(root);
}



#endif





