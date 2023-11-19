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
/*
void Grid::DFS(Node* startNode, std::vector<bool>& visited, std::vector<Node*>& path)
{
	int index = startNode->m_CharType == 's' ? 10 : startNode->m_CharType - 'a';
	
	visited[index] = true;
	path.push_back(startNode);

	for (int i = 0; i < startNode->NeighbourCount; ++i)
	{
		
		Node* neighbor = startNode->m_Neighbours[i]; 
		int NeighborIndex = neighbor->m_CharType == 's' ? 10 : neighbor->m_CharType - 'a';
		std::cout << neighbor->m_CharType;
		if (!visited[NeighborIndex])
		{
			
			DFS(neighbor, visited, path);
		}
	}
}

void Grid::RunDFS()
{
	std::vector<bool> visited(11, false);
	std::vector<Node*> path;

	for (int i = 0; i < 10; ++i)
	{
		Node* collectible = m_Collectables[i];
		int index = collectible->m_CharType == 's' ? 10 : collectible->m_CharType - 'a';
		std::cout << "I: " << index << std::endl;
		if (!visited[index])
		{
			
			DFS(collectible, visited, path);

			// Do something with the path (it represents the order in which collectibles were visited)
			path.clear(); // Clear path for the next connected component
		}
	}
}*/
void Grid::RunDFS(int _startNode)
{
	std::vector<bool> visited(12, false);
	std::stack<int> stack;
	std::vector<int> path;

	visited[_startNode] = true;
	stack.push(_startNode);

	while (!stack.empty())
	{
		int currentNode = stack.top();
		stack.pop();

		path.push_back(currentNode); // Collect the order in which nodes are visited
		std::cout << "c: " << m_Collectables[currentNode]->m_CharType << std::endl;

		for (int i = 0; i < 11; ++i)
		{
			if (!visited[i] && m_WeightPoints[currentNode][i] != 0)
			{
				visited[i] = true;
				stack.push(i);
			}
		}
	}

	// Do something with the path
}

void Grid::RunBFS(int _startNode)
{
	std::vector<bool> visited(12, false);

	std::queue<int> q;
	std::vector<int> path;

	visited[_startNode] = true;
	q.push(_startNode);

	while (!q.empty())
	{
		int currentNode = q.front();
		q.pop();

		path.push_back(currentNode); // Collect the order in which nodes are visited
		std::cout << "c: " <<m_Collectables[currentNode]->m_CharType << std::endl;
		for (int i = 0; i < 11; ++i)
		{
			if (!visited[i] && m_WeightPoints[currentNode][i] != 0)
			{
				visited[i] = true;
				q.push(i);
			}
			
		}
	}

	// Do something with the path
}



void Grid::AssignWeights()
{
	for (int row = 0; row < 10; row++)
	{
		for (int column = 0; column < 10; column++)
		{
			if (row != column)
			{
				m_WeightPoints[column][row] = GetEuclideanDistance(
					m_Collectables[row]->m_NodeX, m_Collectables[row]->m_NodeY,
					m_Collectables[column]->m_NodeX, m_Collectables[column]->m_NodeY
				);
				
			}
			std::cout << m_WeightPoints[column][row] << " ";
		}
		std::cout << "\n";
	}
}

float Grid::GetEuclideanDistance(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	return std::sqrt(dx * dx + dy * dy);
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
				m_Collectables[10] = &m_NodeArray[r][c];
			}
			else if (m_NodeArray[r][c].m_CharType >= 'a' && m_NodeArray[r][c].m_CharType <= 'j') {
				m_gGoal[int(m_NodeArray[r][c].m_CharType - 97)] = &m_NodeArray[r][c];
				m_Collectables[int(m_NodeArray[r][c].m_CharType - 97)] = &m_NodeArray[r][c];
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
