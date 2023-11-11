#include "Node.h"

void Node::InitType()
{
	/*switch (m_CharType)
	{
	case '.':
		m_type = type_clear;
		break;	
	case 'w':
		m_type = type_wall;
		break;	
	case 's':
		m_type = type_entrance;

		break;
	case 'x':
		m_type = type_exit;
		break;
	case 'a': case 'b':case 'c': case 'd': case 'e': case 'f':case 'g': case 'h':case 'i': case 'j':
		m_type = type_collectable;
		break;
	default:
		break;
	}*/

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
