#include <iostream>
#include "Grid.h"
#include <windows.h> 
#include "Walker.h"

int main() {
	while(true){
	std::string Map;
	std::cout << "Input map file name (add txt to the end): " << std::endl;
	std::cin >> Map;
	Map = "ValidMap1.txt";
	Grid grid("Maps/"+Map);
	
	bool gStart = true;

	bool Step = true;
	//std::cout<< "Select

	if(grid.m_valid==2){
		grid.DrawNodes();
		char selection = ' ';
		std::cout << "Select Operation:\nd - DFS\nb - BFS\na - A*"  << std::endl;
		std::cin >> selection;
		Walker Pathmaker(grid);
		Pathmaker.m_CurrentNode = &grid.m_NodeArray[0][0];
		switch (selection) {
		case 'd':
			grid.AssignWeights();
			grid.RunDFS(11);
			break;		
		case 'b':
			grid.AssignWeights();

			grid.RunBFS(11);
			break;
		case 'a':
			Pathmaker.InitWalker();
			while (Pathmaker.goalCount < 1) {
				Pathmaker.FindPathAstar();

				if (Step) {
					//grid.DrawNodes();
				}
				//	Sleep(1000); //so people get less epilepsy attacks

			}
			break;
		default:
			std::cout << "Please select b, d or a" << std::endl;
			break;
		}

		/*Walker Pathmaker(grid);
		Pathmaker.m_CurrentNode = &grid.m_NodeArray[0][0];
		Pathmaker.InitWalker();
	
	
	
		while (Pathmaker.goalCount<1) {
			Pathmaker.FindPathAstar();
		
			if (Step) {
				//grid.DrawNodes();
			}
		//	Sleep(1000); //so people get less epilepsy attacks

		}*/
		
		
		
	
		//grid.RunBFS(11);

	}
	}
} 