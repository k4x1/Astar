#pragma once
#include "Node.h"
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h> 
#include <queue>
#include <stack>

class Grid
{
private:
	int m_AmountOfCollectibles = 0;
public:
	//std::vector<std::vector<Node>> m_NodeArray;
	Node m_NodeArray[20][20];
	Node* m_EntranceNode = &m_NodeArray[0][0];
	Node* m_ExitNode;
	Node* m_Collectables[11];
	Node* m_gGoal[11];
	int m_valid = 0;
	float m_WeightPoints[11][11];
	int m_gridCount;
	void DrawNodes();
	void UpdateTypes(Node _CurrentNode);
	void Update();
	/*void DFS(Node* startNode, std::vector<bool>& visited, std::vector<Node*>& path);

	void RunDFS();*/
	void RunDFS(int _startNode);
	void RunBFS(int _startNode);

	void AssignWeights();
	float GetEuclideanDistance(int x1, int y1, int x2, int y2);
	Grid(std::string _File);
	~Grid();
};

