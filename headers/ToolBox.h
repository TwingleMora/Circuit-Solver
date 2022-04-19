#pragma once
#include <vector>
#include<SFML\Graphics.hpp>
#include<iostream>

template<class T>
 class ToolBox
{
public:

	ToolBox();

	std::string input = "";
	int width;
	int height;
	bool show = false;
	sf::Font font;
	sf::Text Title;
	sf::Text ok_text; //Text On Button
	sf::Text value_textbox;
	sf::RectangleShape mWindow;
	sf::RectangleShape Text;
	sf::RectangleShape ok_button;
	void DrawInputWindow(sf::RenderWindow& window);
	void DrawInfoWindow(sf::RenderWindow& window);
	float buttonOffsetX=0, buttonOffsetY=0;
	float windowOffsetX=0, windowOffsetY=0; 
	float voltage_current_offset_y = 0;
	
	float Info_Window_Pos_X = 0, Info_Window_Pos_Y = 0;

	bool Button_Pressed = false;
	void InputWindow(double posx, double posy, int width, int height,std::string title);
	void InfoWindow(int width, int height, std::string title);
	int info_window_width = 0, info_window_height = 0;
	void SetInfoWindowPosition(float x, float y);
	void SetInfoWindowValues(std::string id, std::string voltage);

	sf::Text Id_Label;// "Id : " + id
	sf::Text Voltage_Label;// "Volt : " + id
	
	void GetInput(sf::Event& e);

			bool Button_OnClick(const sf::RenderWindow& window,  sf::RectangleShape Button,T& Output, sf::Event& e);//3shan 2wafr fy el memory instead of copying the content to new variables
	


};
 

#include"ToolBox.cpp"