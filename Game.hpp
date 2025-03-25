#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "player.hpp"
#include <vector>

class Game
{
private:
    sf::RenderWindow* window;
    sf::Event ev;
    sf::Font font;
    sf::Text menuText;

    void initWindow();

    // Textures

    sf::Texture logoTexture;
    std::vector <sf::Texture> backgroundTexture;
    std::vector <sf::Sprite> backgroundSprite;
public:
    Game();
    virtual ~Game();

    const bool running() const;

    // Init
    void initVariables();
    void initMenuText();

    double frametime;

    //player 
    Player player;

    // Sprites
    sf::Sprite logo;

    // Movement variables
    bool moveRight;
    bool moveLeft;
    bool jump;

    // Helper functions
    void handleEvent(sf::Event);
    void processEvents();
    void update();
    void render();
    void renderPlayer();
    void renderBackground();
    void renderLogo();

    // Menu state
    int menu; // 0 = menu, 1 = playing, 2 = end
};
