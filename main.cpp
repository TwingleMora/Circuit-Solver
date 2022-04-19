//#include<SFML\Graphics.hpp>

#define _CRT_SECURE_NO_WARNINGS 0

#include<cmath>
#include<iomanip>
#include<fstream>
#include<ostream>
#include<iostream>

//#include"Node.h"
#include"Branch.h"
#include"ToolBox.h"
#include<sstream>
//#include"MatlabEngine.hpp"
//#include "MatlabDataArray.hpp"
#include "SolverX.h"
#include "rt_nonfinite.h"
#include "string1.h"
#include "coder_array.h"
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

	/*  |
		-------------------
	*/
	//test t(4);

	/*
						sf::Vector2i  v = sf::Mouse::getPosition(window);
						sf::Vector2f v2 = wireShapeObj.getPosition();
						sf::Vector2f v3 = wireShapeObj.getSize();


					double tan = (v.y - v2.y) / (v.x - v2.x) ;
					pointer.setPosition(v.x , v.y);
					//tan = std::abs(tan);
					angle = std::atan(tan);

						angle = ((angle * 180.0) / pi);
						std::cout << " [y] : "<< (v.y - v2.y) <<" [x] : "<< (v.x - v2.x) << " angle : " << angle << " \n ";
						if (((v.y - v2.y) > 0 && (v.x - v2.x) < 0) || ((v.y - v2.y) < 0 && (v.x - v2.x) < 0))
						{
							angle += 180;
						}
						wireShapeObj.setRotation(angle);
	*/


sf::Texture t1, t2;
sf::Sprite s1(t1), s2(t2), currentGraph;
double distance = 0;
int startIndex = 0;
int EndIndexx = 0;
int state = 0;/// 0 ->Editor Mode , 1 ->Dialoge Window ...
std::stringstream ss;
sf::Vector2f WireSize(100, 2);
double pi = 3.141592654;
double angle = 0;

std::string Input;
sf::RenderWindow window(sf::VideoMode(1024, 800), "Circuit Solver V1.0");
sf::RectangleShape wireShapeObj(WireSize);
sf::CircleShape earthShapeObj(10);
sf::CircleShape test(10);
sf::CircleShape pointer(10);
sf::Vector2i  v = sf::Mouse::getPosition(window);
sf::Vector2f v2 = wireShapeObj.getPosition();
sf::Vector2f v3 = wireShapeObj.getSize();
bool pressed = false;
std::vector<Node> CNodes;
std::vector<Node>::iterator CNodesIter;
std::vector<Branch> CBranches;
std::vector<Branch>::iterator CBranchesIter;
std::vector<sf::CircleShape> nodes;
std::vector<sf::CircleShape>::iterator nodesIter;
Node From(0, 1), To;///index +1 =Id |  Id = Index +1  | Id-1 = Index  | Index = Id -1 
Branch tempoBranch;
double specificAngleModification=0; //to fix the voltage source texture angle that is fliped
std::vector<sf::RectangleShape> branches;
std::vector<sf::RectangleShape>::iterator branchesIter;
std::vector<sf::Sprite>::iterator graphsIter;
std::vector<sf::Sprite> graphs;
sf::Vector2f centerPos;

double Value;
bool stop = false;
char type = 'v'; //('v/r');
short type2 = 1; //('v/r');
sf::Event event;
void DrawCircuit();
void ControllElements();
void ElementsAttitude();
sf::Font font;
double text_angle = 0;
sf::Text element_INFO;
sf::Vector2f default_text_origin;
ToolBox<double> ValueInput,InfoDisplay;
sf::Vector2i PreInputMousePos;
sf::RectangleShape support1,support2;
bool parallelElements = false;//auto
bool ManualParallelElements = false;
int counter = 0;
double parallelDistance = 100;
int lastOperationIndex =0;
double inverse_angle_support_wire = 0;
std::ifstream oFile;
SolverX* solveIt;
coder::array<double, 2U> arrayOfNodesIds;
coder::array<double, 2U> arrayOfPotentialVs;
char* TheInputXX = NULL;
Node earthPermenant;
int main()
{
	
	solveIt = new SolverX();
	
		ValueInput.InputWindow(300, 300, 300, 300,"Enter The Value");
	font.loadFromFile("fonts/arial.ttf");
	t1.loadFromFile("images/vvolt2.png");
	t2.loadFromFile("images/res2.png");
	s1 = sf::Sprite(t1);
	s2 = sf::Sprite(t2);
	element_INFO.setFont(font);
	element_INFO.setFillColor(sf::Color::White);
	element_INFO.setStyle(sf::Text::Bold);
	default_text_origin = element_INFO.getOrigin();
	element_INFO.setOrigin(19, -28);
	s1.setPosition(200, 200);
	//s1.(1, 1);

	//s2.setScale(1, 1);
	pointer.setFillColor(sf::Color::Yellow);
	test.setFillColor(sf::Color::Green);
	earthShapeObj.setFillColor(sf::Color::Red);
	wireShapeObj.setPosition(612, 400);
	wireShapeObj.setFillColor(sf::Color::Green);
	earthShapeObj.setPosition(wireShapeObj.getPosition().x /* - wireShapeObj.getSize().x / 2*/, wireShapeObj.getPosition().y /* - wireShapeObj.getSize().y / 2*/);
	earthShapeObj.setPosition(500, 450);
	tempoBranch.From = From.id;
	nodes.push_back(earthShapeObj);
	From.nodeDraw = earthShapeObj;
	earthPermenant = From;
	CNodes.push_back(From);
	s1.setOrigin(82, 76);
	s2.setOrigin(55, 23);
	//s1.rotate(-90);
	s2.setPosition(200, 200);
	currentGraph = s1;
	specificAngleModification = 90;
	///sf::Vector2i vvv;
	support1 = support2 = wireShapeObj;
	InfoDisplay.InfoWindow(220, 200, "INFO");
	//InfoDisplay.SetInfoWindowPosition(200, 200);
	//InfoDisplay.SetInfoWindowValues("jjj","ooo");
	//InfoDisplay.show = true;
	while (window.isOpen())
	{
	///	vvv = sf::Mouse::getPosition(window);

		sf::Vector2i mosPos;

		while (window.pollEvent(event))
		{
		//	ControllElements();
		
					
					
						ControllElements();
					
					
						ValueInput.GetInput(event);

			

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

		}
		
		
		if (!ValueInput.show)
		{

			ElementsAttitude();
		
		}
		for (CBranchesIter = CBranches.begin(); CBranchesIter != CBranches.end(); ++CBranchesIter)
		{
			(*CBranchesIter).ColomsMove();
		}
		window.clear();
		DrawCircuit();
		/*window.draw(ValueInput.mWindow);
		window.draw(ValueInput.Text);
		window.draw(ValueInput.ok_button);*/
		ValueInput.DrawInputWindow(window);
		InfoDisplay.DrawInfoWindow(window);
		//switch (state)
		//{
		//case 0:
		//	
		//	break;
		//case 1:
		//	//
		//	break;
		//default:
		//	break;
		//}
		////for (nodesIter = nodes.begin(); nodesIter != nodes.end(); ++nodesIter)
		//{
		//	window.draw((*nodesIter));
		//}
		//for (branchesIter = branches.begin(); branchesIter != branches.end(); ++branchesIter)
		//{
		//	window.draw((*branchesIter));
		//}
		//for (graphsIter = graphs.begin(); graphsIter != graphs.end(); ++graphsIter)
		//{
		//	window.draw((*graphsIter));
		//}


		/*for (graphsIter = graphs.begin(); graphsIter != graphs.end(); ++graphsIter)
		{
			window.draw((*graphsIter));
		}*/

		//window.draw(s2);
		//window.draw(test);

		window.display();

		/*	else
			{
			std::cout << "\n" << Input << "\n";
			system("pause");
			}
			*/
	}
	delete(solveIt);
	return 0;


}
void DrawCircuit()
{
	if (pressed)
	{
		window.draw(wireShapeObj);
		window.draw(pointer);
		window.draw(currentGraph);
		window.draw(element_INFO);
		if (parallelElements||ManualParallelElements)
		{
			window.draw(support1);
			window.draw(support2);
		}
	}
	for (CNodesIter = CNodes.begin(); CNodesIter != CNodes.end(); ++CNodesIter)
	{
		window.draw((*CNodesIter).nodeDraw);
	}
	for (CBranchesIter = CBranches.begin(); CBranchesIter != CBranches.end(); ++CBranchesIter)
	{

		window.draw((*CBranchesIter).Wire);
		window.draw((*CBranchesIter).ElementDraw);
		window.draw((*CBranchesIter).InfoDisplay);
		for (std::vector<sf::RectangleShape>::iterator it = (*CBranchesIter).SupportiveWires.begin(); it != (*CBranchesIter).SupportiveWires.end(); ++it)
		{
			window.draw(*it);
		}
		for (std::vector<sf::CircleShape>::iterator it = (*CBranchesIter).Charges.begin(); it != (*CBranchesIter).Charges.end(); ++it)
		{
			window.draw(*it);
		}

	}
	//parallelElements = ManualParallelElements = false;//at the last operation (drawing)
	
}
void ControllElements()
{
	if (event.type == sf::Event::KeyPressed)
	{
		std::string line;
		
		int node_id = 0,index = 0;
		double node_value = 0;
		std::string temp ="";
		
		//{	///Optimization
			/*
			sf::Text &s2 = element_INFO;
			if (event.key.code == sf::Keyboard::J)
			{
				s2.setOrigin(s2.getOrigin().x + 1, s2.getOrigin().y);
			}
			if (event.key.code == sf::Keyboard::H)
			{
				s2.setOrigin(s2.getOrigin().x - 1, s2.getOrigin().y);
			}
			if (event.key.code == sf::Keyboard::Y)
			{
				s2.setOrigin(s2.getOrigin().x, s2.getOrigin().y + 1);
			}
			if (event.key.code == sf::Keyboard::U)
			{
				s2.setOrigin(s2.getOrigin().x + 1, s2.getOrigin().y - 1);
			}
			if (event.key.code == sf::Keyboard::P)//print
			{
				std::cout << "Set Orgin [x] : " << s2.getOrigin().x << "[y] : " << s2.getOrigin().y << "\n";
			}

			if (event.key.code == sf::Keyboard::O)//pause
			{
				std::cout << "\n" << s2.getOrigin().x << "\n" << s2.getOrigin().y << "\n";
				std::cin.get();
			}
		}*/
		//if (event.key.code == sf::Keyboard::S)//save
		//{
		//	size_t ss = CNodes.size();
		//	std::ofstream OutFile;
		//	OutFile.open("nodes.dat", std::ios::out | std::ios::binary);
		//	if (!CNodes.empty())
		//	{
		//		OutFile.write(reinterpret_cast<char*>(&ss), sizeof(ss));
		//		OutFile.write(reinterpret_cast<char*>(&CNodes[0]), CNodes.size() * sizeof(CNodes[0]));
		//	}

		//	OutFile.close();
		//	OutFile = std::ofstream();
		//	size_t ss2 = CBranches.size();
		//	OutFile.open("branches.dat", std::ios::out | std::ios::binary);
		//	if (!CBranches.empty())
		//	{
		//		OutFile.write(reinterpret_cast<char*>(&ss2), sizeof(ss2));
		//		OutFile.write(reinterpret_cast<char*>(&CBranches[0]), CBranches.size() * sizeof(CBranches[0]));
		//	}

		//	OutFile.close();

		//}
		//if (event.key.code == sf::Keyboard::L)//load
		//{
		//	std::vector<Branch> branchess;
		//	std::vector<Node> nodesss;

		//	rsize_t size1 = 0;
		//	std::ifstream read("nodes.dat", std::ios::out | std::ios::binary);
		//	read.read(reinterpret_cast<char*>(&size1), sizeof(size1));
		//	if (CNodes.size() < size1)
		//	{
		//		nodesss = std::vector<Node>(size1, Node());
		//	}
		//		read.read(reinterpret_cast<char*>(&nodesss[0]), size1 * sizeof(CNodes[0]));
		//	read.close();
		//	rsize_t size2 = 0;
		//	 read= std::ifstream("branches.dat", std::ios::out | std::ios::binary);
		//	 read.read(reinterpret_cast<char*>(&size2), sizeof(size2));
		//	 if (CBranches.size()<size2)
		//	 {
		//		 branchess = std::vector<Branch>(size2,Branch());
		//	 }
		//	 read.read(reinterpret_cast<char*>(&branchess[0]), size2 * sizeof(CBranches[0]));
		//	read.close();
		//	CBranches.clear();
		//	for (int x = 0; x < branchess.size(); x++)
		//	{
		//		Branch b = branchess[x];
		//		CBranches.push_back(branchess[x]);
		//	}
		//	CNodes = std::vector<Node>(nodesss);
		//}
		if (event.key.code == sf::Keyboard::F)
		{
			coder::rtString rr;
			double succed = 0;
			int sizee = Input.size();
			TheInputXX = new char[sizee];
			for (int x = 0; x < Input.size(); x++)
			{
				char test = Input[x];
				TheInputXX[x] =test;
			
			}
			int size[2] = {1, (Input.size()) };
			rr.init(TheInputXX, size);
			solveIt->solver1(&rr, arrayOfNodesIds, arrayOfPotentialVs, &succed);
			delete []TheInputXX;
		}
		if (event.key.code == sf::Keyboard::R)
		{
			//oFile = std::ifstream("nodes.txt");
			//if (oFile.is_open())
			//{
			//	while (std::getline(oFile, line))
			//	{
			//		for (char& letter : line)
			//		{
			//			if (letter != ' ' && letter != ','&&letter!='e')
			//			{// numbers are allowed dots are allowed 
			//					temp += letter;
			//				
			//			}
			//			else if (letter == ',')
			//			{
			//				node_id = std::stoi(temp);
			//				temp = "";
			//			}
			//			else if(letter == 'e')
			//			{
			//				
			//				
			//			}
			//			else
			//			{//prepare for the next line
			//				node_value = std::stod(temp);
			//				temp = "";
			//			}
			//		}
			//		index = node_id - 1;
			//		CNodes[index].V = node_value;
			//		
			//	}
			//}
			//oFile.close();
			int sizee = arrayOfNodesIds.numel();
			for (int c = 0; c <sizee ; c++)
			{
				int indexxx = arrayOfNodesIds[c] - 1;
				CNodes[indexxx].V = arrayOfPotentialVs[c];
			}
			for (CBranchesIter = CBranches.begin(); CBranchesIter != CBranches.end(); ++CBranchesIter)
			{
				if((*CBranchesIter).Type=='r')
				(*CBranchesIter).GetCurrent(CNodes,CBranches);
			}	
			for (CBranchesIter = CBranches.begin(); CBranchesIter != CBranches.end(); ++CBranchesIter)
			{
				if((*CBranchesIter).Type=='v')
				(*CBranchesIter).GetCurrent(CNodes,CBranches);
			}

		}

		if (event.key.code == sf::Keyboard::W)
		{
			
		}
		if (event.key.code == sf::Keyboard::Q)
			{
				//stop = true;
				Input = Input + ";";
				std::cout << "\n\n\n" << Input << "\n\n";
			//	std::cin.get();
		}
		if (!ValueInput.show)
		{
			if (event.key.code == sf::Keyboard::G)
			{
				if (inverse_angle_support_wire == 0)
					inverse_angle_support_wire = 180;
				else
					inverse_angle_support_wire = 0;
			}
			if (event.key.code == sf::Keyboard::I)
			{
				size_t NumberOfBranchers = CBranches.size();
				CBranches.clear();
				CNodes.clear();
				CNodes.push_back(earthPermenant);
				ss = std::stringstream();
				Input = "";
				
			}
			if (event.key.code == sf::Keyboard::K)
			{
				parallelDistance -= 0.5;
				
			}
			if (event.key.code == sf::Keyboard::J)
			{
				parallelDistance += 0.5;
			}
			if (event.key.code == sf::Keyboard::M)
			{
				ManualParallelElements = !ManualParallelElements;

			}

			if (event.key.code == sf::Keyboard::V)
			{
				if (type == 'v')
				{
					specificAngleModification = 0;
					type = 'r';
					element_INFO.setOrigin(default_text_origin);
					currentGraph = s2;
					wireShapeObj.setFillColor(sf::Color::Red);
				}
				else
				{
					specificAngleModification = 90;
					type = 'v';
					element_INFO.setOrigin(19, -28);
					currentGraph = s1;
					wireShapeObj.setFillColor(sf::Color::Green);
				}
			}if (event.key.code == sf::Keyboard::C)
			{
				if (type == 'v')
				{
					if (type2 == 1)
					{
						type2 = 2;
					//	specificAngleModification = 0;
						//type = 'r';
						//element_INFO.setOrigin(default_text_origin);
						//currentGraph = s2;
						//wireShapeObj.setFillColor(sf::Color::Red);
					}
					else
					{
						type2 = 1;
					}
				}
			}
		}
	}
		if (event.type == sf::Event::MouseButtonPressed|| event.type == sf::Event::KeyPressed)
		{
			if(!ValueInput.show)
			PreInputMousePos = sf::Mouse::getPosition(window);

			if (event.key.code == sf::Mouse::Left|| event.key.code == sf::Keyboard::Enter)
			{
			
				if (pressed)
				{
						ValueInput.show = true;
					if (ValueInput.Button_OnClick(window, ValueInput.ok_button, Value, event))
					{

						int index = 0;
						pressed = false;
						bool clickedOnExistNode = false;

						////for (nodesIter = nodes.begin(); nodesIter != nodes.end(); ++nodesIter) 
						for (CNodesIter = CNodes.begin(); CNodesIter != CNodes.end(); ++CNodesIter)
						{
							///if (((*nodesIter).getGlobalBounds().contains(v.x, v.y)))
							if (((*CNodesIter).nodeDraw.getGlobalBounds().contains(PreInputMousePos.x, PreInputMousePos.y)))
							{

								clickedOnExistNode = true;
								break;
							}
							else
							{
								//clickedOnExistNode = false
							}
							index = index + 1;
						}
						if (!clickedOnExistNode)
						{
							////nodes.push_back(pointer);//zod node
///								EndIndexx = nodes.size();//el index fy elmatlab bybd2 mn el 1 3shan keda msh lazm 2zwed wa7d

							parallelElements = ManualParallelElements = false;
							EndIndexx = CNodes.size() + 1;//3shan lesa m3mltsh push_back
							To.id = EndIndexx;
							if(type2!=2)
							To.nodeDraw = pointer;
							To.connected_nodes_indexes.push_back(startIndex);
							CNodes[startIndex - 1].connected_nodes_indexes.push_back(EndIndexx);
							CNodes.push_back(To);
							if (type2 == 2)
							{
								To.nodeDraw = pointer;

								CNodes.push_back(To);
							}
							To.connected_nodes_indexes.clear();
							To.nodeDraw = sf::CircleShape();
						}
						else
						{
							EndIndexx = index + 1;
							CNodes[startIndex - 1].connected_nodes_indexes.push_back(EndIndexx);
							CNodes[EndIndexx - 1].connected_nodes_indexes.push_back(startIndex);
							//for (int x = 0; x < CNodes.at(index).connected_nodes_indexes.size(); x++)
							//{
							//	if (startIndex == CNodes.at(index).connected_nodes_indexes.at(x))
							//	{
							//		///                 5                  6
							//		///                 |                  |
							//		///                 |                  |
							//		///                 |                  |
							//		///                 |                  |
							//		/// 8---------------1------------------2------------------7
							//		///                 |                  |
							//		///                 |                  |
							//		///                 |                  |
							//		///                 |                  |
							//		///                 4                  3
							//		/// 3ayz 2wsal 1 b 2 w hma 2sln mtwasalyn  2 3ndha connected nodes ( 1 w 7 w 6 w 3 )
							//		
							//		///double radAngle = (angle+90) * pi / 180;
							//		sf::Vector2f t1, f1;
							//		t1 = To.nodeDraw.getPosition();
							//		f1 = From.nodeDraw.getPosition();

							//		double radAngle = std::atan(std::abs(t1.y - f1.y) / std::abs(t1.x - f1.x));
							//		radAngle = radAngle + (pi / 2);
							//		double offsetX = std::cos(radAngle) * 100;
							//		double offsetY = std::sin(radAngle) * 100;
							//		currentGraph.move(offsetX, offsetY);
							//		wireShapeObj.move(offsetX, offsetY);
							//		element_INFO.move(offsetX, offsetY);
							//	
							//		support1 = wireShapeObj;
							//		sf::Vector2f sss = t.getSize();
							//		sss.x = sqrt(pow(offsetX, 2) + pow(offsetY, 2));
							//		angle = radAngle * 180 / pi;
							//		tempoBranch.Wire.setRotation(angle - 90);
							//		t.setRotation(angle);//dh bysht8l degrees
							//		t.setSize(sss);
							//		t.setFillColor(sf::Color::Red);
							//		t.setPosition(To.nodeDraw.getPosition());
							//		tempoBranch.SupportiveWires.push_back(t);
							//		
							//		t.setPosition(From.nodeDraw.getPosition());
							//		tempoBranch.SupportiveWires.push_back(t);
							//	}

							//}
							if (parallelElements || ManualParallelElements)
							{
								tempoBranch.SupportiveWires.push_back(support1);
								tempoBranch.SupportiveWires.push_back(support2);

							}
						}

						To.id = EndIndexx;
						// things dont affected : (will be drawn any way)

						/*/////branches.push_back(wireShapeObj);
						graphs.push_back(currentGraph);*/
						if (Value != 0)
						tempoBranch.ElementDraw = currentGraph;
						else
							tempoBranch.ElementDraw = sf::Sprite();
							tempoBranch.Wire = wireShapeObj;
						////==============================
						std::string temp="";
						std::stringstream sss;
						sss << std::fixed << std::setprecision(2) << Value;
						sss >> temp;
					//	if(Value!=null)
						temp += " ";
						if (type == 'r')
							temp += "Ohm";
						else
							temp += type;

						element_INFO.setString(temp);

						//	element_INFO.setPosition(currentGraph.getPosition());
						element_INFO.setRotation(text_angle);///rotation angle
						if (Value != 0)
							tempoBranch.InfoDisplay = element_INFO;
						else
							tempoBranch.InfoDisplay.setString("");
						////=================================
					//	std::cout << "Enter The Value Of " << type << " : ";
					//	std::cin >> Value;
						tempoBranch.To = To.id;
						tempoBranch.From = From.id;


						tempoBranch.Value = Value;



						tempoBranch.Type = type;
						

						CBranches.push_back(tempoBranch);
						tempoBranch.SupportiveWires.clear();
						//tempoBranch.
						// .clear();
						//From.Branches.push_back(tempoBranch);
						//	To.Branches.push_back(tempoBranch);
						//	if (Value == -9)
						//	{
						//		stop = true;
						//		Input = Input + ";";
						//	}
						//	else
						//	{
						std::stringstream optimiser;
						std::string tempoo="";
						
						if(Value!=0)
						optimiser <<std::fixed<<std::setprecision(2) <<Value;
						else
							optimiser << std::setprecision(1) << Value;
						optimiser >> tempoo;
						ss <<std::to_string(startIndex) << "," << type << ',' << std::to_string(EndIndexx) << "-" << tempoo << " ";
						if (type2 == 2)
						{
							double ValueX = Value * 99999999;
							std::stringstream optimiserX;
							std::string tempooX = "";
							optimiserX << std::fixed << std::setprecision(2) << ValueX;
							optimiserX >> tempooX;
							ss << std::to_string(EndIndexx) << "," << type << ',' << std::to_string(EndIndexx + 1) << "-" << tempooX << " ";
						}
						std::string x = ss.str();
						Input = ss.str();
						//	}
					}
				}
				else///First Press
				{
				parallelElements = ManualParallelElements = false;
					int index = 0;
					///	for (nodesIter = nodes.begin(); nodesIter != nodes.end(); ++nodesIter)
						///{
							///if ((*nodesIter).getGlobalBounds().contains(v.x, v.y))
					for (CNodesIter = CNodes.begin(); CNodesIter != CNodes.end(); ++CNodesIter)
					{
						///if (((*nodesIter).getGlobalBounds().contains(v.x, v.y)))
						if (((*CNodesIter).nodeDraw.getGlobalBounds().contains(PreInputMousePos.x, PreInputMousePos.y)))
						{
							pressed = true;


							startIndex = index + 1;
							///centerPos = (*nodesIter).getPosition();
							centerPos = (*CNodesIter).nodeDraw.getPosition();
							From.id = startIndex;
							///wireShapeObj.setPosition((*nodesIter).getPosition());
							wireShapeObj.setPosition((*CNodesIter).nodeDraw.getPosition());
						}
						index += 1;
					}
					//tan = std::abs(tan);
				}

			}
		}
	}
	
	void ElementsAttitude()
	{ 
		sf::Vector2f oldGraphPos, oldTextPos, oldWirePos;
			v = sf::Mouse::getPosition(window); // getting mouse position
		if (pressed == true)
		{
			InfoDisplay.show = false;
			if (parallelElements == false)
			{

			v3 = wireShapeObj.getSize();
			v2 = wireShapeObj.getPosition();
			pointer.setPosition(v.x, v.y);
			pointer.setFillColor(sf::Color::Red);
			distance = std::sqrt(std::pow((centerPos.x - v.x), 2) + std::pow((centerPos.y - v.y), 2));
				wireShapeObj.setSize(sf::Vector2f(distance, v3.y));


				/// <summary>
				///  we have here centerPos As From And Pointer As To
				/// </summary>

				double tan = (v.y - centerPos.y) / (v.x - centerPos.x);

				//tan = std::abs(tan);
				angle = std::atan(tan);


				angle = ((angle * 180.0) / pi);
				text_angle = angle;
				
				if (((v.y - centerPos.y) >= 0 && (v.x - centerPos.x) < 0) || ((v.y - centerPos.y) <= 0 && (v.x - centerPos.x) < 0))
				{
					angle += 180;
				}
				//else if(angle)
				wireShapeObj.setRotation(angle);
				currentGraph.setRotation(angle + specificAngleModification);
				double pos_x = ((v.x) + centerPos.x), pos_y = (v.y + centerPos.y);
				currentGraph.setPosition(((v.x + centerPos.x) / 2.0), ((v.y + centerPos.y) / 2.0));
				wireShapeObj.setPosition(centerPos);
				element_INFO.setString(type);

				element_INFO.setPosition(currentGraph.getPosition());
				element_INFO.setRotation(text_angle);///rotation angle
				oldGraphPos = currentGraph.getPosition();
				oldTextPos = element_INFO.getPosition();
				oldWirePos = centerPos;
			}
			
			
			sf::Vector2f v_to, v_from;
		//	t1 = To.nodeDraw.getPosition();//to
			v_from = centerPos;//From


			double radAngle=0;
			double degAngle=0;
			//radAngle = radAngle + (pi / 2);
	

			sf::Vector2f sss;// = wireShapeObj.getSize();
			// = sqrt(pow(offsetX, 2) + pow(offsetY, 2));
			//degAngle = radAngle * 180 / pi;

			//support1 = wireShapeObj;
				////for (nodesIter = nodes.begin(); nodesIter != nodes.end(); ++nodesIter)
	 sss = wireShapeObj.getSize();
	 double offsetX;// = std::cos(radAngle) * 100;
	 double offsetY;// = std::sin(radAngle) * 100;
	 //AutoMatic Parallel Mode
			for (CNodesIter = CNodes.begin(); CNodesIter != CNodes.end(); ++CNodesIter)
			{
				///if (((*nodesIter).getGlobalBounds().contains(v.x, v.y)))
				if (((*CNodesIter).nodeDraw.getGlobalBounds().contains(v.x, v.y)))
				{
					pointer.setFillColor(sf::Color::Yellow);
					for (int x = 0; x < (*CNodesIter).connected_nodes_indexes.size(); x++)
					{

						if (startIndex == (*CNodesIter).connected_nodes_indexes.at(x))
						{
							v_to = (*CNodesIter).nodeDraw.getPosition();
							parallelElements = true;
							break;
						}
						//else
							
					}
					if (parallelElements)
						break;


				}
				else
					parallelElements = false;
				if (parallelElements)
					break;
				
				///test.setPosition(((v.x + centerPos.x )/ 2.0), ((v.y + centerPos.y) / 2.0));
			}
			if (parallelElements||ManualParallelElements)
			{
				if (ManualParallelElements)
				{
					v_to.x = v.x;//The Opposite Node To The From Node = Mouse Which points To It Or Into its area
					v_to.y = v.y;
				}
				radAngle = std::atan((v_to.y - v_from.y) / (v_to.x - v_from.x));

				radAngle = radAngle + (pi / 2);
				degAngle = radAngle * 180 / pi;
				if (((v_to.y - centerPos.y) >= 0 && (v_to.x - centerPos.x) < 0) || ((v_to.y - centerPos.y) <= 0 && (v_to.x - centerPos.x) < 0))//i didnt put <= as when (v_to.x - centerPos.x)  = 0 as the((v_to.y - centerPos.y) will specify whether it is +inf or - inf whether it is 90 or -90
				{
					radAngle += pi;
					degAngle += 180;
				}
				offsetX = std::cos(radAngle) * parallelDistance;
				offsetY = std::sin(radAngle) * parallelDistance;

				if (inverse_angle_support_wire > 0)
				{
					offsetX *= -1;
					offsetY *= -1;
				}
				tempoBranch.Offset.x = offsetX;
				tempoBranch.Offset.y = offsetY;
				sss.x = sqrt(pow(offsetX, 2) + pow(offsetY, 2));
				//wireShapeObj.setPosition((*CNodesIter).nodeDraw.getPosition().x + offsetX, (*CNodesIter).nodeDraw.getPosition().y + offsetY);
				oldGraphPos.x = (v_to.x + centerPos.x) / 2;
				oldGraphPos.y = (v_to.y + centerPos.y) / 2;
				oldTextPos = oldGraphPos;
				wireShapeObj.setPosition(centerPos.x + offsetX, centerPos.y + offsetY);
				currentGraph.setPosition(oldGraphPos.x + offsetX, oldGraphPos.y + offsetY);
				element_INFO.setPosition(oldTextPos.x + offsetX, oldTextPos.y + offsetY);
				wireShapeObj.setRotation((degAngle - 90));
				int SAM = (specificAngleModification == 90) ? 0 : 90;
				currentGraph.setRotation(degAngle+ SAM);
				support1.setRotation(degAngle+inverse_angle_support_wire);//dh bysht8l degrees
				support1.setSize(sss);
				support1.setFillColor(sf::Color::Red);
				support2 = support1;
				support1.setPosition(v_to);
				support2.setPosition(v_from);
			}
		/*	std::cout << "Mouse : [y] : " << v.y << " [x] : " << v.x << " angle : " << degAngle<<" [ "<< counter <<" ] " << " \n ";
			std::cout << "V_To : [y] : " << v_to.y << " [x] : " << v_to.x << " angle : " << degAngle  << " [ " << counter << " ] " << " \n ";
			std::cout << "V_From : [y] : " << v_from.y << " [x] : " << v_from.x << " angle : " << degAngle  << " [ " << counter << " ] " << " \n ";
			std::cout << "V_To - V_From : [y] : " << v_to.y-v_from.y << " [x] : " << v_to.x - v_from.x << " angle : " << degAngle  << " [ " << counter << " ] " << " \n ";
			std::cout << "Tan : " <<( v_to.y-v_from.y)/( v_to.x - v_from.x) << " angle : " << degAngle << " [ " << counter << " ] " << " \n ";
			std::cout << "Rad : " <<std::atan( (v_to.y-v_from.y)/( v_to.x - v_from.x)) << " angle : " << degAngle  << " [ " << counter << " ] " << " \n ";
			std::cout << "Parallel Mode : " << parallelElements << " [ " << counter << " ] "<< "\n";
			counter++;*/
		}
		else
		{
		bool eitherIsSelected = false;
		for (CNodesIter = CNodes.begin(); CNodesIter != CNodes.end(); ++CNodesIter)
		{
		//	InfoDisplay.show = false;
			///if (((*nodesIter).getGlobalBounds().contains(v.x, v.y)))
			if (((*CNodesIter).nodeDraw.getGlobalBounds().contains(v.x, v.y)))
			{
			//	pointer.setFillColor(sf::Color::Yellow);
			//	for (int x = 0; x < (*CNodesIter).connected_nodes_indexes.size(); x++)
				{
				//	std::cout << "\nNode( " << (*CNodesIter).id << " ) " << "Has Connection With Node ( " << (*CNodesIter).connected_nodes_indexes[x] << " )\n";


					//if (startIndex == (*CNodesIter).connected_nodes_indexes.at(x))
					{
				/*		v_to = (*CNodesIter).nodeDraw.getPosition();
						parallelElements = true;
						break;
				*/	}
					//else

				}
				Node n = (*CNodesIter);
				sf::Vector2f nodePos = n.nodeDraw.getPosition();
				InfoDisplay.SetInfoWindowPosition(nodePos.x, nodePos.y);
				std::stringstream ff;
				ff <<std::fixed <<std::setprecision(3) << n.V;
				std::string tt;
				ff >> tt;
				InfoDisplay.SetInfoWindowValues("Id : "+ std::to_string(n.id), "Volt : "+ tt);
				InfoDisplay.show = true;
				eitherIsSelected = true;
				break;
			}
		

			///test.setPosition(((v.x + centerPos.x )/ 2.0), ((v.y + centerPos.y) / 2.0));
		}
		for (CBranchesIter = CBranches.begin(); CBranchesIter!= CBranches.end(); ++CBranchesIter)
		{
			//InfoDisplay.show = false;
			///if (((*nodesIter).getGlobalBounds().contains(v.x, v.y)))
			if (/*((*CBranchesIter).Wire.getGlobalBounds().contains(v.x, v.y))||*/ ((*CBranchesIter).ElementDraw.getGlobalBounds().contains(v.x, v.y)))
			{
				Branch b = (*CBranchesIter);
			//	if (b.Type == 'r')
				{
					b.Current = std::abs(b.Current);
					sf::Vector2f branchPos = b.ElementDraw.getPosition();
					InfoDisplay.SetInfoWindowPosition(branchPos.x, branchPos.y);
					std::stringstream ff;
					ff << std::fixed<<std::setprecision(3) << b.Current;
					std::string tt;
					ff >> tt;
					InfoDisplay.SetInfoWindowValues( "Curr : " +tt,"");
				
					InfoDisplay.show = true;
					eitherIsSelected = true;

					break;
				}
				}
		
		}
		if(!eitherIsSelected)
			InfoDisplay.show = false;

 }


	}




	

	//
	// Arguments    : int32_T argc
	//                char **argv
	// Return Type  : int32_T
	//
	







