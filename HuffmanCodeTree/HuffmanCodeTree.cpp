// HuffmanCodeTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "symbolFreq.h"
#include "treeNodeClass.h"

int main()
{
	treeNodeClass newTreeNodeClass;
	newTreeNodeClass.pushNodesToContainer();
	newTreeNodeClass.createTree();
	newTreeNodeClass.getCodeWrapper();
	system("pause");
    return 0;
}

