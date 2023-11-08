#pragma once
#include "Grid.h"
#include <vector>
class Walker
{
public:
	
	Node* m_CurrentNode;
	std::vector<Node>* m_Neighbors;
	std::vector<Node>* m_Open;
	std::vector<Node>* m_Closed;
	Grid* m_GridReference;

	Walker(Grid _GridReference);
	~Walker();
	void GetNeighbours();
	void CheckLowestFcost();
};

