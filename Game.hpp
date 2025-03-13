#pragma once
#include <SFML/Graphics.hpp>

class Game
{
private:
    sf::RenderWindow* window;
    sf::Event ev;
    sf::Font font;
    sf::Text menuText;

    void initWindow();

    // Textures
    sf::Texture floorTexture;
    sf::Texture layerOne;
    sf::Texture layerTwo;
    sf::Texture layerThree;
    sf::Texture logoTexture;

public:
    Game();
    virtual ~Game();

    const bool running() const;

    // Init
    void initVariables();
    void initMenuText();

    double frametime;

    // Sprites
    sf::Sprite floor;
    sf::Sprite bkgOne;
    sf::Sprite bkgTwo;
    sf::Sprite bkgThree;
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
    void renderFloor();
    void renderBackground();
    void renderPlayer();
    void renderLogo();
    void renderMenuText();

    // Menu state
    int menu; // 0 = menu, 1 = playing, 2 = end
};
