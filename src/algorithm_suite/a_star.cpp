/*
OneLoneCoder.com - PathFinding A*
"No more getting lost..." - @Javidx9

License
~~~~~~~
Copyright (C) 2018  Javidx9
This program comes with ABSOLUTELY NO WARRANTY.
This is free software, and you are welcome to redistribute it
under certain conditions; See license for details. 
Original works located at:
https://www.github.com/onelonecoder
https://www.onelonecoder.com
https://www.youtube.com/javidx9

GNU GPLv3
https://github.com/OneLoneCoder/videos/blob/master/LICENSE

From Javidx9 :)
~~~~~~~~~~~~~~~
Hello! Ultimately I don't care what you use this for. It's intended to be 
educational, and perhaps to the oddly minded - a little bit of fun. 
Please hack this, change it and use it in any way you see fit. You acknowledge 
that I am not responsible for anything bad that happens as a result of 
your actions. However this code is protected by GNU GPLv3, see the license in the
github repo. This means you must attribute me if you use it. You can view this
license here: https://github.com/OneLoneCoder/videos/blob/master/LICENSE
Cheers!


Background
~~~~~~~~~~
The A* path finding algorithm is a widely used and powerful shortest path
finding node traversal algorithm. A heuristic is used to bias the algorithm
towards success. This code is probably more interesting than the video. :-/


Author
~~~~~~
Twitter: @javidx9
Blog: www.onelonecoder.com

Video:
~~~~~~
https://youtu.be/icZj67PTFhc

Last Updated: 08/10/2017
*/

#include <cmath>
#include <game/algorithm_suite/a_star.hpp>

namespace Game {
	Path_finding::Path_finding(){}
	
	bool Path_finding::create(std::shared_ptr<Map> map) {
		auto map_grid = map->get_map(); 

		nodes = new sNode[this->nMapWidth * this->nMapHeight];

		for (int x = 0; x < nMapWidth; x++)
			for (int y = 0; y < nMapHeight; y++)
			{
				this->nodes[y * nMapWidth + x].x = x;
				this->nodes[y * nMapWidth + x].y = y;
				this->nodes[y * nMapWidth + x].bObstacle = map_grid[y][x] == 1;
				this->nodes[y * nMapWidth + x].parent = nullptr;
				this->nodes[y * nMapWidth + x].bVisited = false;
			}
		
		for (int x = 0; x < nMapWidth; x++)
			for (int y = 0; y < nMapHeight; y++)
			{
				if(y>0)
					this->nodes[y*nMapWidth + x].vecNeighbours.push_back(&this->nodes[(y - 1) * nMapWidth + (x + 0)]);
				if(y<nMapHeight-1)
					this->nodes[y*nMapWidth + x].vecNeighbours.push_back(&this->nodes[(y + 1) * nMapWidth + (x + 0)]);
				if (x>0)
					this->nodes[y*nMapWidth + x].vecNeighbours.push_back(&this->nodes[(y + 0) * nMapWidth + (x - 1)]);
				if(x<nMapWidth-1)
					this->nodes[y*nMapWidth + x].vecNeighbours.push_back(&this->nodes[(y + 0) * nMapWidth + (x + 1)]);
				if(y == 14 && x == 0)
					this->nodes[y*nMapWidth + x].vecNeighbours.push_back(&this->nodes[14 * nMapWidth + 27]);
				if(y == 14 && x == 27)
					this->nodes[y*nMapWidth + x].vecNeighbours.push_back(&this->nodes[14 * nMapWidth + 0]);
			}

		return true;
	}

	void Path_finding::set_node_start(int x, int y){
		nodeStart = &this->nodes[y * nMapWidth + x];
	}

	void Path_finding::set_node_end(int x, int y){
		nodeEnd = &this->nodes[y * nMapWidth + x];
	}

	bool Path_finding::solve_AStar() {
		for (int x = 0; x < nMapWidth; x++)
			for (int y = 0; y < nMapHeight; y++)
			{
				this->nodes[y*nMapWidth + x].bVisited = false;
				this->nodes[y*nMapWidth + x].fGlobalGoal = std::numeric_limits<float>::infinity();
				this->nodes[y*nMapWidth + x].fLocalGoal = std::numeric_limits<float>::infinity();
				this->nodes[y*nMapWidth + x].parent = nullptr;
			}
		
		if(nodeStart == nodeEnd)
			return true;

		auto distance = [](sNode* a, sNode* b)
		{
			return sqrtf((a->x - b->x)*(a->x - b->x) + (a->y - b->y)*(a->y - b->y));
		};

		auto heuristic = [distance](sNode* a, sNode* b)
		{
			sNode c = *b;
			sNode d = *b;
			c.x += 28;
			d.x -= 28;
			return std::min(distance(a, b), std::min(distance(a, &c), distance(a, &d)));
		};

		sNode *nodeCurrent = nodeStart;
		nodeStart->fLocalGoal = 0.0f;
		nodeStart->fGlobalGoal = heuristic(nodeStart, nodeEnd);

		std::list<sNode*> listNotTestedNodes;
		listNotTestedNodes.push_back(nodeStart);

		while (!listNotTestedNodes.empty() && nodeCurrent != nodeEnd)
		{
			listNotTestedNodes.sort([](const sNode* lhs, const sNode* rhs){ return lhs->fGlobalGoal < rhs->fGlobalGoal; } );

			while(!listNotTestedNodes.empty() && listNotTestedNodes.front()->bVisited)
				listNotTestedNodes.pop_front();

			if (listNotTestedNodes.empty())
				break;

			nodeCurrent = listNotTestedNodes.front();
			nodeCurrent->bVisited = true;
			
			for (auto nodeNeighbour : nodeCurrent->vecNeighbours)
			{
				if (!nodeNeighbour->bVisited && nodeNeighbour->bObstacle == 0)
					listNotTestedNodes.push_back(nodeNeighbour);

				float fPossiblyLowerGoal = nodeCurrent->fLocalGoal + heuristic(nodeCurrent, nodeNeighbour);

				if (fPossiblyLowerGoal < nodeNeighbour->fLocalGoal)
				{
					nodeNeighbour->parent = nodeCurrent;
					nodeNeighbour->fLocalGoal = fPossiblyLowerGoal;

					nodeNeighbour->fGlobalGoal = nodeNeighbour->fLocalGoal + heuristic(nodeNeighbour, nodeEnd);
				}
			}
		}

		return true;
	}

	std::stack<std::pair<int, int>> Path_finding::get_path(){
		std::stack<std::pair<int, int>> path;
		if (nodeEnd != nullptr)
		{
			sNode *p = nodeEnd;
			while (p->parent != nullptr)
			{
				path.push(std::pair<int, int>{p->x, p->y});
				p = p->parent;
			}
		}

		return path;
	}
};