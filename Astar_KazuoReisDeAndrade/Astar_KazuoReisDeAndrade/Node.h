#pragma once
#include <iostream>
enum NodeType {
	type_clear,
	type_wall,
	type_entrance,
	type_exit,
	type_collectable 
};
class Node
{
public: 
	int m_NodeX;
	int m_NodeY;
	bool m_Walkable;
	char m_CharType;
	Node* m_Neighbours[8];
	int m_Gcost; //distance from starting node
	int m_Hcost; //distance from exit node
	int m_Fcost; //G + H
	int NeighbourCount = 0;

	NodeType m_type;
	void InitType();
	//Node* m_Neighbours[8];
	Node();
	~Node();
};
