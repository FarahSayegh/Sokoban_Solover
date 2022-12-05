#include "Sokoban.h"

int globalID = 0;

Sokoban::Sokoban()
{
	this->row = 1;
	this->col = 1;
	this->cost = 0;
	this->distance = 0;
	this->f = this->cost + this->distance;
	this->id = 0;
	this->parentId = -1;
	this->numberOfObstacles = 0;
	this->numberOfBoxesAndGoals = 0;	

	this->grid = new Cell * [this->row];
	for (int i = 0; i < this->row; i++)
		this->grid[i] = new Cell[this->col];

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->grid[i][j].cell = empty;
			this->grid[i][j].pos.x = i;
			this->grid[i][j].pos.y = j;
		}
	}

	this->goals = new Position[this->numberOfBoxesAndGoals];

	for (int i = 0; i < this->numberOfBoxesAndGoals; i++)
	{
		this->goals[i].x = 0;
		this->goals[i].y = 0;
	}

	this->boxes = new Position[this->numberOfBoxesAndGoals];

	for (int i = 0; i < this->numberOfBoxesAndGoals; i++)
	{
		this->boxes[i].x = 0;
		this->boxes[i].y = 0;
	}
}
Sokoban::Sokoban(int row, int col)
{
	this->row = row;
	this->col = col;
	this->cost = 0;
	this->distance = 0;
	this->f = this->cost + this->distance;
	this->id = 0;
	this->parentId = -1;
	this->numberOfObstacles = 0;
	this->numberOfBoxesAndGoals = 0;

	this->grid = new Cell * [this->row];
	for (int i = 0; i < this->row; i++)
		this->grid[i] = new Cell[this->col];

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->grid[i][j].cell = empty;
			this->grid[i][j].pos.x = i;
			this->grid[i][j].pos.y = j;
		}
	}

	this->goals = new Position[this->numberOfBoxesAndGoals];

	for (int i = 0; i < this->numberOfBoxesAndGoals; i++)
	{
		this->goals[i].x = 0;
		this->goals[i].y = 0;
	}

	this->boxes = new Position[this->numberOfBoxesAndGoals];

	for (int i = 0; i < this->numberOfBoxesAndGoals; i++)
	{
		this->boxes[i].x = 0;
		this->boxes[i].y = 0;
	}
}
Sokoban::Sokoban(const Sokoban& obj)
{
	this->row = obj.row;
	this->col = obj.col;
	this->cost = obj.cost;
	this->distance = obj.distance;
	this->f = obj.f;
	this->id = obj.id;
	this->parentId = obj.parentId;
	this->numberOfObstacles = obj.numberOfObstacles;
	this->numberOfBoxesAndGoals = obj.numberOfBoxesAndGoals;
	
	this->grid = new Cell * [this->row];
	for (int i = 0; i < this->row; i++)
		this->grid[i] = new Cell[this->col];

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->grid[i][j].cell = obj.grid[i][j].cell;
			this->grid[i][j].pos.x = obj.grid[i][j].pos.x;
			this->grid[i][j].pos.y = obj.grid[i][j].pos.y;
		}
	}

	this->goals = new Position[this->numberOfBoxesAndGoals];

	for (int i = 0; i < this->numberOfBoxesAndGoals; i++)
	{
		this->goals[i].x = obj.goals[i].x;
		this->goals[i].y = obj.goals[i].y;
	}

	this->boxes = new Position[this->numberOfBoxesAndGoals];

	for (int i = 0; i < this->numberOfBoxesAndGoals; i++)
	{
		this->boxes[i].x = obj.boxes[i].x;
		this->boxes[i].y = obj.boxes[i].y;
	}
}
Sokoban::~Sokoban()
{
	for (int i = 0; i < this->row; i++)
	{
		delete[] this->grid[i];
	}
	delete[] this->grid;

	delete[] this->goals;

	delete[] this->boxes;
}

void Sokoban::setRow(int row)
{
	this->row = row;
}
void Sokoban::setCol(int col)
{
	this->col = col;
}
void Sokoban::setCost(int cost)
{
	this->cost = cost;
}
void Sokoban::setDistance(int distance)
{
	this->distance = distance;
}
void Sokoban::setId(int id)
{
	this->id = id;
}
void Sokoban::setF(int f)
{
	this->f = f;
}
void Sokoban::setParentId(int parentId)
{
	this->parentId = parentId;
}
void Sokoban::setNumberOfObstacles(int numberOfObstacles)
{
	this->numberOfObstacles = numberOfObstacles;
}
void Sokoban::setNumberOfBoxesAndGoals(int numberOfBoxesAndGoals)
{
	this->numberOfBoxesAndGoals = numberOfBoxesAndGoals;
}

int Sokoban::getRow() const
{
	return this->row;
}
int Sokoban::getCol() const
{
	return this->col;
}
int Sokoban::getCost() const
{
	return this->cost;
}
int Sokoban::getDistance() const
{
	return this->distance;
}
int Sokoban::getId() const
{
	return this->id;
}
int Sokoban::getF()const
{
	return this->f;
}
int Sokoban::getParentId() const
{
	return this->parentId;
}
int Sokoban::getNumberOfObstacles() const
{
	return this->numberOfObstacles;
}
int Sokoban::getNumberOfBoxesAndGoals() const
{
	return this->numberOfBoxesAndGoals;
}

void Sokoban::fillCell(Position pos, CellType cell)
{
	this->grid[pos.x][pos.y].cell = cell;
}
void Sokoban::fillGrid()
{
	Position pos;
	int n = 0;

	std::cout << "Enter the number of Obstacles: ";
	std::cin >> n;
	setNumberOfObstacles(n);
	std::cout << std::endl;

	for (int i = 0; i < this->getNumberOfObstacles(); i++)
	{
		std::cout << "Enter the position of obstacle number " << i + 1 << ": ";
		std::cin >> pos.x >> pos.y;
		fillCell(pos, obstacle);
		std::cout << std::endl;
	}

	std::cout << "Enter the number of Boxes and Goals: ";
	std::cin >> n;
	setNumberOfBoxesAndGoals(n);
	std::cout << std::endl;

	for (int i = 0; i < this->getNumberOfBoxesAndGoals(); i++)
	{
		std::cout << "Enter the position of box number " << i + 1 << ": ";
		std::cin >> pos.x >> pos.y;
		fillCell(pos, box);
		std::cout << std::endl;

		std::cout << "Enter the position of goal number " << i + 1 << ": ";
		std::cin >> pos.x >> pos.y;
		fillCell(pos, goal);
		std::cout << std::endl;

		this->saveGoalsLoc();
		this->saveBoxesLoc();
	}

	std::cout << "Enter the position of Player: ";
	std::cin >> pos.x >> pos.y;
	fillCell(pos, player);
	std::cout << std::endl;

	this->manhattanDistance();
}

void Sokoban::saveGoalsLoc()
{
	this->goals = new Position[this->getNumberOfBoxesAndGoals()];

	Position pos;
	int loc = 0;
	for (int i = 0; i < this->getRow(); i++)
	{
		for (int j = 0; j < this->getCol(); j++)
		{
			if (this->grid[i][j].cell == goal)
			{
				pos.x = i;
				pos.y = j;
				this->goals[loc] = pos;
				loc++;
			}
		}
	}
}
void Sokoban::saveBoxesLoc()
{
	this->boxes = new Position[this->getNumberOfBoxesAndGoals()];

	Position pos;
	int loc = 0;
	for (int i = 0; i < this->getRow(); i++)
	{
		for (int j = 0; j < this->getCol(); j++)
		{
			if (this->grid[i][j].cell == box)
			{
				pos.x = i;
				pos.y = j;
				this->boxes[loc] = pos;
				loc++;
			}
		}
	}
}
void Sokoban::updateBoxesLoc()
{
	Position pos;
	int loc = 0;
	for (int i = 0; i < this->getRow(); i++)
	{
		for (int j = 0; j < this->getCol(); j++)
		{
			if (this->grid[i][j].cell == box)
			{
				pos.x = i;
				pos.y = j;
				this->boxes[loc] = pos;
				loc++;
			}
		}
	}
}

Position Sokoban::getPlayer()
{
	Position pos;

	for (int i = 0; i < this->getRow(); i++)
	{
		for (int j = 0; j < this->getCol(); j++)
		{
			if (this->grid[i][j].cell == player)
			{
				pos.x = i;
				pos.y = j;
				return pos;
			}
		}
	}
}

bool Sokoban::checkRight()
{
	Position pos = this->getPlayer();

	if (pos.y == this->getCol() - 1)
		return false;
	else if (this->grid[pos.x][pos.y + 1].cell == obstacle)
		return false;
	else if (this->grid[pos.x][pos.y + 1].cell == box && (pos.y + 1) == this->getCol() - 1)
		return false;
	else if (this->grid[pos.x][pos.y + 1].cell == box && ( (this->grid[pos.x][pos.y + 2].cell == box) || (this->grid[pos.x][pos.y + 2].cell == obstacle) ) )
		return false;
	else
		return true;
}
bool Sokoban::checkLeft()
{
	Position pos = this->getPlayer();

	if (pos.y == 0)
		return false;
	else if (this->grid[pos.x][pos.y - 1].cell == obstacle)
		return false;
	else if (this->grid[pos.x][pos.y - 1].cell == box && (pos.y - 1) == 0)
		return false;
	else if (this->grid[pos.x][pos.y - 1].cell == box && ((this->grid[pos.x][pos.y - 2].cell == box) || (this->grid[pos.x][pos.y - 2].cell == obstacle)))
		return false;
	else
		return true;
}
bool Sokoban::checkUp()
{
	Position pos = this->getPlayer();

	if (pos.x == 0)
		return 0;
	else if (this->grid[pos.x - 1][pos.y].cell == obstacle)
		return false;
	else if (this->grid[pos.x - 1][pos.y].cell == box && (pos.x - 1) == 0)
		return false;
	else if (this->grid[pos.x - 1][pos.y].cell == box && ((this->grid[pos.x - 2][pos.y].cell == box) || (this->grid[pos.x - 2][pos.y].cell == obstacle)))
		return false;
	else
		return true;
}
bool Sokoban::checkDown()
{
	Position pos = this->getPlayer();

	if (pos.x == this->getRow() - 1)
		return 0;
	else if (this->grid[pos.x + 1][pos.y].cell == obstacle)
		return false;
	else if (this->grid[pos.x + 1][pos.y].cell == box && (pos.x + 1) == this->getRow() - 1)
		return false;

	else if (this->grid[pos.x + 1][pos.y].cell == box && ((this->grid[pos.x + 2][pos.y].cell == box) || (this->grid[pos.x + 2][pos.y].cell == obstacle)))
		return false;

	else
		return true;
}

bool Sokoban::resetGoal()
{
	Position pos = this->getPlayer();
	bool rightPlace = false;

	for (int i = 0; i < this->getNumberOfBoxesAndGoals(); i++)
	{
		if (this->goals[i].x == pos.x && this->goals[i].y == pos.y)
		{
			rightPlace = true;
			break;
		}
		else
			continue;
	}
	return rightPlace;
}

void Sokoban::moveRight()
{
	Position pos = this->getPlayer();

	if (this->checkRight())
	{

		if (this->grid[pos.x][pos.y + 1].cell == empty)
		{
			if (this->resetGoal())
				this->grid[pos.x][pos.y].cell = goal;
			else
				this->grid[pos.x][pos.y].cell = empty;

			this->grid[pos.x][pos.y + 1].cell = player;
		}
		else if (this->grid[pos.x][pos.y + 1].cell == goal)
		{
			if (this->resetGoal())
				this->grid[pos.x][pos.y].cell = goal;
			else
				this->grid[pos.x][pos.y].cell = empty;

			this->grid[pos.x][pos.y + 1].cell = player;
		}
		else if (this->grid[pos.x][pos.y + 1].cell == box)
		{
			if (this->resetGoal())
				this->grid[pos.x][pos.y].cell = goal;
			else
				this->grid[pos.x][pos.y].cell = empty;

			this->grid[pos.x][pos.y + 2].cell = box;
			this->grid[pos.x][pos.y + 1].cell = player;	

			this->setCost(this->getCost()+1);
		}
		else
			std::cout << "SOMETHING WENT WRONG!!!! in moveRight" << std::endl;
		updateBoxesLoc();
	}
	else
		std::cout << "Can't move right" << std::endl;
}
void Sokoban::moveLeft()
{
	Position pos = this->getPlayer();

	if (this->checkLeft())
	{

		if (this->grid[pos.x][pos.y - 1].cell == empty)
		{
			if (this->resetGoal())
				this->grid[pos.x][pos.y].cell = goal;
			else
				this->grid[pos.x][pos.y].cell = empty;

			this->grid[pos.x][pos.y - 1].cell = player;
		}
		else if (this->grid[pos.x][pos.y - 1].cell == goal)
		{
			if (this->resetGoal())
				this->grid[pos.x][pos.y].cell = goal;
			else
				this->grid[pos.x][pos.y].cell = empty;

			this->grid[pos.x][pos.y - 1].cell = player;	
		}
		else if (this->grid[pos.x][pos.y - 1].cell == box)
		{
			if (this->resetGoal())
				this->grid[pos.x][pos.y].cell = goal;
			else
				this->grid[pos.x][pos.y].cell = empty;

			this->grid[pos.x][pos.y - 2].cell = box;
			this->grid[pos.x][pos.y - 1].cell = player;

			this->setCost(this->getCost() + 1);
		}
		else
			std::cout << "SOMETHING WENT WRONG!!!! in moveLeft" << std::endl;
		updateBoxesLoc();
	}
	else
		std::cout << "Can't move left" << std::endl;
}
void Sokoban::moveUp()
{
	Position pos = this->getPlayer();

	if (this->checkUp())
	{

		if (this->grid[pos.x - 1][pos.y].cell == empty)
		{
			if (this->resetGoal())
				this->grid[pos.x][pos.y].cell = goal;
			else
				this->grid[pos.x][pos.y].cell = empty;

			this->grid[pos.x - 1][pos.y].cell = player;
		}
		else if (this->grid[pos.x - 1][pos.y].cell == goal)
		{
			if (this->resetGoal())
				this->grid[pos.x][pos.y].cell = goal;
			else
				this->grid[pos.x][pos.y].cell = empty;

			this->grid[pos.x - 1][pos.y].cell = player;
		}
		else if (this->grid[pos.x - 1][pos.y].cell == box)
		{
			if (this->resetGoal())
				this->grid[pos.x][pos.y].cell = goal;
			else
				this->grid[pos.x][pos.y].cell = empty;

			this->grid[pos.x - 2][pos.y].cell = box;
			this->grid[pos.x - 1][pos.y].cell = player;

			this->setCost(getCost() + 1);
		}
		else
			std::cout << "SOMETHING WENT WRONG!!!! in moveUp" << std::endl;
		updateBoxesLoc();
	}
	else
		std::cout << "Can't move up" << std::endl;
}
void Sokoban::moveDown()
{
	Position pos = this->getPlayer();

	if (this->checkDown())
	{

		if (this->grid[pos.x + 1][pos.y].cell == empty)
		{
			if (this->resetGoal())
				this->grid[pos.x][pos.y].cell = goal;
			else
				this->grid[pos.x][pos.y].cell = empty;

			this->grid[pos.x + 1][pos.y].cell = player;
		}
		else if (this->grid[pos.x + 1][pos.y].cell == goal)
		{
			if (this->resetGoal())
				this->grid[pos.x][pos.y].cell = goal;
			else
				this->grid[pos.x][pos.y].cell = empty;

			this->grid[pos.x + 1][pos.y].cell = player;
		}
		else if (this->grid[pos.x + 1][pos.y].cell == box)
		{
			if (this->resetGoal())
				this->grid[pos.x][pos.y].cell = goal;
			else
				this->grid[pos.x][pos.y].cell = empty;

			this->grid[pos.x + 2][pos.y].cell = box;
			this->grid[pos.x + 1][pos.y].cell = player;

			this->setCost(this->getCost() + 1);
		}
		else
			std::cout << "SOMETHING WENT WRONG!!!! in moveDown" << std::endl;
		updateBoxesLoc();
	}
	else
		std::cout << "Can't move down" << std::endl;
}

bool Sokoban::isFinal()
{
	bool final = true;

	for (int i = 0; i < this->getNumberOfBoxesAndGoals(); i++)
	{
		if (this->grid [this->goals[i].x] [this->goals[i].y] .cell == box)
			continue;
		else
		{
			final = false;
			break;
		}
	}
	return final;
}

void Sokoban::manhattanDistance()
{
	int h = 0;

	for (int i = 0; i < this->getNumberOfBoxesAndGoals(); i++)
	{
		h += abs(this->boxes[i].x - this->goals[i].x) + abs(this->boxes[i].y - this->goals[i].y);
	}
	
	this->setDistance(h);
}

void Sokoban::checkPossibleMoves(std::list<Sokoban>& possibleMoves,bool activateCost,bool activateDistance)
{
	Sokoban next;

	copyGrid(*this, next);
	if (this->checkUp())
	{
		next.moveUp();
		next.setParentId(this->getId());
		globalID++;
		next.setId(globalID);
		if (activateCost)
			next.setCost(next.getCost() + 1);
		if (activateDistance)
			next.manhattanDistance();
		if (activateCost && activateDistance)
			next.setF(next.getCost() + this->getDistance());
		possibleMoves.push_back(next);
	}

	copyGrid(*this, next);
	if (this->checkRight())
	{
		next.moveRight();
		next.setParentId(this->getId());
		globalID++;
		next.setId(globalID);
		if (activateCost)
			next.setCost(next.getCost() + 1);
		if (activateDistance)
			next.manhattanDistance();
		if (activateCost && activateDistance)
			next.setF(next.getCost() + this->getDistance());
		possibleMoves.push_back(next);
	}

	copyGrid(*this, next);
	if (this->checkDown())
	{
		next.moveDown();
		next.setParentId(this->getId());
		globalID++;
		next.setId(globalID);
		if (activateCost)
			next.setCost(next.getCost() + 1);
		if (activateDistance)
			next.manhattanDistance();
		if (activateCost && activateDistance)
			next.setF(next.getCost() + this->getDistance());
		possibleMoves.push_back(next);
	}

	copyGrid(*this, next);
	if (this->checkLeft())
	{
		next.moveLeft();
		next.setParentId(this->getId());
		globalID++;
		next.setId(globalID);
		if (activateCost)
			next.setCost(next.getCost() + 1);
		if (activateDistance)
			next.manhattanDistance();
		if (activateCost && activateDistance)
			next.setF(next.getCost() + this->getDistance());
		possibleMoves.push_back(next);
	}
}

void  Sokoban::copyGrid(const Sokoban obj1, Sokoban& obj2)
{
	obj2.row = obj1.row;
	obj2.col = obj1.col;
	obj2.cost = obj1.cost;
	obj2.distance = obj1.distance;
	obj2.id = obj1.id;
	obj2.f = obj1.f;
	obj2.parentId = obj1.parentId;
	obj2.numberOfObstacles = obj1.numberOfObstacles;
	obj2.numberOfBoxesAndGoals = obj1.numberOfBoxesAndGoals;

	obj2.grid = new Cell * [obj2.row];
	for (int i = 0; i < obj2.row; i++)
		obj2.grid[i] = new Cell[obj2.col];

	for (int i = 0; i < obj2.row; i++)
	{
		for (int j = 0; j < obj2.col; j++)
		{
			obj2.grid[i][j].cell = obj1.grid[i][j].cell;
			obj2.grid[i][j].pos.x = obj1.grid[i][j].pos.x;
			obj2.grid[i][j].pos.y = obj1.grid[i][j].pos.y;
		}
	}

	obj2.goals = new Position[obj2.numberOfBoxesAndGoals];

	for (int i = 0; i < obj2.numberOfBoxesAndGoals; i++)
	{
		obj2.goals[i].x = obj1.goals[i].x;
		obj2.goals[i].y = obj1.goals[i].y;
	}

	obj2.boxes = new Position[obj2.numberOfBoxesAndGoals];

	for (int i = 0; i < obj2.numberOfBoxesAndGoals; i++)
	{
		obj2.boxes[i].x = obj1.boxes[i].x;
		obj2.boxes[i].y = obj1.boxes[i].y;
	}
}

bool Sokoban::isEqual(Sokoban& obj1, Sokoban& obj2)
{
	for (int i = 0; i < obj1.row; i++)
	{
		for (int j = 0; j < obj1.col; j++)
		{
			if (obj1.grid[i][j].cell != obj2.grid[i][j].cell)
				return false;
		}
	}
	return true;
}
bool Sokoban::isEqual(Sokoban& obj1, std::list<Sokoban>& objList)
{
	for (std::list<Sokoban>::iterator itr = objList.begin(); itr != objList.end(); itr++)
	{
		if (isEqual(obj1, *itr))
			return true;
	}
	return false;
}

void Sokoban::printGrid() const
{
	for (int i = 0; i < this->getRow(); i++)
	{
		for (int j = 0; j < this->getCol(); j++)
		{
			std::cout << this->grid[i][j].cell << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "cost: " << this->getCost() << std::endl;
	std::cout << "distance: " << this->getDistance() << std::endl;
	std::cout << "f: " << this->getF() << std::endl;
	std::cout << "id = " << this->getId() << std::endl;
	std::cout << "pid = " << this->getParentId() << std::endl;
}
void Sokoban::printGrid(const std::list<Sokoban>& objList) 
{
	for (std::list<Sokoban>::const_iterator itr = objList.cbegin(); itr != objList.cend(); itr++)
	{
		itr->printGrid();
		std::cout << "---------------" << std::endl;
	}
}

void Sokoban::findPath(const std::list<Sokoban>& visitedList,std::list<Sokoban>& path)
{ 
	path.push_back(visitedList.back());
	for (std::list<Sokoban>::const_reverse_iterator itr = visitedList.crbegin(); itr != visitedList.crend(); itr++)
	{
		if (itr->getId() != path.back().getParentId())
			continue;
		else
			path.push_back(*itr);
	}
	path.reverse();
}

void Sokoban::palyerGame(Sokoban& current)
{
	char ch;

	std::cout << "Start moving with WASD: " << std::endl;
	while (!current.isFinal())
	{
		std::cin >> ch;
		switch (ch)
		{
		case 'w':
			current.moveUp();
			current.printGrid();
			break;
		case 's':
			current.moveDown();
			current.printGrid();
			break;
		case 'a':
			current.moveLeft();
			current.printGrid();
			break;
		case 'd':
			current.moveRight();
			current.printGrid();
			break;
		default:
			std::cout << "please use WASD to move: " << std::endl;
			break;
		}
	}
	if (current.isFinal())
		std::cout << "Congrats you've won the game." << std::endl;
	else
		std::cout << "Game over." << std::endl;
}

void Sokoban::BFS(Sokoban& current)
{
	int countPop = 0;
	double difference = 0;
	time(&current.begin);

	std::queue<Sokoban> queueGrid;
	std::list<Sokoban> visitedList;
	std::list<Sokoban> possibleMoves;
	std::list<Sokoban> path;

	visitedList.push_back(current);
	do
	{
		current.checkPossibleMoves(possibleMoves,false,false); 

		while (possibleMoves.size() != 0)
		{
			queueGrid.push(possibleMoves.front());
			possibleMoves.pop_front();
		}

		if (queueGrid.size() != 0)
		{
			copyGrid(queueGrid.front(), current);
			queueGrid.pop();
			countPop++;
			while (isEqual(current, visitedList) && queueGrid.size() != 0)
			{
				copyGrid(queueGrid.front(), current);
				queueGrid.pop();
				countPop++;
			}
			visitedList.push_back(current);
		}
		else
		{
			std::cout << "BFS could not find a solution to this grid." << std::endl;
		}
	} while (!current.isFinal());
	time(&current.end);
	std::cout << "number of pop: " << countPop << std::endl;
	std::cout << "BFS has found a solution." << std::endl;

	difference = difftime(current.end, current.begin);
	std::cout << "This search took: " << difference << " secs" << std::endl;

	findPath(visitedList, path);
	std::cout << "Number of steps to solution: " << path.size() << std::endl;;
	std::cout << "The path is: " << std::endl;
	printGrid(path);

	path.clear();
	visitedList.clear();
	while (queueGrid.size() != 0)
	{
		queueGrid.pop();
	}
	globalID = 0;
}

void Sokoban::DFS(Sokoban& current)
{
	int countPop = 0;
	double difference = 0;
	time(&current.begin);

	std::stack<Sokoban> stackGrid;
	std::list<Sokoban> visitedList;
	std::list<Sokoban> possibleMoves;
	std::list<Sokoban> path;

	visitedList.push_back(current);
	do
	{
		current.checkPossibleMoves(possibleMoves,false,false);
		while (possibleMoves.size() != 0)
		{
			stackGrid.push(possibleMoves.front());
			possibleMoves.pop_front();
		}

		if (stackGrid.size() != 0)
		{
			copyGrid(stackGrid.top(), current);
			stackGrid.pop();
			countPop++;
			while (isEqual(current, visitedList) && stackGrid.size() != 0)
			{
				copyGrid(stackGrid.top(), current);
				stackGrid.pop();
				countPop++;
			}
			visitedList.push_back(current);
		}
		else
		{
			std::cout << "DFS could not find a solution to this grid." << std::endl;
		}
	} while (!current.isFinal());
	time(&current.end);
	std::cout << "number of pop: " << countPop << std::endl;
	std::cout << "DFS has found a solution." << std::endl;

	difference = difftime(current.end, current.begin);
	std::cout << "This search took: " << difference << " secs" << std::endl;

	findPath(visitedList, path);
	std::cout << "Number of steps to solution: " << path.size() << std::endl;
	std::cout << "The path is: " << std::endl;
	printGrid(path);

	path.clear();
	visitedList.clear();
	while (stackGrid.size() != 0)
	{
		stackGrid.pop();
	}
	globalID = 0;
}

void Sokoban::UCS(Sokoban& current)
{
	int countPop = 0;
	double difference = 0;
	time(&current.begin);

	std::list<Sokoban> visitedList;
	std::list<Sokoban> possibleMoves;
	std::list<Sokoban> path;

	visitedList.push_back(current);
	do
	{
		current.checkPossibleMoves(possibleMoves,true,false);
		possibleMoves.sort(CompareCost<Sokoban>());

		if (possibleMoves.size() != 0)
		{
			copyGrid(possibleMoves.front(), current);
			possibleMoves.pop_front();
			countPop++;
			while (isEqual(current, visitedList) && possibleMoves.size() != 0)
			{
				copyGrid(possibleMoves.front(), current);
				possibleMoves.pop_front();
				countPop++;
			}
			visitedList.push_back(current);
		}
		else
		{
			std::cout << "UCS could not find a solution to this grid." << std::endl;
		}
	} while (!current.isFinal());
	time(&current.end);
	std::cout << "number of pop: " << countPop << std::endl;
	std::cout << "UCS has found a solution." << std::endl;

	difference = difftime(current.end, current.begin);
	std::cout << "This search took: " << difference << " secs" << std::endl;

	std::cout <<"The cost is: "<< current.getCost() << std::endl;

	findPath(visitedList, path);
	std::cout << "Number of steps to solution: " << path.size() << std::endl;
	std::cout << "The path is: " << std::endl;
	printGrid(path);

	path.clear();
	visitedList.clear();
	possibleMoves.clear();

	globalID = 0;
}

void Sokoban::HCS(Sokoban& current)
{
	int countPop = 0;
	double difference = 0;
	time(&current.begin);

	std::list<Sokoban> visitedList;
	std::list<Sokoban> possibleMoves;
	std::list<Sokoban> path;

	visitedList.push_back(current);
	do
	{
		current.checkPossibleMoves(possibleMoves, false, true);
		possibleMoves.sort(CompareDistance<Sokoban>());

		if (possibleMoves.size() != 0)
		{
			copyGrid(possibleMoves.front(), current);
			possibleMoves.pop_front();
			countPop++;
			while (isEqual(current, visitedList) && possibleMoves.size() != 0)
			{
				copyGrid(possibleMoves.front(), current);
				possibleMoves.pop_front();
				countPop++;
			}
			visitedList.push_back(current);
		}
		else
		{
			std::cout << "HCS could not find a solution to this grid." << std::endl;
		}
	} while (!current.isFinal());
	time(&current.end);
	std::cout << "number of pop: " << countPop << std::endl;
	std::cout << "HCS has found a solution." << std::endl;

	difference = difftime(current.end, current.begin);
	std::cout << "This search took: " << difference << " secs" << std::endl;

	findPath(visitedList, path);
	std::cout << "Number of steps to solution: " << path.size() << std::endl;
	std::cout << "The path is: " << std::endl;
	printGrid(path);

	path.clear();
	visitedList.clear();
	possibleMoves.clear();

	globalID = 0;
}

void Sokoban::Astar(Sokoban& current)
{
	int countPop = 0;
	double difference = 0;
	time(&current.begin);

	std::list<Sokoban> visitedList;
	std::list<Sokoban> possibleMoves;
	std::list<Sokoban> path;

	visitedList.push_back(current);
	do
	{
		current.checkPossibleMoves(possibleMoves, true, true);
		possibleMoves.sort(CompareF<Sokoban>());

		if (possibleMoves.size() != 0)
		{
			copyGrid(possibleMoves.front(), current);
			possibleMoves.pop_front();
			countPop++;
			while (isEqual(current, visitedList) && possibleMoves.size() != 0)
			{
				copyGrid(possibleMoves.front(), current);
				possibleMoves.pop_front();
				countPop++;
			}
			visitedList.push_back(current);
		}
		else
		{
			std::cout << "A* could not find a solution to this grid." << std::endl;
		}
	} while (!current.isFinal());
	time(&current.end);
	std::cout << "number of pop: " << countPop << std::endl;
	std::cout << "A* has found a solution." << std::endl;

	difference = difftime(current.end, current.begin);
	std::cout << "This search took: " << difference << " secs" << std::endl;

	findPath(visitedList, path);
	std::cout << "Number of steps to solution: " << path.size() << std::endl;
	std::cout << "The path is: " << std::endl;
	printGrid(path);

	path.clear();
	visitedList.clear();
	possibleMoves.clear();

	globalID = 0;
}


void Sokoban::printClass() const
{
	std::cout << "--------------------------------" << std::endl;
	std::cout << "number of rows: " << this->row << " number of col: " << this->col << std::endl;
	std::cout << "number of boxes and goals: " << this->numberOfBoxesAndGoals << " number of obstacles: " << this->numberOfObstacles << std::endl;
	std::cout << "distance is : " << this->getDistance() << std::endl;

	std::cout << "the grid" << std::endl;
	for (int i = 0; i < this->getRow(); i++)
	{
		for (int j = 0; j < this->getCol(); j++)
		{
			std::cout << this->grid[i][j].cell << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "the positions of the grid" << std::endl;
	for (int i = 0; i < this->getRow(); i++)
	{
		for (int j = 0; j < this->getCol(); j++)
		{
			std::cout << this->grid[i][j].pos.x << this->grid[i][j].pos.y << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "The position of goals: ";
	for (int i = 0; i < this->getNumberOfBoxesAndGoals(); i++)
	{
		std::cout << this->goals[i].x << this->goals[i].y << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "The position of Boxes: ";
	for (int i = 0; i < this->getNumberOfBoxesAndGoals(); i++)
	{
		std::cout << this->boxes[i].x << this->boxes[i].y << " ";
	}
	std::cout << std::endl;
}