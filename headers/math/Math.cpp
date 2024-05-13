
#include "Math.hpp"

#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

Math::Math( )
{

}

Math::~Math( )
{

}

float Math::d( sf::Vector2f a1, sf::Vector2f a2 )
{
    this->_deltaX = a1.x - a2.x;
    this->_deltaY = a1.y - a2.y;
    this->_d = sqrtf( powf(this->_deltaX, 2.0) + powf(this->_deltaY, 2.0) );

    return _d;
}

float Math::d1( sf::Vector2f a1, sf::Vector2f a2, float hx ) {
    return sqrt( powf(((a1.x - hx) - a2.x ), 2.f) + powf((a1.y - a2.y), 2.f));
}

float Math::d2( sf::Vector2f a1, sf::Vector2f a2, float hx ) {
    return sqrt( powf(((a1.x + hx) - a2.x ), 2.f) + powf((a1.y - a2.y), 2.f));
}

float Math::d3( sf::Vector2f a1, sf::Vector2f a2, float hy ) {
    return sqrt( powf((a1.x - a2.x), 2.f) + powf(((a1.y - hy) - a2.y), 2.f));
}

float Math::d4( sf::Vector2f a1, sf::Vector2f a2, float hy ) {
    return sqrt( powf((a1.x - a2.x), 2.f) + powf(((a1.y + hy) - a2.y), 2.f));
}

float Math::deltaX( sf::Vector2f a1, sf::Vector2f a2 ) {
    return (a1.x - a2.x);
}

float Math::deltaY( sf::Vector2f a1, sf::Vector2f a2 ) {
    return (a1.y - a2.y);
}

float Math::angle( sf::Vector2f a1, sf::Vector2f a2 ) {
    return asin(this->_deltaY / this->_d );
}

bool Math::diff1( sf::Vector2f a1, sf::Vector2f a2, float width, float height, float radius ) 
{
    float aX = a1.x + width/2;
    float bX = a2.x - radius;

    float aYTop = a1.y - height/2;
    float aYBottom = a1.y + height/2;
    float bYTop = a2.y - radius;
    float bYBottom = a2.y + radius;

    if ( aX == bX ) {
        if ( aYTop < bYBottom && aYBottom > bYTop ) {
            return true;
        }
    }
    return false;
}

bool Math::diff2( sf::Vector2f a1, sf::Vector2f a2, float width, float height, float radius ) 
{
    float aX = a1.x - width/2;
    float bX = a2.x + radius;

    float aYTop = a1.y - height/2;
    float aYBottom = a1.y + height/2;
    float bYTop = a2.y - radius;
    float bYBottom = a2.y + radius;

    if ( aX == bX ) {
        if ( aYTop < bYBottom && aYBottom > bYTop ) {
            return true;
        }
    }
    return false;
}

bool Math::diff3( sf::Vector2f a1, sf::Vector2f a2, float width, float height, float radius ) 
{
    float aY = a1.y + height/2;
    float bY = a2.y - radius;

    float aXLeft = a1.x - width/2;
    float aXRight = a1.x + width/2;
    float bXLeft = a2.x - radius;
    float bXRight = a2.x + radius;

    if ( aY == bY ) {
        if ( aXLeft < bXRight && aXRight > bXLeft ) {
            return true;
        }
    }
    return false;
}

bool Math::diff4( sf::Vector2f a1, sf::Vector2f a2, float width, float height, float radius ) 
{
    float aY = a1.y - height/2;
    float bY = a2.y + radius;

    float aXLeft = a1.x - width/2;
    float aXRight = a1.x + width/2;
    float bXLeft = a2.x - radius;
    float bXRight = a2.x + radius;

    if ( aY == bY && aXLeft < bXRight && aXRight > bXLeft ) {
        return true;
    }
    return false;
}
