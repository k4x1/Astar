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
		//something wrong with this

		//makes a reference ot start
		break;
	case 'x':
		_CurrentNode.m_type = type_exit;
		//*m_ExitNode = _CurrentNode;
		//reference to exit
		break;
	case 'a': case 'b':case 'c': case 'd': case 'e': case 'f':case 'g': case 'h':case 'i': case 'j':
		_CurrentNode.m_type = type_collectable;
		 //adds collectables to array for reference
		break;
	default:
		break;
	}
	m_gridCount++;
}

void Grid::Update()
{
}
void Grid::AssignWeights()
{
	int Points[11][11];

}


Grid::Grid(std::string _File)
{
	std::ifstream GridFile;
	GridFile.open(_File);
	std::string line;
	
	//std::cout << line;
	if (!GridFile) {
		std::cout << "File not opened" << std::endl;
	}
	int c = 0; // column
	while (GridFile >> line) {
		
		for (int r = 0; r < line.size(); r++)
		{
			
			m_NodeArray[r][c].m_CharType = line[r];
			m_NodeArray[r][c].m_NodeX = r;
			m_NodeArray[r][c].m_NodeY = c;
			UpdateTypes(m_NodeArray[r][c]);
			
			if(m_NodeArray[r][c].m_CharType == 's'){
				m_valid++;
				m_EntranceNode = &m_NodeArray[r][c];
			}
			else if (m_NodeArray[r][c].m_CharType >= 'a' && m_NodeArray[r][c].m_CharType <= 'j') {
				m_gGoal[int(m_NodeArray[r][c].m_CharType - 97)] = &m_NodeArray[r][c];
				*m_Collectables[int(m_NodeArray[r][c].m_CharType - 97)] = _CurrentNode;
				//converts a to int(0) and so on and sets the x and y pos
			}
			else if(m_NodeArray[r][c].m_CharType == 'x'){
				m_gGoal[10]= &m_NodeArray[r][c];
				m_valid++;
			}
		}

		c++; //NO WAY C++ :OOO
	}
	if (m_valid < 2) {
		std::cout << "InvalidMap" << std::endl;
		GridFile.close();
		return;
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
