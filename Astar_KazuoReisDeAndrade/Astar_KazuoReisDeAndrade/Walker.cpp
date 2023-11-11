#include "Walker.h"

Walker::Walker(Grid _GridReference)
{
	m_GridReference = &_GridReference;
	m_CurrentNode = _GridReference.m_EntranceNode;
}

Walker::~Walker()
{
}

void Walker::GetNeighbours()
{
	/*for (int i = 0; i < (sizeof(m_GridReference->m_NodeArray) / sizeof(m_GridReference->m_NodeArray[0])); i++)
	{
		for (int j = 0; j < (sizeof(m_GridReference->m_NodeArray)[0] / sizeof(m_GridReference->m_NodeArray[0][0])); j++)
		{
			std::cout<<m_Neighbors[
		}
	}*/
	for (int i = 0; i < sizeof(m_Neighbors); i++) {
		std::cout<<m_Neighbors[i]<<std::endl;

	}
}

void Walker::CheckLowestFcost()
{
	/*
	first check all neighbour tiles and add them to open tile
	*/
//	std::cout << m_CurrentNode->NeighbourCount;
	for (int i = 0; i < m_CurrentNode->NeighbourCount; i++) {
	//	std::cout << "a";
	//	m_Open.push_back(m_CurrentNode->m_Neighbours[i]);
		//std::cout << m_Open[i]->m_CharType << std::endl;
		
	}

	/*
	assign H and g costs to all open tiles 
	calculate f cost
	find lowest f cost
	check if theres a tie and choose 
	move walker to that position
	close the node
	repeat

	*/
}
