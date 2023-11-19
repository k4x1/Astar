#pragma once
#include "Grid.h"
#include <vector>
#include <cmath>
#include <algorithm>
class Walker
{
private:
	int GetDistance(Node _nodeA, Node _nodeB);
	void RetracePath(Node* _Start, Node* _End);
public:
	
	Node* m_CurrentNode;
	Node* m_StartingNode;
	std::vector<Node*> m_Neighbors;
	std::vector<Node*> m_Open;
	std::vector<Node*> m_Closed;
	Grid* m_GridReference;
	Node* m_wGoal[11]; //array goal x and ys, basically a vector2
	int m_CurrentGoalXY[2];
	int goalCount = 0;
	Walker(Grid _GridReference);
	~Walker();
	void InitWalker();
	void GetNeighbours();
	void FindPathAstar();
	
	
};

