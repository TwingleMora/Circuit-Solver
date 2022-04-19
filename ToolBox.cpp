#include "ToolBox.h"


template<class T>
ToolBox<T>::ToolBox()
{

}


template <class T>
void ToolBox<T>::SetInfoWindowValues(std::string id, std::string voltage)
{
	Id_Label.setString(id);
	Voltage_Label.setString(voltage);
}
template <class T>
void ToolBox<T>::SetInfoWindowPosition(float posx, float posy)
{
	float left_padding = 0;
	int width = info_window_width;
	int height = info_window_height;
//buttonOffsetX = -10;
mWindow.setPosition(posx + windowOffsetX, posy + windowOffsetY);
Title.setPosition(posx + width / 3,		posy + 10);
Id_Label.setPosition(posx + 5 + windowOffsetX, (posy +( height / 3) + windowOffsetY));// posx + (width + 10) / 2  not the same as (posx + width + 10) / 2
Voltage_Label.setPosition(posx +5 + windowOffsetX , (posy + (height / 3) - 5 + windowOffsetY)+80);
//ok_button.setPosition(((posx + width / 2 - 30) + buttonOffsetX + windowOffsetX), ((posy + height) / 2) + 200 + buttonOffsetY + windowOffsetY);
//ok_text.setPosition(((posx + width / 2 - 10) + buttonOffsetX + windowOffsetX), ((posy + height) / 2) + 202 + buttonOffsetY + windowOffsetY);
}
template <class T>
void ToolBox<T>::InfoWindow(int width, int height, std::string title)
{
	//float posx = Info_Window_Pos_X,posy=Info_Window_Pos_Y;
	info_window_width = width;
	info_window_height = height;
	
	font.loadFromFile("fonts/arial.ttf");
	Title.setFont(font);
	ok_text.setFont(font);
	Id_Label.setFont(font);
	Voltage_Label.setFont(font);

	sf::Color c;
	c = sf::Color::Black;
	c.a = 100;
	mWindow.setFillColor(c);
	Title.setFillColor(sf::Color::White);
	ok_text.setFillColor(sf::Color::White);
//	value_textbox.setFillColor(sf::Color::Black);
	Id_Label.setFillColor(sf::Color::White);
	Voltage_Label.setFillColor(sf::Color::White);

	Title.setString(title);
	ok_text.setString("Ok");
	//value_textbox.setString("");
	sf::Vector2f size = sf::Vector2f(width, height);
	mWindow.setSize(size);

	size.x = size.x - 10;
	size.y = 30;
	mWindow.setOutlineColor(sf::Color::White);
	mWindow.setOutlineThickness(5);

	Text.setSize(size);
	

	size.x = 80;
	size.y = 40;

	ok_button.setSize(size);
	
	//ok_button.setFillColor(sf::Color::Blue);
	//ok_text.setStyle(sf::Text::Bold);
	
	
}
template <class T>
void ToolBox<T>::InputWindow(double posx, double posy, int width, int height,std::string title)
{
	buttonOffsetX = -10;
	font.loadFromFile("fonts/arial.ttf");
	Title.setFont(font);
	ok_text.setFont(font);
	value_textbox.setFont(font);
	Title.setPosition(posx + width/7, posy + 10);
	Title.setFillColor(sf::Color::White);
	ok_text.setFillColor(sf::Color::White);
	value_textbox.setFillColor(sf::Color::Black);
	Title.setString(title);
	ok_text.setString("Ok");
	value_textbox.setString("");
	sf::Vector2f size = sf::Vector2f(width, height);
	mWindow.setSize(size);
	mWindow.setPosition(posx+ windowOffsetX, posy+ windowOffsetY);
	size.x = size.x - 10;
	size.y = 30;
	mWindow.setOutlineColor(sf::Color::White);
	mWindow.setOutlineThickness(5);
	mWindow.setFillColor(sf::Color::Black);
	Text.setSize(size);
	Text.setPosition((posx + width+10) / 2+ windowOffsetX, ((posy + height/3)+ windowOffsetY));
	value_textbox.setPosition((posx + width+10) / 2+ windowOffsetX, ((posy + height/3)-5+ windowOffsetY));
	size.x = 80;
	size.y = 40;
	Text.setFillColor(sf::Color::White);
	ok_button.setSize(size);
	ok_button.setPosition(((posx + width/2-30) +buttonOffsetX+ windowOffsetX),((posy + height) / 2)+200+buttonOffsetY+ windowOffsetY);
	ok_button.setFillColor(sf::Color::Blue);
	ok_text.setStyle(sf::Text::Bold);
	value_textbox.setStyle(sf::Text::Bold);
	ok_text.setPosition(((posx + width / 2 -10)+buttonOffsetX+ windowOffsetX), ((posy + height) / 2) + 202+buttonOffsetY+windowOffsetY);

}
template <class T>
void ToolBox<T>::DrawInfoWindow(sf::RenderWindow& window)
{
	if (show)
	{
		window.draw(mWindow);
		
	//	window.draw(ok_button);
		//window.draw(ok_text);
		window.draw(Title);
		window.draw(Voltage_Label);
		window.draw(Id_Label);

	}
}
template <class T>
void ToolBox<T>::DrawInputWindow(sf::RenderWindow& window)
{
	if (show)
	{
		window.draw(mWindow);
		window.draw(Text);
		window.draw(ok_button);
		window.draw(ok_text);
		window.draw(Title);
		window.draw(value_textbox);
	}
}
template<class T>
void ToolBox<T>::GetInput(sf::Event& e)
{
	if (show)
	{
	
			if (e.type == sf::Event::TextEntered) {
			if (std::isprint(e.text.unicode))
				if (e.text.unicode < 128) {//
					input += static_cast<char>(e.text.unicode);
					value_textbox.setString(input);

				}	
			}
	    	else if (e.type == sf::Event::KeyPressed)
			{
				if (e.key.code == sf::Keyboard::Backspace)
				{
					input = input.substr(0, input.size() - 1);
					value_textbox.setString(input);
				}
		    }
		//else if()
	
	}
	else//lma y2fel
	{
		input = "";
		value_textbox.setString("");
	}
}
template <class T>
bool ToolBox<T>::Button_OnClick(const sf::RenderWindow& window,  sf::RectangleShape Button ,T &Output, sf::Event& e)//3shan 2wafr fy el memory instead of copying the content to new variables
{
	Output = 0.0;
	if (show)
	{
		if (input != "")
		{
			sf::Vector2i mosPos = sf::Mouse::getPosition(window);
			if (e.type == sf::Event::MouseButtonPressed)
			{
				if (e.key.code == sf::Mouse::Left)
				{
					if (Button.getGlobalBounds().contains(mosPos.x, mosPos.y))
					{
						Output = ::atof(input.c_str());
						show = false;
						Button_Pressed = true;
						return true;
					}
				}
			}
			if (e.type == sf::Event::KeyPressed)
			{
				if (e.key.code == sf::Keyboard::Enter)
				{
					
				//	Output = std::stof(input);//.c_str() convert strijng to char
					Output = ::atof(input.c_str());
					//std::stringstream ss;
					show = false;
					Button_Pressed = true;
					return true;
				}
			}
		}
			return false;
	}
	else
		return true;

}

