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

		m_EntranceNode = &_CurrentNode;

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

	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 20; y++)
		{
			
			for (int i = -1; i < 2; i++)
			{
				for (int j = -1; j < 2; j++)
				{

					if (i != 0 || j != 0) {

						int newX = x + i;
						int newY = y + j;

						if (newX >= 0 && newX < 20 && newY >= 0 && newY < 20)
						{
							m_NodeArray[x][y].m_Neighbours[m_NodeArray[x][y].NeighbourCount] = &m_NodeArray[newX][newY];
							m_NodeArray[x][y].NeighbourCount++;
							//if(&m_NodeArray[x][y] == m_EntranceNode){
							std::cout << m_NodeArray[x][y].NeighbourCount<<std::endl;
							//}
						}
					}
				}
			}
			
		}

	}
	GridFile.close();
}

	


Grid::~Grid()
{
}
