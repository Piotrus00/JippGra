#include<SFML/Graphics.hpp>


class Menu {
public:

    sf::Text title;
    sf::RectangleShape rectangle_autistic;
    sf::Text undertitle;
    sf::RectangleShape rectangle_play;
    sf::Text play;
    sf::RectangleShape rectangle_sett;
    sf::Text sett;
    sf::RectangleShape rectangle_quit;
    sf::Text quit;

    Menu(unsigned int screenWidth) {

        font.loadFromFile("OpenSans-Regular.ttf");

        title.setString("AimLab");
        title.setFont(font);
        title.setCharacterSize(200);
        title.setOrigin(350, 100);
        title.setPosition(screenWidth / float(2), 600);

        rectangle_autistic.setSize(sf::Vector2f(200, 100));
        rectangle_autistic.setFillColor(sf::Color::Transparent);
        rectangle_autistic.setPosition(screenWidth / float(2) - 100, 750);
        undertitle.setString("Autistic");
        undertitle.setFont(font);
        undertitle.setFillColor(sf::Color::Transparent);
        undertitle.setCharacterSize(50);
        undertitle.setOrigin(undertitle.getGlobalBounds().getSize() / 2.f + undertitle.getLocalBounds().getPosition());
        undertitle.setPosition(rectangle_autistic.getPosition() + (rectangle_autistic.getSize() / 2.f));

        rectangle_play.setSize(sf::Vector2f(200, 100));
        rectangle_play.setFillColor(sf::Color::Transparent);
        rectangle_play.setPosition(screenWidth / float(2) - 100, 1050);
        play.setString("Play");
        play.setFont(font);
        play.setCharacterSize(100);
        play.setOrigin(play.getGlobalBounds().getSize() / 2.f + play.getLocalBounds().getPosition());
        play.setPosition(rectangle_play.getPosition() + (rectangle_play.getSize() / 2.f));


        rectangle_sett.setSize(sf::Vector2f(370, 100));
        rectangle_sett.setFillColor(sf::Color::Transparent);
        rectangle_sett.setPosition(screenWidth / float(2) - 185, 1250);
        sett.setString("Settings");
        sett.setFont(font);
        sett.setCharacterSize(100);
        sett.setOrigin(sett.getGlobalBounds().getSize() / 2.f + sett.getLocalBounds().getPosition());
        sett.setPosition(rectangle_sett.getPosition() + (rectangle_sett.getSize() / 2.f));

        rectangle_quit.setSize(sf::Vector2f(200, 100));
        rectangle_quit.setFillColor(sf::Color::Transparent);
        rectangle_quit.setPosition(screenWidth / float(2) - 100, 1450);
        quit.setString("Quit");
        quit.setFont(font);
        quit.setCharacterSize(100);
        quit.setOrigin(quit.getGlobalBounds().getSize() / 2.f + quit.getLocalBounds().getPosition());
        quit.setPosition(rectangle_quit.getPosition() + (rectangle_quit.getSize() / 2.f));
    }

private:
    sf::Font font;
};