#pragma once
#include<iostream>
#include"Sokoban.h"
#include"CellType.h"
#include"Position.h"
#include"Cell.h"

int main() {

	int rows;
	int columns;
	int index;

	std::cout << "Enter the number of rows and columns: ";
	std::cin >> rows >> columns;
	std::cout << std::endl;

	Sokoban current(rows,columns);
	current.fillGrid();

	current.printGrid();
	Sokoban copy(current);

	std::cout << "chose the who to play: " << std::endl;;
	std::cout << "Enter 1 to play by yourself." << std::endl;
	std::cout << "Enter 2 to solve with Breadth First Search." << std::endl;
	std::cout << "Enter 3 to solve with Depth First Search." << std::endl;
	std::cout << "Enter 4 to solve with Uniform Cost Search." << std::endl;
	std::cout << "Enter 5 to solve with Hill Climbing Search." << std::endl;
	std::cout << "Enter 6 to solve with A* Search." << std::endl;
	std::cout << "Enter 0 to exit" << std::endl;


	std::cin >> index;
	while(index != 0)
	{
		switch (index)
		{
		case 1:
			Sokoban::palyerGame(copy);
			Sokoban::copyGrid(current, copy);
			break;
		case 2:
			Sokoban::BFS(copy);
			Sokoban::copyGrid(current, copy);
			break;
		case 3:
			Sokoban::DFS(copy);
			Sokoban::copyGrid(current, copy);
			break;
		case 4:
			Sokoban::UCS(copy);
			Sokoban::copyGrid(current, copy);
			break;
		case 5:
			Sokoban::HCS(copy);
			Sokoban::copyGrid(current, copy);
			break;
		case 6:
			Sokoban::Astar(copy);
			Sokoban::copyGrid(current, copy);
			break;

		default:

			break;
		}
		std::cout << "chose the who to play: " << std::endl;;
		std::cout << "Enter 1 to play by yourself." << std::endl;
		std::cout << "Enter 2 to solve with Breadth First Search." << std::endl;
		std::cout << "Enter 3 to solve with Depth First Search." << std::endl;
		std::cout << "Enter 4 to solve with Uniform Cost Search." << std::endl;
		std::cout << "Enter 5 to solve with Hill Climbing Search." << std::endl;
		std::cout << "Enter 6 to solve with A* Search." << std::endl;
		std::cout << "Enter 0 to exit" << std::endl;
		std::cin >> index;
	}

	
	return 0;
}