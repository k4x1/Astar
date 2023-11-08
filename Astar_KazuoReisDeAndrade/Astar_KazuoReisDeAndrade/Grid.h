#pragma once
#include "Node.h"
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h> 

class Grid
{
private:
	int m_AmountOfCollectibles = 0;
public:
	//std::vector<std::vector<Node>> m_NodeArray;
	Node m_NodeArray[20][20];
	Node* m_EntranceNode;
	Node* m_ExitNode;
	Node* m_Collectables[10];
	void DrawNodes();
	void UpdateTypes(Node _CurrentNode);
	void Update();
	Grid(std::string _File);
	~Grid();
};

