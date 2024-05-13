#ifndef SCORE_HPP
#define SCORE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Score 
{
    public:
    // sf::RectangleShape _score;
    sf::Font font;

    Score( float xPosition, float yPosition );
    ~Score( );

    sf::Text initScore( int count );

    protected:
    std::string currentCount;
    float xPosition;
    float yPosition;
};

#endif
