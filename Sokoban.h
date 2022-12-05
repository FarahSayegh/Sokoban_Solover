#pragma once
#include<iostream>
#include <list>
#include <queue>
#include <stack>
#include<ctime>
#include<stdlib.h>
#include"Cell.h"
#include"Position.h"
#include"CellType.h"
#include"CompareCost.h"
#include"CompareCost.cpp"
#include"CompareDistance.h"
#include"CompareDistance.cpp"
#include"CompareF.h"
#include"CompareF.cpp"

class Sokoban
{
public:

	Sokoban();
	Sokoban(int row, int col);
	Sokoban(const Sokoban& obj);
	~Sokoban();

	void setRow(int row);
	void setCol(int col);
	void setCost(int cost);
	void setDistance(int distance);
	void setId(int id);
	void setF(int f);
	void setParentId(int parentId);
	void setNumberOfObstacles(int numberOfObstacles);
	void setNumberOfBoxesAndGoals(int numberOfBoxesAndGoals);

	int getRow() const;
	int getCol() const;
	int getCost() const;
	int getDistance() const;
	int getId() const;
	int getF()const;
	int getParentId() const;
	int getNumberOfObstacles() const;
	int getNumberOfBoxesAndGoals() const;

	void fillCell(Position pos,CellType cell);
	void fillGrid();
	
	void saveGoalsLoc();
	void saveBoxesLoc();
	void updateBoxesLoc();

	Position getPlayer();

	bool checkRight();
	bool checkLeft();
	bool checkUp();
	bool checkDown();

	bool resetGoal();

	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();

	bool isFinal();

	void manhattanDistance();

	void checkPossibleMoves(std::list<Sokoban>& possibleMoves, bool activateCost, bool activateDistance);

	static void findPath(const std::list<Sokoban>& visiteList,std::list<Sokoban>& path);

	void printGrid() const;

	static void printGrid(const std::list<Sokoban>& objList);

	static void copyGrid(const Sokoban obj1, Sokoban& obj2);

	static bool isEqual(Sokoban& obj1, Sokoban& obj2);
	
	static bool isEqual(Sokoban& obj1, std::list<Sokoban>& objList);
	
	static void palyerGame(Sokoban& current);

	static void BFS(Sokoban& current);

	static void DFS(Sokoban& current);

	static void UCS(Sokoban& current);

	static void HCS(Sokoban& current);

	static void Astar(Sokoban& current);

	void printClass() const;
	
	time_t begin, end;
private:
	Cell** grid;
	Position* goals;
	Position* boxes;
	int row;
	int col;
	int numberOfObstacles;
	int numberOfBoxesAndGoals;
	int id;
	int parentId;
	int cost;
	int distance;
	int f;
};