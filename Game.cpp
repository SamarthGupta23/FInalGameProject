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
    this->floorTexture.loadFromFile("C:/EldenBracelet/Images/oak_woods_tileset.png");
    this->layerOne.loadFromFile("C:/EldenBracelet/Images/background_layer_1.png");
    this->layerTwo.loadFromFile("C:/EldenBracelet/Images/background_layer_2.png");
    this->layerThree.loadFromFile("C:/EldenBracelet/Images/background_layer_3.png");
    this->logoTexture.loadFromFile("C:/EldenBracelet/Images/DALL_E_2025-03-13_07.41.57_-_A_detailed_fantasy-style_logo_featuring_the_words__Elden_Bracelet__in_an_elegant__readable_medieval_font._The_text_should_have_a_glowing__magical_aura-removebg-preview.png");

    this->floor.setTexture(this->floorTexture);
    this->bkgOne.setTexture(layerOne);
    this->bkgTwo.setTexture(layerTwo);
    this->bkgThree.setTexture(layerThree);
    this->logo.setTexture(this->logoTexture);
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
        this->renderFloor();
    }
    else if (this->menu == 0) // If menu is active
    {
        this->renderBackground();
        this->renderLogo();
        this->renderMenuText();
    }

    this->window->display();
}

void Game::renderFloor()
{
    for (int i = 0; i < 5; i++) {
        this->floor.setScale(4, 4);
        this->floor.setPosition(i * 280, 800);
        this->window->draw(this->floor);
    }
}

void Game::renderBackground()
{
    this->bkgOne.setPosition(0, 0);
    this->bkgThree.setPosition(0, 0);
    this->bkgTwo.setPosition(0, 0);
    this->bkgOne.setScale(4.375, 5);
    this->bkgTwo.setScale(4.375, 5);
    this->bkgThree.setScale(4.375, 5);
    this->window->draw(bkgOne);
    this->window->draw(bkgTwo);
    this->window->draw(bkgThree);
}

void Game::renderLogo()
{
    logo.setPosition(450, 200);
    this->window->draw(logo);
}

void Game::renderMenuText()
{
    this->window->draw(this->menuText);
}

void Game::renderPlayer()
{
    // Implement player rendering if needed
}
