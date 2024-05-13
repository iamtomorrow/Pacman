
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Pacman.hpp"

const int windowWidth = 700;
const int windowHeight = 300;

Pacman::Pacman( ) 
{
    this->pacmanPlayer.setRadius( this->radius );
    this->pacmanPlayer.setFillColor( sf::Color::Yellow );
    this->pacmanPlayer.setOrigin( sf::Vector2f( this->radius, this->radius ));
    this->pacmanPlayer.setPosition( sf::Vector2f(windowWidth/2, windowHeight/2) ); 

    this->xOffset = 2.f;
    this->yOffset = 2.f;

    // setting textures
    this->LeftTexture.loadFromFile("../assets/images/textures/Pacman/left.png");
    this->RightTexture.loadFromFile("../assets/images/textures/Pacman/right.png");
    this->UpTexture.loadFromFile("../assets/images/textures/Pacman/up.png");
    this->DownTexture.loadFromFile("../assets/images/textures/Pacman/down.png");
}

Pacman::~Pacman( ) { }

sf::CircleShape Pacman::initPacman( ) 
{
    return this->pacmanPlayer;
}

void Pacman::movePacman( float x, float y, int orientation ) 
{
    switch ( orientation )
    {
        case 1:
            // this->pacmanPlayer.getPosition().x - radius > 0 ? 
            this->pacmanPlayer.setTexture( &this->LeftTexture );
            this->pacmanPlayer.move( sf::Vector2f(-x, 0) );
            // : this->pacmanPlayer.move( sf::Vector2f(x, 0) );
            break;
        case 2:
            // this->pacmanPlayer.getPosition().x + radius < windowWidth ? 
            this->pacmanPlayer.setTexture( &this->RightTexture );
            this->pacmanPlayer.move( sf::Vector2f(+x, 0) ) ;
            // : this->pacmanPlayer.move( sf::Vector2f(-x, 0) );
            break;
        case 3:
            // this->pacmanPlayer.getPosition().y - radius > 0 ?
            this->pacmanPlayer.setTexture( &this->UpTexture );
            this->pacmanPlayer.move( sf::Vector2f(0, -y) );
            // : this->pacmanPlayer.move( sf::Vector2f(0, y) );
            break;
        case 4:
            // this->pacmanPlayer.getPosition().y + radius < windowHeight ?
            this->pacmanPlayer.setTexture( &this->DownTexture );
            this->pacmanPlayer.move( sf::Vector2f(0, +y) );
            // : this->pacmanPlayer.move( sf::Vector2f(0, -y) );
            break;
        default:
            std::cerr << "ERROR ENTRY" << "\n";
            break;
    }
}
