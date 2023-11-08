#include "Walker.h"

Walker::Walker(Grid _GridReference)
{
	//*m_GridReference = _GridReference;
}

Walker::~Walker()
{
}

void Walker::GetNeighbours()
{
	for (int i = 0; i < (sizeof(m_GridReference->m_NodeArray) / sizeof(m_GridReference->m_NodeArray[0])); i++)
	{
		for (int j = 0; j < (sizeof(m_GridReference->m_NodeArray)[0] / sizeof(m_GridReference->m_NodeArray[0][0])); j++)
		{
			
		
		}
	}
}

void Walker::CheckLowestFcost()
{
}
