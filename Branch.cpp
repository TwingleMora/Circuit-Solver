#include<cmath>
#include"Branch.h"
Branch::Branch() //:

//	From(0), To(0);

{

}
std::vector<int> unique2(std::vector<int> vec)
{
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;
	std::vector<int> temp = vec;
	for (it = temp.begin(); it != temp.end(); ++it)
	{
		for (it2 = temp.begin(); it2 != temp.end(); ++it2)
		{
			if (it != it2)
			{
				if ((*it) == (*it2))
				{
					temp.erase(it);
					return unique2(temp);
				}
			}
		}
	}
	return temp;
}
double Small_Length;
double magnitude(sf::Vector2f  vec1, sf::Vector2f  vec2)
{

	return std::sqrt(pow((vec1.x-vec2.x), 2) + pow((vec1.y-vec2.y), 2));
}
float Slope(sf::Vector2f from, sf::Vector2f to)
{
	return((from.y - to.y) / (from.x - to.x));
}
bool Branch::Exist(int node1, int node2,double value ,char type = 'r')
{
	if (From == node1 || From == node2)
	{
		if (To == node2 || To == node1)
		{
			if (Value == value)
			{
				return true;
			}
		}
	}
	return false;
}
void Branch::ColomsMove()
{
	//sf::Vector2f CenterPoint;
	
	//CenterPoint.x = (startPos.x+destinationPos.x)/2;
	//CenterPoint.y = (startPos.y+destinationPos.y)/2;
	//float critical_slope = ((Middle_Pos_1.y - CenterPoint.y) / (Middle_Pos_1.x - CenterPoint.x));
	//double A;
	//double B;
	//double X;
	//double Y=0;
	//double speed,x2;
	//double M;
	//X = -1;//destination - pos.x
	
	Charge.setPosition(startPos);
	float x = (destinationPos.x - startPos.x) / 1000, y = (destinationPos.y - startPos.y) / 1000;
	float currentDistance = 0;
	sf::Vector2f AVec = ((Middle_Pos_1*(1/1000.0f))-(startPos*(1/1000.0f)));
	float c = ((Small_Length + MaxDistance) / magnitude(Middle_Pos_1, startPos));
	AVec = AVec * c;
	sf::Vector2f pos;
	sf::Vector2f BVec(x,y);
	sf::Vector2f CurrentDirVec;
	dir = 1;
	///float slope;
	if(!Charges.empty())
	for (std::vector<sf::CircleShape>::iterator it = Charges.begin(); it != Charges.end(); ++it)
	{
			pos = (*it).getPosition();
			if (is_there_supportive){
		///slope = Slope(pos, CenterPoint);
		CurrentDirVec = AVec;
		
		if (Small_Length < magnitude(pos, startPos))
		{
			CurrentDirVec = BVec;
	
		}

		if (magnitude(pos, Middle_Pos_1) > magnitude(pos, Middle_Pos_2))
		{
			//dir = -1;
		}
		else
		{
			dir = 1;
		}
		if (MaxDistance < magnitude(pos, Middle_Pos_1))
		{
			dir = -1;
			CurrentDirVec = AVec * -1.0f;
		}
		if(dir==-1)
		if (Small_Length < magnitude(pos, Middle_Pos_2))
		{
			Charges.erase(it);// m7taaaaaag tryyyyyy2a 27ddddd byhhhhhhhaaaaaaaaaaaaa el dir w el hit_the_middile_point lkol colom
			Charges.push_back(Charge);
				break;
		}
		(*it).move(CurrentDirVec);
		//	 A = pos.y;
		//	 B = pos.x;
		//	 x2 = pow((X - B / 2), 2);
		//	 speed = ((pow(A,2))/ 4);
		//	 Y = std::sqrt(speed - x2) + (A / 2);
		//	*/
		//	 Y = ((startPos.x - B) / (A - startPos.y)) * (X);
		//	 if (std::abs(A - startPos.y) > 0.5)
		//	 {
		//	 }
		//	 else
		//	 {
		//		 X = 1;
		//		 Y = -1;
		//	 }
		//		
		//
		//	 M = magnitude(X, Y);
		//	(*it).move(X/M, Y/M);
		//{
		//	if (std::sqrt(pow(Middle_Pos_2.x - pos.x, 2) + pow(Middle_Pos_2.y - pos.y, 2)) > std::sqrt(pow(Middle_Pos_1.x - pos.x, 2) + pow(Middle_Pos_1.y - pos.y, 2)))
		//		dir = -1;
		//	else
		//		dir = 1;
		//	if (!hit_the_middile_point)
		//	{
		//		if (dir == 1)
		//			currentDistance = std::sqrt(pow(startPos.x - pos.x, 2) + pow(startPos.y - pos.y, 2));
		//		else
		//			currentDistance = std::sqrt(pow(Middle_Pos_2.x - pos.x, 2) + pow(Middle_Pos_2.y - pos.y, 2));
		//		if (currentDistance < Small_Length)
		//		{
		//			(*it).move(xs * dir, ys * dir);
		//		}
		//		else
		//		{
		//			hit_the_middile_point = true;
		//			if (dir == -1)
		//			{
		//				// dir = 1;
		//				//hit_the_middile_point = false;
		//				Charges.erase(it);// m7taaaaaag tryyyyyy2a 27ddddd byhhhhhhhaaaaaaaaaaaaa el dir w el hit_the_middile_point lkol colom
		//				Charges.push_back(Charge);
		//				break;
		//			}
		//		}
		//	}
		//	else
		//	{
		//		currentDistance = std::sqrt(pow(Middle_Pos_1.x - pos.x, 2) + pow(Middle_Pos_1.y - pos.y, 2));
		//		if (currentDistance < MaxDistance)
		//		{
		//			(*it).move(x, y);
		//		}
		//		else
		//		{
		//			hit_the_middile_point = false;
		//			dir *= -1;
		//		}
		//	}
		}
		else
		{
		
			currentDistance = std::sqrt(pow(startPos.x - pos.x, 2) + pow(startPos.y - pos.y, 2));
			(*it).move(x, y);
			if (currentDistance >= MaxDistance)
			{
				Charges.erase(it);
				Charges.push_back(Charge);
				break;
			}


		}
	}
}


void Branch::GetCurrent(const std::vector<Node>& CNodes, const std::vector<Branch>& CBranches)
{
	
	Charges.clear();
	Charge= sf::CircleShape(5);
	Charge.setFillColor(sf::Color::Magenta);
	int StartIndx = From - 1,EndIndx = To -1;
	int count = 0;
	float x = 0, y = 0;
	if (Type == 'r')
	{
		Current = (CNodes[StartIndx].V - CNodes[EndIndx].V) / Value;
		if (Current > 0)
		{
			startPos = (CNodes[StartIndx].nodeDraw.getPosition());
			destinationPos = CNodes[EndIndx].nodeDraw.getPosition();
			Charge.setPosition(startPos);

		}
		else
		{
			startPos = (CNodes[EndIndx].nodeDraw.getPosition());
			Charge.setPosition(startPos);
			destinationPos = CNodes[StartIndx].nodeDraw.getPosition();
		}
		MaxDistance = std::sqrt(pow(startPos.x - destinationPos.x, 2) + pow(startPos.y - destinationPos.y, 2));


		count = std::round(std::abs(Current * 10));
		if (Current >= INFINITY||Current<=-INFINITY)
		{

			count = std::round(MaxDistance / (5.0f * Charge.getRadius()));
		}
		x = (destinationPos.x - startPos.x) / 6; y = (destinationPos.y - startPos.y) / 6;
		{
			if (SupportiveWires.size() > 0)
			{
				hit_the_middile_point = false;
				Middle_Pos_1.x = startPos.x + Offset.x;
				Middle_Pos_1.y = startPos.y + Offset.y;
				Middle_Pos_2.x = destinationPos.x + Offset.x;
				Middle_Pos_2.y = destinationPos.y + Offset.y;
				is_there_supportive = true;
				Small_Length = std::sqrt(pow(Offset.x, 2) + pow(Offset.y, 2));
				if (Current == 0)
					count = 0;
				else
					count = std::round(Small_Length / (5.0f * Charge.getRadius()));
			}
		}
		if (is_there_supportive)
		{
			x = (Middle_Pos_1.x - startPos.x) / 4;
			y = (Middle_Pos_1.y - startPos.y) / 4;
		}
	}
	else if(Type=='v')
	{
		
		std::vector<int> SNodes = CNodes[EndIndx].connected_nodes_indexes;
		SNodes = unique2(SNodes);
		Current = 0;
		for (int surroundNodes = 0; surroundNodes < SNodes.size(); surroundNodes++)
		{//Node Can have More than one Branch
			for (int branches = 0; branches< CBranches.size(); branches++)
			{
				if (CBranches[branches].To == SNodes[surroundNodes] || CBranches[branches].From == SNodes[surroundNodes])// the first Node
				{
					int nodeId = SNodes[surroundNodes];
					if (CBranches[branches].To == To || CBranches[branches].From == To)//where is the second node?
					// --------(+ -)-------(N0.E-N0.S)/Req + (N0.E-N1.s
						//w hwa mashy hyla2y branch whose = its to and from = its from... you know what branch is that ... yes it's that branch i'm trying to get its current
						if (CBranches[branches].Type=='r')//but if they both do ... dont add their current
						{
							int index = nodeId - 1;
							if(!(CBranches[branches].Current>=INFINITY|| CBranches[branches].Current<=-INFINITY))
							if (CNodes[EndIndx].V > CNodes[index].V)
							{
								Current += std::abs(CBranches[branches].Current);
							}
							else
							{
								Current += -std::abs(CBranches[branches].Current);
							}
							
						}
				}
			}
		}
		if (Current != 0)
		{

			count = std::round(std::abs(Current * 10));
			if (Current > 0)
			{
				startPos = (CNodes[StartIndx].nodeDraw.getPosition());
				destinationPos = CNodes[EndIndx].nodeDraw.getPosition();
				Charge.setPosition(startPos);

			}
			else
			{
				startPos = (CNodes[EndIndx].nodeDraw.getPosition());
				Charge.setPosition(startPos);
				destinationPos = CNodes[StartIndx].nodeDraw.getPosition();
			}
			x = (destinationPos.x - startPos.x) / 6; y = (destinationPos.y - startPos.y) / 6;
			MaxDistance = std::sqrt(pow(startPos.x - destinationPos.x, 2) + pow(startPos.y - destinationPos.y, 2));
		}
	}
		for (int c = 0; c < count; c++)
		{
			
			Charge.move(x, y);
			Charges.push_back(Charge);

		}
	
		
	


}