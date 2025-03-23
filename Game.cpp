#include "Game.h"
#include <iostream>

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1400, 900), "Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
    this->frametime = 1.f / 60;
}

Game::Game()
{
    this->initWindow();
    this->initVariables();
    this->initMenuText();
}

Game::~Game()
{
    delete this->window;
}

const bool Game::running() const
{
    return this->window->isOpen();
}

void Game::initVariables()
{
    this->menu = 0;

    this->moveLeft = false;
    this->moveRight = false;
    this->jump = false;

    // Load textures

    this->logoTexture.loadFromFile("C:/EldenBracelet/Images/DALL_E_2025-03-13_07.41.57_-_A_detailed_fantasy-style_logo_featuring_the_words__Elden_Bracelet__in_an_elegant__readable_medieval_font._The_text_should_have_a_glowing__magical_aura-removebg-preview.png");
    this->logo.setTexture(this->logoTexture);

    sf::Texture image;
    image.loadFromFile("C:/EldenBracelet/Images/Layers/1.png");
    backgroundTexture.push_back(image);
    image.loadFromFile("C:/EldenBracelet/Images/Layers/2.png");
    backgroundTexture.push_back(image);
    image.loadFromFile("C:/EldenBracelet/Images/Layers/3.png");
    backgroundTexture.push_back(image);
    image.loadFromFile("C:/EldenBracelet/Images/Layers/4.png");
    backgroundTexture.push_back(image);
    image.loadFromFile("C:/EldenBracelet/Images/Layers/5.png");
    backgroundTexture.push_back(image);

    sf::Sprite temp;
    float horizontal = 1400.f / 576.f;
    float vertical = 900.f / 324.f;
    for (int i = 0; i < 5; i++) {
        temp.setTexture(backgroundTexture[i]);
        temp.setScale(horizontal , vertical);
        temp.setPosition(0.f, 0.f);
        backgroundSprite.push_back(temp);
    }
}

void Game::initMenuText()
{
    this->menuText.setString("Press any key to continue");
    this->menuText.setCharacterSize(30);
    this->menuText.setFillColor(sf::Color::White);
    this->menuText.setPosition(550, 600);
}

void Game::handleEvent(sf::Event event)
{
    if (menu == 0)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            menu = 1;
        }
    }
    if (menu == 1)
    {
          
    }
}

void Game::processEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        if (this->ev.type == sf::Event::Closed)
            this->window->close();

        handleEvent(this->ev);
    }
}

void Game::update()
{
    this->processEvents();
}

void Game::render()
{
    this->window->clear();

    if (this->menu == 1) // If game is active
    {
        this->renderBackground();
    }
    else if (this->menu == 0) // If menu is active
    {
        this->renderLogo();

    }

    this->window->display();
}

void Game::renderLogo()
{
    logo.setPosition(450, 200);
    this->window->draw(logo);
}

void Game::renderPlayer()
{
    // Implement player rendering if needed
}

void Game::renderBackground()
{
    for (int i = 0; i < 5; i++) {
        window->draw(backgroundSprite[i]);
    }
}
