#ifndef PACMAN_HPP
#define PACMAN_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Pacman {
    public:
    sf::CircleShape pacmanPlayer;
    float positionX;
    float positionY;
    int currentOrientation;
    float xOffset;
    float yOffset;

    Pacman( );
    ~Pacman( );

    sf::CircleShape initPacman( );
    void movePacman( float x, float y, int orientation );

    protected:
    const float radius = 10.f;

    sf::Texture LeftTexture;
    sf::Texture RightTexture;
    sf::Texture UpTexture;
    sf::Texture DownTexture;
};

#endif
