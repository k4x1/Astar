#include <iostream>
#include "Grid.h"
#include <windows.h> 
#include "Walker.h"

int main() {
	Grid grid("Maps/ValidMap2.txt");

	bool gStart = true;
	int cs = 0;
	bool Step = true;
	//std::cout << grid.m_NodeArray[0][0].NeighbourCount<<std::endl;
	if(grid.m_valid==2){
		Walker Pathmaker(grid);
		Pathmaker.m_CurrentNode = &grid.m_NodeArray[0][0];
		Pathmaker.InitWalker();
	
	
		//std::cout << grid.m_EntranceNode->NeighbourCount;
	//	std::cout << grid.m_EntranceNode->NeighbourCount<<std::endl;
	
		while (Pathmaker.goalCount<1) {
			Pathmaker.FindPathAstar();
			cs++;
			//std::cout << cs << std::endl;
			if (Step) {
				//grid.DrawNodes();
			}
		//	Sleep(1000); //so people get less epilepsy attacks

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
} 