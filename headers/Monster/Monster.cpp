
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Monster.hpp"
#include "../math/Math.hpp"

Monster::Monster( sf::Color monsterColor, float xPosition, float yPosition, float x, float y )
{
    this->monsterColor = monsterColor;
    this->xPosition = xPosition;
    this->yPosition = yPosition;
    this->x = x;
    this->y = y;

    this->player.setRadius( this->monsterRadius );
    this->player.setPosition( sf::Vector2f( this->xPosition, this->yPosition ) );
    this->player.setOrigin( sf::Vector2f( this->monsterRadius, this->monsterRadius ));
    this->player.setFillColor( this->monsterColor );

    if ( this->RedTexture.loadFromFile("../assets/images/textures/Monster/red.jpg") &&
        this->GreenTexture.loadFromFile("../assets/images/textures/Monster/green.jpg") && 
        this->BlueTexture.loadFromFile("../assets/images/textures/Monster/blue.jpg") &&
        this->VioletTexture.loadFromFile("../assets/images/textures/Monster/violet.jpg") )
    {
        if ( monsterColor == sf::Color::Red ) {
            this->player.setTexture( &this->RedTexture );
        } else if ( monsterColor == sf::Color::Green ) {
            this->player.setTexture( &this->GreenTexture );
        } else if ( monsterColor == sf::Color::Blue ) {
            this->player.setTexture( &this->BlueTexture );
        } else if ( monsterColor == sf::Color(127, 0, 255 )) {
            this->player.setTexture( &this->VioletTexture );
        } else {
            std::cerr << "INVALID COLOR" << "\n";
        }
    } else {
        std::cerr << "ERROR LOADING TEXTURES" << "\n";
    }
 
    this->catched = false;
}

Monster::~Monster( ) { }

sf::CircleShape Monster::initMonster()
{
    return this->player;
}

void Monster::calculateDistanceFromPacman( sf::CircleShape pacman )
{
    sf::Vector2f a1 = sf::Vector2f( this->player.getPosition().x, this->player.getPosition().y);
    sf::Vector2f a2 = sf::Vector2f( pacman.getPosition().x, pacman.getPosition().y );

    this->XCoordinate = a1.x;
    this->YCoordinate = a1.y;

    this->deltaX = math.deltaX( a1, a2 );
    this->deltaY = math.deltaY( a1, a2 );

    this->distance = math.d( a1, a2 );


    if ( distance < 2.f ) this->catched = true;
    else this->catched = false;
}

void Monster::moveMonster( int orientation )
{
    switch ( orientation )
    {
        case 1:
            this->player.move( sf::Vector2f( -x, 0 ));
            break;
        case 2:
            this->player.move( sf::Vector2f( +x, 0 ));
            break;
        case 3:
            this->player.move( sf::Vector2f( 0, -y ));
            break;
        case 4:
            std::cout << "Executing" << "\n";
            this->player.move( sf::Vector2f( 0, +y ));
            break;
        default:
            std::cerr << "ERROR ENTRY: " << orientation << "\n";
            break;
    }
}

void Monster::getPossibleOrientations( sf::CircleShape pacman, int orientation )
{
    std::cout << "This orientation >> " << orientation << "\n";

    sf::Vector2f a1 = sf::Vector2f( this->player.getPosition().x, this->player.getPosition().y);
    sf::Vector2f a2 = sf::Vector2f( pacman.getPosition().x, pacman.getPosition().y );

    float d1 = this->math.d1( a1, a2 );
    float d2 = this->math.d2( a1, a2 );
    float d3 = this->math.d3( a1, a2 );
    float d4 = this->math.d4( a1, a2 );

    dS.push_back(d1);
    dS.push_back(d2); 
    dS.push_back(d3);
    dS.push_back(d4);

    minD = *std::min_element(dS.begin(), dS.end());

    if ( d1 == d2 && d3 == d4 ) {
        this->currentOrientation = 4;
    } else {
        switch ( orientation ) 
        {
            case 1:
            if ( minD != d1 ) {
                auto value = std::find( dS.begin(), dS.end(), minD );
                currentOrientation = value - dS.begin() + 1;
                this->moveMonster( currentOrientation );
            } else {
                dS.erase( dS.begin() );
                float minD2 = *std::min_element(dS.begin(), dS.end());

                if ( minD2 == d2 ) {
                    this->currentOrientation = 2;
                    this->moveMonster( currentOrientation );
                }
                else if ( minD2 == d3 ) {
                    this->currentOrientation = 3;
                    this->moveMonster( currentOrientation );
                }
                else {
                    this->currentOrientation = 4;
                    this->moveMonster( currentOrientation );
                }
            }
            break;

            case 2:
            if ( minD != d2 ) {
                auto value = std::find( dS.begin(), dS.end(), minD );
                currentOrientation = value - dS.begin() + 1;
                std::cout << "Result: " << currentOrientation << "\n";
                this->moveMonster( currentOrientation );
            } else {
                dS.erase( dS.begin() + 1 );
                float minD2 = *std::min_element(dS.begin(), dS.end());
                
                if ( minD2 == d1 ) {
                    this->currentOrientation = 1;
                    this->moveMonster( currentOrientation );
                }
                else if ( minD2 == d3 ) {
                    currentOrientation = 3;
                    this->moveMonster( currentOrientation );                
                }
                else {
                    this->currentOrientation = 4;
                    this->moveMonster( currentOrientation );
                }
            }
            break;
            
            case 3:
            if ( minD != d3 ) {
                auto value = std::find( dS.begin(), dS.end(), minD );
                currentOrientation = value - dS.begin() + 1;
                std::cout << "Go to: " << currentOrientation << "\n";
                this->moveMonster( currentOrientation );
            } else {
                dS.erase( dS.begin() + 2 );
                float minD2 = *std::min_element(dS.begin(), dS.end());
                auto value = std::find( dS.begin(), dS.end(), minD2 );

                if ( minD2 == d1 ) {
                    this->currentOrientation = 1;
                    this->moveMonster( currentOrientation );
                }   
                else if ( minD2 == d2 ) {
                    this->currentOrientation = 2;
                    this->moveMonster( currentOrientation );
                }
                else if ( minD2 == d4 ) {
                    this->currentOrientation = 4;
                    this->moveMonster( currentOrientation );
                }                
            }            
            break;
            
            case 4:
            if ( minD != d4 ) {
                auto value = std::find( dS.begin(), dS.end(), minD );
                this->currentOrientation = value - dS.begin() + 1;
                this->moveMonster( currentOrientation );
            } else {
                dS.erase( dS.begin() + 3 );
                float minD2 = *std::min_element(dS.begin(), dS.end());

                if ( minD2 == d1 ) {
                    this->currentOrientation = 1;
                    this->moveMonster(1);
                }
                else if ( minD2 == d2 ) {
                    this->currentOrientation = 2;
                    this->moveMonster( currentOrientation );
                }
                else if ( minD2 == d3 ) {
                    this->currentOrientation = 3;
                    this->moveMonster( currentOrientation );
                }
            }
            break;

            default:
            break;
        }
    }
    dS.clear();
}

void Monster::moveByDelta( ) 
{
    if ( this->deltaX == 0 && this->deltaY < 0 ) this->currentOrientation = 4;
    else if ( this->deltaX == 0 && this->deltaY > 0 ) this->currentOrientation = 3;

    if ( this->deltaY == 0 && this->deltaX < 0 ) this->currentOrientation = 2;
    else if ( this->deltaY == 0 && this->deltaX > 0) this->currentOrientation = 1;
}

void Monster::moveByAngle( ) 
{
    
}

void Monster::moveRandom( ) 
{
    auto ranDev = std::random_device { };
    auto defEng = std::default_random_engine { ranDev() };
    std::shuffle( std::begin(this->orientations), std::end(this->orientations), defEng );

    this->currentOrientation = orientations[0];
    std::cout << orientations[0] << "\n";
}
