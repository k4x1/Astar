#include "Walker.h"

Walker::Walker(Grid _GridReference)
{
	m_GridReference = &_GridReference;
	
}

Walker::~Walker()
{
}

void Walker::InitWalker()
{
	if(goalCount==0){
		m_CurrentNode = m_GridReference->m_EntranceNode;
		m_StartingNode = m_CurrentNode;
		for (int i = 0; i < 11; i++) {
			m_wGoal[i] = m_GridReference->m_gGoal[i];

		}
	}
	//goalCount = 2;

	m_CurrentGoalXY[0] = m_wGoal[goalCount]->m_NodeX;
	m_CurrentGoalXY[1] = m_wGoal[goalCount]->m_NodeY;

}

void Walker::GetNeighbours()
{
	m_Neighbors.clear();
	for (int i = 0; i < m_CurrentNode->NeighbourCount; i++) {
		m_Open.push_back(m_CurrentNode->m_Neighbours[i]);
	}
}

void Walker::FindPathAstar()
{
	/*
		first check all neighbour tiles and add them to open tile
	*/
	m_Open.push_back(m_StartingNode);
	//GetNeighbours();
/*
	for (int i = 0; i < m_Open.size(); i++) {
		std::cout << m_Open[i]->m_CharType;

		// Calculate g(n)
		//get lowest number 

		int gCost = 0;
		int hCost = 0;

		int DistanceX = abs(m_Open[i]->m_NodeX - m_CurrentGoalXY[0]);
		int DistanceY = abs(m_Open[i]->m_NodeY - m_CurrentGoalXY[1]);
		if (DistanceX > DistanceY) {
			hCost = (14 * DistanceY) + (10 * (DistanceX - DistanceY));
		}
		else {
			hCost = (14 * DistanceX) + (10 * (DistanceY - DistanceX));
		}
		DistanceX = abs(m_Open[i]->m_NodeX - m_StartingNode->m_NodeX);
		DistanceY = abs(m_Open[i]->m_NodeY - m_StartingNode->m_NodeY);
		if (DistanceX > DistanceY) {
			gCost = (14 * DistanceY) + (10 * (DistanceX - DistanceY));
		}
		else {
			gCost = (14 * DistanceX) + (10 * (DistanceY - DistanceX));
		}




		//	std::cout <<i<<"x: "<< m_Open[i]->m_NodeX << std::endl;
			//std::cout <<i<< "y: "<<m_Open[i]->m_NodeY << std::endl;
		std::cout << gCost << " | " << hCost << std::endl;

		m_Open[i]->m_Hcost = hCost;
		m_Open[i]->m_Gcost = gCost;

		m_Open[i]->m_Fcost = gCost + hCost;

		/*assign H and g costs to all open tiles
		calculate f cost
		
		
	}
*/ std::cout << m_Open.size();
	
	while (!m_Open.empty()) {
	
		Node* CurrentLookingAt = m_Open[0];
		int Count = 0;
		for (int i = 1; i < m_Open.size(); i++)
		{
			if (m_Open[i]->m_Fcost < CurrentLookingAt->m_Fcost
				|| (m_Open[i]->m_Fcost == CurrentLookingAt->m_Fcost) &&
				m_Open[i]->m_Hcost < CurrentLookingAt->m_Hcost)
			{
				
				CurrentLookingAt = m_Open[i];
				Count++;
				
			}
		}
		//std::cout << CurrentLookingAt<< "| "<< m_wGoal[goalCount]<<std::endl;
		m_Open.erase(m_Open.begin() + Count);
		m_Closed.push_back(CurrentLookingAt);
		if (CurrentLookingAt == m_wGoal[goalCount]) {
			RetracePath(m_StartingNode, m_wGoal[goalCount]);
			m_StartingNode = m_wGoal[goalCount];
			goalCount++;
			m_Open.clear();
			m_Closed.clear();
			std::cout << goalCount;
			
			return;
		}
		/*std::cout << "jk" << std::endl;
		std::cout << m_wGoal[goalCount]->m_CharType << std::endl;
		std::cout << CurrentLookingAt->m_CharType << std::endl;*/
		for (int i = 0; i < CurrentLookingAt->NeighbourCount; i++)
		{
			
			if (!CurrentLookingAt->m_Neighbours[i]->m_Walkable || (std::find(m_Closed.begin(), m_Closed.end(), CurrentLookingAt->m_Neighbours[i]) != m_Closed.end())) {
				continue;
				
			}
			
			int newCostToNeighbour = CurrentLookingAt->m_Gcost + GetDistance(*CurrentLookingAt, *CurrentLookingAt->m_Neighbours[i]);
		//	std::cout << "laa: " << newCostToNeighbour << "fsd: "<< m_CurrentNode->m_Neighbours[i]->m_Gcost<<std::endl;
		//	std::cout << "f: " << (newCostToNeighbour > m_CurrentNode->m_Neighbours[i]->m_Gcost) << "g: " << !(std::find(m_Open.begin(), m_Open.end(), m_CurrentNode->m_Neighbours[i]) != m_Open.end())<< std::endl;
			if (newCostToNeighbour < CurrentLookingAt->m_Neighbours[i]->m_Gcost || !(std::find(m_Open.begin(), m_Open.end(), CurrentLookingAt->m_Neighbours[i]) != m_Open.end())) {
				//std::cout << "st35e" << std::endl;
				CurrentLookingAt->m_Neighbours[i]->m_Gcost = newCostToNeighbour;
				CurrentLookingAt->m_Neighbours[i]->m_Hcost = GetDistance(*CurrentLookingAt->m_Neighbours[i], *m_wGoal[goalCount]);
				CurrentLookingAt->m_Neighbours[i]->m_Fcost = CurrentLookingAt->m_Neighbours[i]->m_Gcost + CurrentLookingAt->m_Neighbours[i]->m_Hcost;
				CurrentLookingAt->m_Neighbours[i]->m_Parent = CurrentLookingAt;
				//std::cout << "current: " << m_CurrentNode->m_Neighbours[i]->m_Parent->m_CharType <<" | "<< CurrentLookingAt->m_CharType << std::endl;
			//	std::cout << "Afafaf"<<std::endl;;
				if (!(std::find(m_Open.begin(), m_Open.end(), CurrentLookingAt->m_Neighbours[i]) != m_Open.end())) {

					m_Open.push_back(CurrentLookingAt->m_Neighbours[i]);
				}

			}
		}
	}
	/*
	find lowest f cost
	check if theres a tie and choose 
	move walker to that position
	close the node
	repeat

	*/
}
void Walker::gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}





int Walker::GetDistance(Node _nodeA, Node _nodeB)
{
	int DistanceX = abs(_nodeA.m_NodeX - _nodeB.m_NodeX);
	int DistanceY = abs(_nodeA.m_NodeY - _nodeB.m_NodeY);
	if (DistanceX > DistanceY) {
		return  (14 * DistanceY) + (10 * (DistanceX - DistanceY));
	}
	else {
		return  (14 * DistanceX) + (10 * (DistanceY - DistanceX));
	}
	
}

void Walker::RetracePath(Node* _Start, Node* _End)
{
	
	/*std::cout << "path:" << std::endl;
	std::cout << _Start->m_CharType << std::endl;
	std::cout << _End->m_CharType << std::endl;*/
	std::vector<Node*> Path;
	Node* CurrentNode = _End;
	int PathSize = 0;
	
	while (CurrentNode != _Start) {
	//	std::cout << "curr: " << CurrentNode->m_CharType << std::endl;
		Path.push_back(CurrentNode);
	//	std::cout << "x: " << CurrentNode->m_NodeX << "| y: " << CurrentNode->m_NodeY << std::endl;
		CurrentNode = CurrentNode->m_Parent;
		PathSize++;

		
	}
	
	std::reverse(Path.begin(), Path.end());
	for (int i = 0; i < PathSize; i++)
	{
		gotoxy((Path[i]->m_NodeX*2)+1, Path[i]->m_NodeY);
		std::cout << "P";
	}
	gotoxy(0, 30);
	

}
