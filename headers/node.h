
#include"SFML\Graphics.hpp"
#include<vector>

class Node
{
public:
	int id;
	double V;
	Node();
	std::vector<int> connected_nodes_indexes;
	sf::CircleShape nodeDraw;
	Node(int Id);
	Node(float voltage,int Id);
	//if mouse on it
	//if clicked
};

