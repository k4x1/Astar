#include <iostream>
#include "Grid.h"
#include <windows.h> 
#include "Walker.h"

int main() {
	Grid grid("Maps/ValidMap1.txt");

	bool gStart = true;

	bool Step = true;
	//std::cout << grid.m_NodeArray[0][0].m_NodeX;
	Walker Pathmaker(grid);
	Pathmaker.m_CurrentNode = grid.m_EntranceNode;
	//std::cout << grid.m_EntranceNode->NeighbourCount;
	Pathmaker.CheckLowestFcost();
	while (gStart) {

		if (Step) {
			//grid.DrawNodes();
		}
		Sleep(1000); //so people get less epilepsy attacks

	/*		int i = 0;
			int j = 0;
			std::cin >> i;
			std::cin >> j;
			
			for (int k = 0; k < 8; k++)
			{
				std::cout << grid.m_NodeArray[i][j].m_Neighbours[k]->m_CharType;
			}*/
	
		//gStart = false; do this to exit
	}


} 