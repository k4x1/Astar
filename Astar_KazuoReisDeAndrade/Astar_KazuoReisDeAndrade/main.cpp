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
	
	while (gStart) {

		if (Step) {
			grid.DrawNodes();
		}



		Sleep(1000); //so people get less epilepsy attacks
		//gStart = false; do this to exit
	}


}