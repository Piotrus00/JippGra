#include <SFML/Graphics.hpp>

class Settings {
public:
	sf::Text sett_skin_selection;
	sf::Text sett_time_selection;
	sf::Text sett_radius_selection;
	sf::Text sett_number_of_points_selection;
	sf::Text sett_quit;
	sf::RectangleShape rectangle_sett_quit;
	Settings() {
		font.loadFromFile("OpenSans-Regular.ttf");
		sett_skin_selection.setString("Choose Skin");
		sett_skin_selection.setFont(font);
		sett_skin_selection.setCharacterSize(50);
		sett_skin_selection.setPosition(screenWidth / 6.f, 200);


		sett_time_selection.setString("Choose Time For Circle To Disappear");
		sett_time_selection.setFont(font);
		sett_time_selection.setCharacterSize(50);
		sett_time_selection.setPosition(screenWidth / 6.f, 600);


		sett_number_of_points_selection.setString("Select Number Of Circles To Click");
		sett_number_of_points_selection.setFont(font);
		sett_number_of_points_selection.setCharacterSize(50);
		sett_number_of_points_selection.setPosition(screenWidth / 6.f, 1000);


		sett_radius_selection.setString("Choose Radius Of Circle");
		sett_radius_selection.setFont(font);
		sett_radius_selection.setCharacterSize(50);
		sett_radius_selection.setPosition(screenWidth / 6.f, 1400);

		rectangle_sett_quit.setSize(sf::Vector2f(150, 100));
		rectangle_sett_quit.setFillColor(sf::Color::Transparent);
		rectangle_sett_quit.setPosition(screenWidth * (5 / 6.f), 1200);
		sett_quit.setString("Quit");
		sett_quit.setFont(font);
		sett_quit.setCharacterSize(75);
		sett_quit.setPosition(screenWidth * (5 / 6.f), 1200);


	}
private:
	sf::Font font;

	unsigned int screenWidth = sf::VideoMode::getDesktopMode().width;
	unsigned int screenHeight = sf::VideoMode::getDesktopMode().height;
};