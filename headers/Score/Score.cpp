
#include <bits/stdc++.h> 

#include "Score.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

Score::Score( float xPosition, float yPosition ) { 
    this->font.loadFromFile("../assets/fonts/Roboto-Medium.ttf");
    this->xPosition = xPosition;
    this->yPosition = yPosition;
};

Score::~Score( ) { };

sf::Text Score::initScore( int count ) 
{
    sf::Text _score;
    _score.setString( std::to_string(count) );
    _score.setFont( this->font );
    _score.setCharacterSize( 20 );
    _score.setFillColor( sf::Color::White );
    _score.setLetterSpacing( 1 ); 
    _score.setString("Score: " + std::to_string(count) );
    _score.setPosition( sf::Vector2f( this->xPosition, 0 ));
    
    return _score;
}
