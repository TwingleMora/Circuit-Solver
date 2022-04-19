#include"SFML\Graphics.hpp"
#include"Node.h"
class Branch
{
public :
	Branch();
	sf::Text InfoDisplay;
	sf::Sprite ElementDraw;
	sf::RectangleShape Wire;
	
	std::vector<sf::RectangleShape> SupportiveWires;
	std::vector<sf::CircleShape> Charges;
	int From;
	int To ;
	char Type;
	short Type2 = 1;
	double Value = 0;
	double Current =0;
	bool Exist(int from, int to, double value,char type);
	void GetCurrent(const std::vector<Node>& CNodes, const std::vector<Branch>& CBranches);
	void ColomsMove();
	sf::Vector2f destinationPos= sf::Vector2f(0,0), startPos= sf::Vector2f(0, 0);
	sf::Vector2f Offset = sf::Vector2f(0,0);
	sf::Vector2f Middle_Pos_1, Middle_Pos_2;
	sf::CircleShape Charge;
	float MaxDistance=0;
	bool is_there_supportive = false;
	bool hit_the_middile_point = false;
	int dir = 1;
	//double magnitude(double, double);
};

