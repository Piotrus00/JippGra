#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <random>

class Game {

public:

	sf::Text end_title;
	sf::Text end_try_again;
	sf::CircleShape circle;
	sf::RectangleShape rectangle_try_again;
	sf::Text stats_quit;
	sf::RectangleShape rectangle_stats_quit;


	Game() {
		radius = 20;
		max_num_circles = 5;
		circle.setRadius(radius);
		circle.setFillColor(sf::Color::Red);
		circle.setPosition(screenWidth / float(2) - 100, 750);
		duration = sf::milliseconds(2000);
	}


	void add_point() {
		points++;
	}


	void rand_position() {

		std::uniform_int_distribution<int> cord_x(2*radius, screenWidth - 2*radius);
		std::uniform_int_distribution<int> cord_y(2*radius, screenHeight - 2*radius);
		circle.setPosition(cord_x(seed), cord_y(seed));
		number_of_circles++;
		clock.restart();
	}

	bool is_end() {
		return number_of_circles >= max_num_circles;
	}

	void show_stats() {
		font.loadFromFile("OpenSans-Regular.ttf");
		end_title.setString("Score\n" + std::to_string(points)+ "/" + std::to_string(number_of_circles));
		end_title.setFont(font);
		end_title.setCharacterSize(200);
		end_title.setPosition(screenWidth/6.f, 600);
		
		rectangle_try_again.setSize(sf::Vector2f(420, 100));
		rectangle_try_again.setFillColor(sf::Color::Transparent);
		rectangle_try_again.setPosition(screenWidth * (4/6.f), 1000);
		end_try_again.setString("Try Again");
		end_try_again.setFont(font);
		end_try_again.setCharacterSize(100);
		end_try_again.setPosition(screenWidth * (4/6.f), 1000);


		rectangle_stats_quit.setSize(sf::Vector2f(200, 100));
		rectangle_stats_quit.setFillColor(sf::Color::Transparent);
		rectangle_stats_quit.setPosition(screenWidth * (4 / 6.f), 1200);
		stats_quit.setString("Quit");
		stats_quit.setFont(font);
		stats_quit.setCharacterSize(100);
		stats_quit.setPosition(screenWidth * (4 / 6.f), 1200);

	}

	void set_new_game() {
		points = 0;
		number_of_circles = 0;
		clock.restart();
	}

	bool time_measure() {
		return clock.getElapsedTime() > duration;
	}

private:
	sf::Font font;
	unsigned int radius;
	std::random_device seed;
	unsigned int points;
	unsigned int number_of_circles;
	sf::Clock clock;
	sf::Time duration;
	unsigned int screenWidth = sf::VideoMode::getDesktopMode().width;
	unsigned int screenHeight = sf::VideoMode::getDesktopMode().height;
	unsigned int max_num_circles;
};