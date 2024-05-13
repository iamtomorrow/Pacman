
#include <iostream>

#include "GridMap.hpp"
#include "../math/Math.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

const int windowWidth = 700;
const int windowHeight = 300;

GridMap::GridMap( int size )
{
    this->pelletCollected = 0;
    this->size = size;
    this->xDimension = windowWidth / size;
    this->yDimension = windowHeight / size;
    this->grid.resize( xDimension );
}

GridMap::~GridMap( ) { }

void GridMap::initGrid( )
{

    if ( this->TextureLeft.loadFromFile("../assets/images/textures/cells/1.png") &&
        this->TextureRight.loadFromFile("../assets/images/textures/cells/2.png") &&
        this->TextureTop.loadFromFile("../assets/images/textures/cells/3.png") &&
        this->TextureDown.loadFromFile("../assets/images/textures/cells/4.png") &&
        this->TextureRightDown.loadFromFile("../assets/images/textures/cells/6.png") &&
        this->TextureLeftDown.loadFromFile("../assets/images/textures/cells/7.png") &&
        this->TextureRightTop.loadFromFile("../assets/images/textures/cells/8.png") &&
        this->TextureLeftTop.loadFromFile("../assets/images/textures/cells/9.png") &&
        this->TextureLeftTopCorner.loadFromFile("../assets/images/textures/cells/-1.png") &&
        this->TextureRightTopCorner.loadFromFile("../assets/images/textures/cells/-2.png") &&
        this->TextureLeftBottomCorner.loadFromFile("../assets/images/textures/cells/-3.png") &&
        this->TextureRightBottomCorner.loadFromFile("../assets/images/textures/cells/-4.png") ) {
        for ( int i = 0; i < xDimension; i++ ) {
            for ( int j = 0; j < yDimension; j++ ) {
                sf::RectangleShape Cell;
                Cell.setSize( sf::Vector2f( size, size) );
                Cell.setOrigin( sf::Vector2f( size/2.f, size/2.f ) );
                Cell.setPosition( sf::Vector2f( i*size + size/2, j*size + size/2 ) );

                if ( this->gridArray[j][i] == -1) {
                    Cell.setFillColor( sf::Color::Blue ); 
                    Cell.setTexture( &TextureLeftTopCorner );
                }
                else if ( this->gridArray[j][i] == -2) {
                    Cell.setTexture( &TextureRightTopCorner );
                }
                else if ( this->gridArray[j][i] == -3 ) {
                    Cell.setTexture( &TextureLeftBottomCorner );
                }
                else if ( this->gridArray[j][i] == -4 ) {
                    Cell.setTexture( &TextureRightBottomCorner );
                }
                else if ( this->gridArray[j][i] == 0 ) {  
                    Cell.setFillColor( ColorAvailable );
                }
                else if (this->gridArray[j][i] == 1) {
                    Cell.setFillColor( ColorLeft );
                    Cell.setTexture( &TextureLeft );
                }
                else if ( this->gridArray[j][i] == 2 ) {
                    Cell.setFillColor( ColorRight );
                    Cell.setTexture( &TextureRight );
                }
                else if ( this->gridArray[j][i] == 3 ) {
                    Cell.setFillColor( ColorTop );
                    Cell.setTexture( &TextureTop );
                }
                else if ( this->gridArray[j][i] == 4 ) {
                    Cell.setFillColor( ColorDown );
                    Cell.setTexture( &TextureDown );
                }
                else if ( this->gridArray[j][i] == 5 ) {
                    Cell.setFillColor( sf::Color::Black );
                    // Cell.setOutlineThickness( 1.f );
                    // Cell.setOutlineColor( sf::Color::Blue );
                }
                else if ( this->gridArray[j][i] == 6 ) {
                    Cell.setFillColor( ColorRightDown );
                    Cell.setTexture( &TextureRightDown );
                }
                else if ( this->gridArray[j][i] == 7 ) {
                    Cell.setFillColor( ColorLeftDown );
                    Cell.setTexture( &TextureLeftDown );
                }
                else if ( this->gridArray[j][i] == 8 ) {
                    Cell.setFillColor( ColorRightTop );
                    Cell.setTexture( &TextureRightTop );
                }
                else if ( this->gridArray[j][i] == 9 ) {
                    Cell.setFillColor( ColorLeftTop );
                    Cell.setTexture( &TextureLeftTop );
                }

                this->cells.push_back(Cell);
            }
        }
    }
}

void GridMap::applyTexture( ) {

}

void GridMap::distribuitePellets( )
{
    for ( int i = 0; i < xDimension; i++ ) {
        for ( int j = 0; j < yDimension; j++ ) {
            if (this->gridArray[j][i] == 0) {
                sf::CircleShape Pellet;
                Pellet.setRadius( this->pelletRadius );
                Pellet.setFillColor( sf::Color::Yellow );
                Pellet.setOrigin( sf::Vector2f( this->pelletRadius/2, this->pelletRadius/2 ) );
                Pellet.setPosition( i*size + size/2, j*size + size/2 );

                this->pellets.push_back(Pellet);
            }
        }
    }
}

void GridMap::collectPellets( sf::CircleShape object, int orientation )
{
sf::CircleShape DarkPellet;
    DarkPellet.setRadius(2.f);
    DarkPellet.setFillColor( sf::Color::Blue);

    for ( int i = 0; i < pellets.size(); i++ ) {
        sf::CircleShape pellet = pellets[i];

        switch ( orientation )
        {
            case 1:
            if ( object.getPosition().x - 10.f == pellet.getPosition().x )
                if ( object.getPosition().y - pellet.getPosition().y == 0 && pellet.getPosition().y - object.getPosition().y == 0 ) {
                    this->pellets[i] = DarkPellet;
                    this->pelletCollected += 1;
                }
            break;

            case 2:
            if ( object.getPosition().x + 10.f == pellet.getPosition().x )
                if ( object.getPosition().y - pellet.getPosition().y == 0 && pellet.getPosition().y - object.getPosition().y == 0 ) {
                    this->pellets[i] = DarkPellet;
                    this->pelletCollected +=1 ;
                }
            break;

            case 3:
            if ( object.getPosition().y - 10.f == pellet.getPosition().y )
                if ( object.getPosition().x - pellet.getPosition().x == 0 && pellet.getPosition().x - object.getPosition().x == 0 ) {
                    this->pellets[i] = DarkPellet;
                    this->pelletCollected +=1 ;        
                }
            break;

            case 4:
            if ( object.getPosition().y + 10.f == pellet.getPosition().y )
                if ( object.getPosition().x - pellet.getPosition().x == 0 && pellet.getPosition().x - object.getPosition().x == 0 ) {
                    this->pellets[i] = DarkPellet;
                    this->pelletCollected += 1;
                }
            break;

            default:
            break;
        }
    }
}

bool GridMap::detectCollisions( sf::CircleShape object, int orientation )
{
    for ( int i = 0; i < this->cells.size(); i++ ) {
        sf::RectangleShape cell = cells[i];

        switch ( orientation )
        {
            // detect collision while moving to the left
            case 1:
            if ( cell.getFillColor() == ColorRight || cell.getFillColor() == ColorRightDown || cell.getFillColor() == ColorRightTop ) 
            {
                if ( cell.getPosition().x + size/2 == object.getPosition().x - 10.f ) 
                {
                    if ( cell.getPosition().y - size/2 < object.getPosition().y + 10.f && cell.getPosition().y + size/2 > object.getPosition().y - 10.f )
                    {
                        return true;
                    }
                }
            }
            break;

            // detect collision while moving to the right
            case 2:
            if ( cell.getFillColor() == ColorLeft || cell.getFillColor() == ColorLeftDown || cell.getFillColor() == ColorLeftTop ) 
            {
                if ( cell.getPosition().x - size/2 == object.getPosition().x + 10.f ) 
                {
                    if ( cell.getPosition().y - size/2 < object.getPosition().y + 10.f && cell.getPosition().y + size/2 > object.getPosition().y - 10.f )
                    {
                        std::cout << "Lets go" << "\n";
                        return true;
                    }
                }
            }
            break;

            // detect collision while moving up
            case 3:
            if ( cell.getFillColor() == ColorDown || cell.getFillColor() == ColorRightDown || cell.getFillColor() == ColorLeftDown ) 
            {
                if ( cell.getPosition().y + size/2 == object.getPosition().y - 10.f ) 
                {
                    if ( cell.getPosition().x - size/2 < object.getPosition().x + 10.f && cell.getPosition().x + size/2 > object.getPosition().x - 10.f )
                    {
                        return true;
                    }
                }
            }
            break;

            // detect collision while moving up
            case 4:
            if ( cell.getFillColor() == ColorTop || cell.getFillColor() == ColorRightTop || cell.getFillColor() == ColorLeftTop ) 
            {
                if ( cell.getPosition().y - size/2 == object.getPosition().y + 10.f )
                {
                    if ( cell.getPosition().x - size/2 < object.getPosition().x + 10.f && cell.getPosition().x + size/2 > object.getPosition().x - 10.f )
                    {
                        std::cout << "... ..." << "\n";
                        return true;
                    }
                }
            }
            break;

            default:
            return false;
            break;
        }
    }
    return false;
}

void GridMap::repulseObject( sf::CircleShape object, int orientation ) 
{
    switch ( orientation )
    {
        case 1:
            object.move( sf::Vector2f( +1.f, 0 ));
            break;
        case 2:
            object.move( sf::Vector2f( -1.f, 0 ));
            break;
        case 3:
            object.move( sf::Vector2f( 0, +1.f ));
            break;
        case 4:
            object.move( sf::Vector2f( 0, -1.f ));
            break;
        default:
            std::cerr << "ERROR ENTRY" << "\n";
            break;
    }
}

void GridMap::getAvailablePositions( ) 
{
    // int n = 0;
    int p = 0;
    // std::cout << this->cells.size() << "\n";

    /* for ( int i = 0; i < gridArray.size(); i++ ) {
        for ( const int& j : gridArray[i]) {
            if ( j == 0 ) n++;
        }
    } */

    // std::cout << n << "\n";
    // this->availablePositions.resize( n );

    for ( const sf::RectangleShape& i : cells ) {
        if ( i.getFillColor() == ColorAvailable ) {
            p++;
            this->availablePositions.resize(p);
            // std::cout << ": " << i.getPosition().x << " - " << i.getPosition().y << "\n";
            this->availablePositions.push_back( sf::Vector2f( i.getPosition().x, i.getPosition().y ));
        }
    }
}
