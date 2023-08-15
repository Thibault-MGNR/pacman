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

#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <list>
#include <tuple>
#include <stack>
#include <game/map/map.hpp>

namespace Game {
	struct sNode
	{
		bool bObstacle = false;
		bool bVisited = false;
		float fGlobalGoal;
		float fLocalGoal;
		int x;
		int y;
		std::vector<sNode*> vecNeighbours;
		sNode* parent;
	};

	class Path_finding {
		public:
			Path_finding();
			bool create(std::shared_ptr<Map> map);
			bool solve_AStar();
			void set_node_start(int x, int y);
			void set_node_end(int x, int y);
			std::stack<std::pair<int, int>> get_path();
			int get_count();

		private:
			sNode *nodes;
			int nMapWidth = 28;
			int nMapHeight = 31;

			sNode *nodeStart = nullptr;
			sNode *nodeEnd = nullptr;	
	};
}
