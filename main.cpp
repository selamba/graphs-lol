#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
	constexpr Edge<> edge1 {'A', 'B'};
	constexpr Edge<> edge2 {edge1};
	
	std::cout << std::boolalpha
	          << edge1.is_proper_edge() << '\n'
	          << Edge<>::are_multi_edges(edge1, edge2) << '\n'
	          << Edge<>::are_multi_edges(edge1, edge2, Edge<> {'A', 'C'}) << '\n'
	          << std::endl;
	
	return 0;
}
