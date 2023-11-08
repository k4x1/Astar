#include "Grid.h"


void Grid::DrawNodes()
{
	system("cls");

	for (int i = 0; i < (sizeof(m_NodeArray) / sizeof(m_NodeArray[0])); i++)
	{
		std::cout << "|";
		for (int j = 0; j < (sizeof(m_NodeArray)[0] / sizeof(m_NodeArray[0][0])); j++)
		{
			std::cout <<"\033[4m"<<m_NodeArray[j][i].m_CharType << "|";
		}//underline stuff
		std::cout << "\033[24m"<<"\n";
	}
}

void Grid::UpdateTypes(Node _CurrentNode)
{
	switch (_CurrentNode.m_CharType)
	{
	case '.':
		_CurrentNode.m_type = type_clear;
		break;
	case 'w':
		_CurrentNode.m_type = type_wall;
		_CurrentNode.m_Walkable = false;
		break;
	case 's':
		_CurrentNode.m_type = type_entrance;
		//*m_EntranceNode = _CurrentNode;
		//makes a reference ot start
		break;
	case 'x':
		_CurrentNode.m_type = type_exit;
		//*m_ExitNode = _CurrentNode;
		//reference to exit
		break;
	case 'a': case 'b':case 'c': case 'd': case 'e': case 'f':case 'g': case 'h':case 'i': case 'j':
		_CurrentNode.m_type = type_collectable;
		//*m_Collectables[m_AmountOfCollectibles] = _CurrentNode; //adds collectables to array for reference
		break;
	default:
		break;
	}
}

void Grid::Update()
{
}

Grid::Grid(std::string _File)
{
	std::ifstream GridFile;
	GridFile.open(_File);
	std::string line;
	
	std::cout << line;
	if (!GridFile) {
		std::cout << "File not opened" << std::endl;
	}
	int c = 0; // column
	while (GridFile >> line) {
		
		for (int r = 0; r < line.size(); r++)
		{
			//std::cout << line[r] << std::endl;
			m_NodeArray[r][c].m_CharType = line[r];
			m_NodeArray[r][c].m_NodeX = r;
			m_NodeArray[r][c].m_NodeY = c;
			UpdateTypes(m_NodeArray[r][c]);

		}

		c++; //NO WAY C++ :OOO
	}
	GridFile.close();
	
}

Grid::~Grid()
{
}
