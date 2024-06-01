#include<SFML/Graphics.hpp>
#include "Aimlab.hpp"



enum win_state
{
    winmenu,
    winsettings,
    wingame,
    winscoreboard,

};

class Menu {
public:
    unsigned int screenWidth = sf::VideoMode::getDesktopMode().width;
    unsigned int screenHeight = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow window;
    sf::Text title;
    sf::RectangleShape rectangle_autistic;
    sf::Text undertitle;
    sf::RectangleShape rectangle_play;
    sf::Text play;
    sf::RectangleShape rectangle_sett;
    sf::Text sett;
    sf::RectangleShape rectangle_quit;
    sf::Text quit;
    win_state winstate;
    Game *game;
    Settings *settings;



    Menu() {
        font.loadFromFile("OpenSans-Regular.ttf");
        window.create(sf::VideoMode(200, 200), "xd", sf::Style::Fullscreen);
        window.setFramerateLimit(60);


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

        winstate = winmenu;
        game = new Game();
        settings = new Settings();
    }

    void start() {
        while (window.isOpen())
        {

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            sf::Mouse::getPosition(window);
            switch (winstate)
            {
            case winmenu:
                CRiMO(rectangle_autistic, undertitle, true);
                CRiMO(rectangle_play, play);
                CRiMO(rectangle_sett, sett);
                CRiMO(rectangle_quit, quit);

                if (isclicked(rectangle_play)) {
                    winstate = wingame;
                    break;
                }
                if (isclicked(rectangle_sett)) {
                    winstate = winsettings;
                    break;
                }
                if (isclicked(rectangle_quit)) {
                    window.close();
                }

                window.draw(title);
                window.draw(rectangle_autistic);
                window.draw(undertitle);
                window.draw(rectangle_play);
                window.draw(play);
                window.draw(rectangle_sett);
                window.draw(sett);
                window.draw(rectangle_quit);
                window.draw(quit);
                break;
            case winsettings:
                CRiMO(settings->rectangle_sett_quit, settings->sett_quit);

                window.draw(settings->sett_skin_selection);
                window.draw(settings->sett_radius_selection);
                window.draw(settings->sett_time_selection);
                window.draw(settings->sett_number_of_points_selection);
                window.draw(settings->rectangle_sett_quit);
                window.draw(settings->sett_quit);
                break;
            case wingame:
                if (game->is_end())
                {
                    game->show_stats();
                    winstate = winscoreboard;
                    break;
                }

                if (isclicked(game->circle))
                {
                    game->rand_position();
                    game->add_point();
                }
                if (game->time_measure())
                {
                    game->rand_position();
                }
                window.draw(game->circle);

                break;
            case winscoreboard:
                CRiMO(game->rectangle_try_again, game->end_try_again);
                CRiMO(game->rectangle_stats_quit, game->stats_quit);


                window.draw(game->end_title);

                window.draw(game->rectangle_try_again);
                window.draw(game->end_try_again);

                window.draw(game->rectangle_stats_quit);
                window.draw(game->stats_quit);
            default:
                break;
            }

         window.display();

        }
    }
private:

    void csda() {
        while (window.isOpen()) {
            window.clear();
            window.draw(title);
            window.display();
        }
    }

    bool mouse_pos(sf::Shape& rectangle) {
        sf::IntRect rect(rectangle.getPosition().x, rectangle.getPosition().y, rectangle.getGlobalBounds().width, rectangle.getGlobalBounds().height);
        if (rect.contains(sf::Mouse::getPosition())) {
            return true;
        }
        return false;
    }

    void CRiMO(sf::RectangleShape& rect, sf::Text& tekst, bool easteregg = false) {
        if (mouse_pos(rect)) {
            tekst.setFillColor(sf::Color::Blue);
        }
        else
        {
            if (easteregg) {
                tekst.setFillColor(sf::Color::Transparent);
            }
            else
            {
                tekst.setFillColor(sf::Color::White);

            }
        }
    }
    bool isclicked(sf::Shape& rect) {
        return (mouse_pos(rect) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)));
    }


    sf::Font font;

};