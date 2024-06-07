#include <SFML/Graphics.hpp>

class Settings {
public:
	sf::Text sett_skin_selection;
	sf::Text sett_time_selection;
	sf::Text sett_radius_selection;
	sf::Text sett_number_of_points_selection;
	sf::Text sett_quit;
	sf::RectangleShape rectangle_sett_quit;
	
	sf::RectangleShape rectangle_sett_skin_increase;
	sf::RectangleShape rectangle_sett_skin_reduce;
	sf::RectangleShape rectangle_sett_time_increase;
	sf::RectangleShape rectangle_sett_time_reduce;
	sf::RectangleShape rectangle_sett_radius_increase;
	sf::RectangleShape rectangle_sett_radius_reduce;
	sf::RectangleShape rectangle_sett_number_of_points_increase;
	sf::RectangleShape rectangle_sett_number_of_points_reduce;

	sf::Text plus_skin;
	sf::Text plus_time;
	sf::Text plus_number;
	sf::Text plus_radius;

	sf::Text minus_skin;
	sf::Text minus_time;
	sf::Text minus_number;
	sf::Text minus_radius;


	Settings() {


		//skin


		font.loadFromFile("OpenSans-Regular.ttf");
		sett_skin_selection.setString("Skin");
		sett_skin_selection.setFont(font);
		sett_skin_selection.setCharacterSize(50);
		sett_skin_selection.setPosition(300, 200);

			//rect

		rectangle_sett_skin_reduce.setSize(sf::Vector2f(200, 100));
		rectangle_sett_skin_reduce.setPosition(300, 385);
		rectangle_sett_skin_reduce.setFillColor(sf::Color::Transparent);   
		rectangle_sett_skin_increase.setSize(sf::Vector2f(200, 100));
		rectangle_sett_skin_increase.setPosition(800, 385);
		rectangle_sett_skin_increase.setFillColor(sf::Color::Transparent);
		
			//plus

		plus_skin.setFont(font);
		plus_skin.setString("+");
		plus_skin.setCharacterSize(100);
		plus_skin.setOrigin(plus_skin.getGlobalBounds().getSize() / 2.f + plus_skin.getLocalBounds().getPosition());
		plus_skin.setPosition(rectangle_sett_skin_increase.getPosition() + (rectangle_sett_skin_increase.getSize() / 2.f));

			//minus

		minus_skin.setFont(font);
		minus_skin.setString("-");
		minus_skin.setCharacterSize(100);
		minus_skin.setOrigin(minus_skin.getGlobalBounds().getSize() / 2.f + minus_skin.getLocalBounds().getPosition());
		minus_skin.setPosition(rectangle_sett_skin_reduce.getPosition() + (rectangle_sett_skin_reduce.getSize() / 2.f));
		

		//time


		sett_time_selection.setString("Time");
		sett_time_selection.setFont(font);
		sett_time_selection.setCharacterSize(50);
		sett_time_selection.setPosition(300, 600);

			//rect

		rectangle_sett_time_reduce.setSize(sf::Vector2f(200, 100));
		rectangle_sett_time_reduce.setPosition(300, 785);
		rectangle_sett_time_reduce.setFillColor(sf::Color::Transparent);
		rectangle_sett_time_increase.setSize(sf::Vector2f(200, 100));
		rectangle_sett_time_increase.setPosition(800, 785);
		rectangle_sett_time_increase.setFillColor(sf::Color::Transparent);
		
			//plus
		
		plus_time.setFont(font);
		plus_time.setString("+");
		plus_time.setCharacterSize(100);
		plus_time.setOrigin(plus_time.getGlobalBounds().getSize() / 2.f + plus_time.getLocalBounds().getPosition());
		plus_time.setPosition(rectangle_sett_time_increase.getPosition() + (rectangle_sett_time_increase.getSize() / 2.f));
		
			//minus

		minus_time.setFont(font);
		minus_time.setString("-");
		minus_time.setCharacterSize(100);
		minus_time.setOrigin(minus_time.getGlobalBounds().getSize() / 2.f + minus_time.getLocalBounds().getPosition());
		minus_time.setPosition(rectangle_sett_time_reduce.getPosition() + (rectangle_sett_time_reduce.getSize() / 2.f));


		//circles
		

		sett_number_of_points_selection.setString("Circles");
		sett_number_of_points_selection.setFont(font);
		sett_number_of_points_selection.setCharacterSize(50);
		sett_number_of_points_selection.setPosition(300, 1000);

			//rect

		rectangle_sett_number_of_points_reduce.setSize(sf::Vector2f(200, 100));
		rectangle_sett_number_of_points_reduce.setPosition(300, 1115);
		rectangle_sett_number_of_points_reduce.setFillColor(sf::Color::Transparent);

		rectangle_sett_number_of_points_increase.setSize(sf::Vector2f(200, 100));
		rectangle_sett_number_of_points_increase.setPosition(800, 1115);
		rectangle_sett_number_of_points_increase.setFillColor(sf::Color::Transparent);
			//plus
		plus_number.setFont(font);
		plus_number.setString("+");
		plus_number.setCharacterSize(100);
		plus_number.setOrigin(plus_number.getGlobalBounds().getSize() / 2.f + plus_number.getLocalBounds().getPosition());
		plus_number.setPosition(rectangle_sett_number_of_points_increase.getPosition() + (rectangle_sett_number_of_points_increase.getSize() / 2.f));
			//minus
		minus_number.setFont(font);
		minus_number.setString("-");
		minus_number.setCharacterSize(100);
		minus_number.setOrigin(minus_number.getGlobalBounds().getSize() / 2.f + minus_number.getLocalBounds().getPosition());
		minus_number.setPosition(rectangle_sett_number_of_points_reduce.getPosition() + (rectangle_sett_number_of_points_reduce.getSize() / 2.f));


		//radius


		sett_radius_selection.setString("Radius");
		sett_radius_selection.setFont(font);
		sett_radius_selection.setCharacterSize(50);
		sett_radius_selection.setPosition(300, 1400);

			//rect

		rectangle_sett_radius_reduce.setSize(sf::Vector2f(200, 100));
		rectangle_sett_radius_reduce.setPosition(300, 1515);
		rectangle_sett_radius_reduce.setFillColor(sf::Color::Transparent);
					   
		rectangle_sett_radius_increase.setSize(sf::Vector2f(200, 100));
		rectangle_sett_radius_increase.setPosition(800, 1515);
		rectangle_sett_radius_increase.setFillColor(sf::Color::Transparent);

			//plus

		plus_radius.setFont(font);
		plus_radius.setString("+");
		plus_radius.setCharacterSize(100);
		plus_radius.setOrigin(plus_radius.getGlobalBounds().getSize() / 2.f + plus_radius.getLocalBounds().getPosition());
		plus_radius.setPosition(rectangle_sett_radius_increase.getPosition() + (rectangle_sett_radius_increase.getSize() / 2.f));
			
			//minus

		minus_radius.setFont(font);
		minus_radius.setString("-");
		minus_radius.setCharacterSize(100);
		minus_radius.setOrigin(minus_radius.getGlobalBounds().getSize() / 2.f + minus_radius.getLocalBounds().getPosition());
		minus_radius.setPosition(rectangle_sett_radius_reduce.getPosition() + (rectangle_sett_radius_reduce.getSize() / 2.f));

		
		
		rectangle_sett_quit.setSize(sf::Vector2f(150, 100));
		rectangle_sett_quit.setFillColor(sf::Color::Transparent);
		rectangle_sett_quit.setPosition(screenWidth * (4.5 / 6.f), 1500);
		sett_quit.setString("Quit");
		sett_quit.setFont(font);
		sett_quit.setCharacterSize(75);
		sett_quit.setPosition(screenWidth * (4.5 / 6.f), 1500);
	}
private:
	sf::Font font;
	unsigned int screenWidth = sf::VideoMode::getDesktopMode().width;
	unsigned int screenHeight = sf::VideoMode::getDesktopMode().height;
};