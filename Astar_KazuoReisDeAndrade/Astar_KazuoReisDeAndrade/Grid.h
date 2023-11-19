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
	Node* m_EntranceNode = &m_NodeArray[0][0];
	Node* m_ExitNode;
	Node* m_Collectables[10];
	Node* m_gGoal[11];
	int m_valid = 0;
	int m_gridCount;
	void DrawNodes();
	void UpdateTypes(Node _CurrentNode);
	void Update();
	void AssignWeights();
	Grid(std::string _File);
	~Grid();
};

