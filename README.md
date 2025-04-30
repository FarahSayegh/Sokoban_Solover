
# Sokoban Solver â€“ C++ Game Engine with AI Search Algorithms

This project is a C++ implementation of the classic **Sokoban puzzle game**, enhanced with intelligent search algorithms to automatically solve puzzle levels. It demonstrates strong proficiency in object-oriented programming, algorithm design, and AI techniques applied to game development.

## ðŸš€ Features

- Grid-based Sokoban engine with full player and box movement mechanics.
- Support for multiple AI search algorithms:
  - Breadth-First Search (BFS)
  - Depth-First Search (DFS)
  - Uniform Cost Search (UCS)
  - Greedy Best-First Search (HCS)
  - A* Search
- Heuristic-based decision-making using Manhattan Distance.
- Object-oriented design with reusable and modular classes.
- Console-based grid rendering and debug-friendly output.

## ðŸ“ Project Structure

- `Sokoban.h / Sokoban.cpp` â€“ Main class handling game logic and AI integration.
- `Cell`, `Position`, `CellType` â€“ Supporting components for game state and grid layout.
- `CompareCost`, `CompareDistance`, `CompareF` â€“ Custom comparators for search algorithms.
- `main.cpp` â€“ Entry point for launching the game or search algorithm.

## ðŸ§  Algorithms & AI

The solver supports multiple AI techniques to explore different strategies for reaching the goal state efficiently. A* combines cost and heuristic information to find optimal paths in complex grid configurations.

## ðŸ› ï¸ Getting Started

### Prerequisites

- C++11 or higher
- A standard C++ compiler (e.g., `g++`)

### Compilation

```bash
g++ -std=c++11 -o sokoban main.cpp Sokoban.cpp CompareCost.cpp CompareDistance.cpp CompareF.cpp
./sokoban
```

### Controls (Player Mode)

- Arrow keys or `W`, `A`, `S`, `D` for movement
- Custom keybindings can be added in the input handler


## ðŸ“š Learning Outcomes

- Implemented core search algorithms and evaluated their efficiency in game-solving.
- Practiced deep C++ features like dynamic memory management, class encapsulation, and custom sorting.
- Built a fully functional simulation of a logic-based puzzle game using real AI techniques.

## ðŸ“„ License

This project is open-source and available under the MIT License.

---

Feel free to fork, contribute, or use it as a base for more advanced AI game projects!
