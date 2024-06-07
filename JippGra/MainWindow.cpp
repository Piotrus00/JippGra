#include<SFML/Graphics.hpp>
#include "Aimlab.hpp"

enum win_state
{
    winmenu,
    winsettings,
    wingame,
    winscoreboard,

};

class Window {
public:

    Window() {

        window.create(sf::VideoMode(200, 200), "AimLab.vA", sf::Style::Fullscreen);
        window.setFramerateLimit(60);

        winstate = winmenu;
        menu = new Menu(screenWidth);
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

                CRiMO(menu->rectangle_autistic, menu->undertitle, true);
                CRiMO(menu->rectangle_play, menu->play);
                CRiMO(menu->rectangle_sett, menu->sett);
                CRiMO(menu->rectangle_quit, menu->quit);

                if (isclicked(menu->rectangle_play)) {
                    game->set_new_game();

                    winstate = wingame;
                    break;
                }
                if (isclicked(menu->rectangle_sett)) {
                    winstate = winsettings;
                    break;
                }
                if (isclicked(menu->rectangle_quit)) {
                    window.close();
                }

                window.draw(menu->title);
                window.draw(menu->rectangle_autistic);
                window.draw(menu->undertitle);
                window.draw(menu->rectangle_play);
                window.draw(menu->play);
                window.draw(menu->rectangle_sett);
                window.draw(menu->sett);
                window.draw(menu->rectangle_quit);
                window.draw(menu->quit);
                break;

            case winsettings:
                CRiMO(settings->rectangle_sett_quit, settings->sett_quit);

                CRiMO(settings->rectangle_sett_skin_increase, settings->plus_skin);
                CRiMO(settings->rectangle_sett_time_increase, settings->plus_time);
                CRiMO(settings->rectangle_sett_number_of_points_increase, settings->plus_number);
                CRiMO(settings->rectangle_sett_radius_increase, settings->plus_radius);

                CRiMO(settings->rectangle_sett_skin_reduce, settings->minus_skin);
                CRiMO(settings->rectangle_sett_time_reduce, settings->minus_time);
                CRiMO(settings->rectangle_sett_number_of_points_reduce, settings->minus_number);
                CRiMO(settings->rectangle_sett_radius_reduce, settings->minus_radius);




                if (isclicked(settings->rectangle_sett_quit)) {
                    winstate = winmenu;
                    break;
                }


                window.draw(settings->sett_skin_selection);
                window.draw(settings->sett_radius_selection);
                window.draw(settings->sett_time_selection);
                window.draw(settings->sett_number_of_points_selection);

                window.draw(settings->rectangle_sett_skin_reduce);
                window.draw(settings->rectangle_sett_skin_increase);
                window.draw(settings->plus_skin);
                window.draw(settings->minus_skin);
                window.draw(settings->skin);

                window.draw(settings->rectangle_sett_time_increase);
                window.draw(settings->rectangle_sett_time_reduce);
                window.draw(settings->plus_time);
                window.draw(settings->minus_time);
                window.draw(settings->time);

                window.draw(settings->rectangle_sett_number_of_points_increase);
                window.draw(settings->rectangle_sett_number_of_points_reduce);
                window.draw(settings->plus_number);
                window.draw(settings->minus_number);
                window.draw(settings->number_circles);


                window.draw(settings->rectangle_sett_radius_increase);
                window.draw(settings->rectangle_sett_radius_reduce);
                window.draw(settings->plus_radius);
                window.draw(settings->minus_radius);
                window.draw(settings->radius);



                window.draw(settings->rectangle_sett_quit);
                window.draw(settings->sett_quit);

                if (isclicked(settings->rectangle_sett_radius_increase)) {
                    settings->inc_radius();
                }
                if (isclicked(settings->rectangle_sett_radius_reduce)) {
                    settings->dec_radius();
                }
                


                if (isclicked(settings->rectangle_sett_time_increase)) {
                    settings->inc_time();
                }
                if (isclicked(settings->rectangle_sett_time_reduce)) {
                    settings->dec_time();
                }



                if (isclicked(settings->rectangle_sett_number_of_points_increase)) {
                    settings->inc_num_circles();
                }
                if (isclicked(settings->rectangle_sett_number_of_points_reduce)) {
                    settings->dec_num_circles();
                }



                if (isclicked(settings->rectangle_sett_skin_increase)) {
                    settings->next_skin();
                }
                if (isclicked(settings->rectangle_sett_skin_reduce)) {
                    settings->prev_skin();
                }


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

                if (isclicked(game->rectangle_try_again)) {
                    game->set_new_game();
                    winstate = wingame;
                    break;
                }
                if (isclicked(game->rectangle_stats_quit)) {
                    winstate = winmenu;
                    break;
                }
                window.draw(game->end_title);

                window.draw(game->rectangle_try_again);
                window.draw(game->end_try_again);

                window.draw(game->rectangle_stats_quit);
                window.draw(game->stats_quit);
                break;

            default:
                break;
            }

            window.display();

        }
    }
private:

    unsigned int screenWidth = sf::VideoMode::getDesktopMode().width;
    unsigned int screenHeight = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow window;
    win_state winstate;
    Menu* menu;
    Game* game;
    Settings* settings;

    void csda() {
        while (window.isOpen()) {
            window.clear();
            window.draw(menu->title);
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

    bool isclicked(sf::Shape& rect) {
        return (mouse_pos(rect) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)));
    }

    void CRiMO(sf::Shape& rectangle, sf::Text& tekst, bool easteregg = false) {
        if (mouse_pos(rectangle)) {
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

};