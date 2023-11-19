#include "Node.h"

void Node::InitType()
{


}

Node::Node()
{

	m_NodeX = 0;
	m_NodeY = 0;
	m_Walkable = true;
	m_CharType = '.';
	m_type = type_clear;
	
	m_Gcost = 0;
	m_Hcost = 0;
	m_Fcost = 0;
}

Node::~Node()
{

}
