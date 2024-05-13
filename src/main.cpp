
#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
#include <chrono>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "../headers/Pacman/Pacman.hpp"
#include "../headers/GridMap/GridMap.hpp"
#include "../headers/Monster/Monster.hpp"
#include "../headers/Score/Score.hpp"

const int windowWidth = 700;
const int windowHeight = 300;

int main()
{
    // creating the window and frame limit
    sf::RenderWindow Window( sf::VideoMode( windowWidth, windowHeight + 40 ), "Pacman");
    sf::Clock clock;
    Window.setFramerateLimit(30);
    
    // creating the map grid
    GridMap map(20);
    map.initGrid();
    map.distribuitePellets();
    map.getAvailablePositions();

    // creating the score
    Score score( windowWidth/2, 315.f );

    // creating a new pacman objetc
    Pacman pacman;

    // creating the monsters
    Monster monster1( sf::Color::Green, map.availablePositions[150].x, map.availablePositions[150].y);
    monster1.currentOrientation = 3;

    Monster monster2( sf::Color::Red, map.availablePositions[12].x, map.availablePositions[12].y );
    monster2.currentOrientation = 2;
    
    // creating the distance line vertex
    sf::Vertex LineDistance1[2];
    sf::Vertex LineDistance2[2];

    while ( Window.isOpen() ) 
    { 
        sf::Event eve;
        clock.restart().asSeconds();

        while ( Window.pollEvent(eve) )
        {
            if ( eve.type == sf::Event::Closed )
                Window.close();
        }

        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left )) {
            pacman.currentOrientation = 1;
            if ( !map.detectCollisions( pacman.pacmanPlayer, pacman.currentOrientation )) 
                pacman.movePacman( pacman.xOffset, 0, 1 );

            map.collectPellets( pacman.pacmanPlayer, 1 );
        }

        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right )) {
            pacman.currentOrientation = 2;
            if ( !map.detectCollisions( pacman.pacmanPlayer, pacman.currentOrientation ))
                pacman.movePacman( pacman.xOffset, 0, 2 );

            map.collectPellets( pacman.pacmanPlayer, 2 );
        }

        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up )) {
            pacman.currentOrientation = 3;
            if ( !map.detectCollisions( pacman.pacmanPlayer, pacman.currentOrientation ))
                pacman.movePacman( 0, pacman.yOffset, 3 );

            map.collectPellets( pacman.pacmanPlayer, 3 );
        }

        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down )) {
            pacman.currentOrientation = 4;
            if ( !map.detectCollisions( pacman.pacmanPlayer, pacman.currentOrientation ))
                pacman.movePacman( 0, pacman.yOffset, 4 );

            map.collectPellets( pacman.pacmanPlayer, 4 );
        }

        // Window.clear( sf::Color::Black );

        // drawing cells
        for ( int i = 0; i < map.cells.size(); i++ ) {
            Window.draw( map.cells[i] );
        }

        // drawing pellets
        for ( int i = 0; i < map.pellets.size(); i++ ) {
            Window.draw( map.pellets[i] );
        }

        monster1.calculateDistanceFromPacman( pacman.pacmanPlayer );
        monster2.calculateDistanceFromPacman( pacman.pacmanPlayer );

        /* LineDistance2[0].position = sf::Vector2f( pacman.pacmanPlayer.getPosition().x, pacman.pacmanPlayer.getPosition().y );
        LineDistance2[0].color = sf::Color::Green;
        LineDistance2[1].position = sf::Vector2f( monster2.XCoordinate, monster2.YCoordinate );
        LineDistance2[1].color = sf::Color::Green; */

        if ( !monster1.catched ) 
        {
            monster1.moveByDelta();
            if ( map.detectCollisions( monster1.player, monster1.currentOrientation ) )
                monster1.getPossibleOrientations( pacman.pacmanPlayer, monster1.currentOrientation);
            else 
                monster1.moveMonster( monster1.currentOrientation );
        } else {
            std::cout << "Game Over" << "\n";
        }

        if ( !monster2.catched ) 
        {
            monster2.moveByDelta();
            if ( map.detectCollisions( monster2.player, monster2.currentOrientation ) )
                monster2.getPossibleOrientations( pacman.pacmanPlayer, monster2.currentOrientation);
            else 
                monster2.moveMonster( monster2.currentOrientation );
        } else {
            std::cout << "Game Over" << "\n";
        }

        Window.draw( pacman.initPacman( ) );
        Window.draw( monster1.initMonster( ) );
        Window.draw( monster2.initMonster( ) );
        // Window.draw( LineDistance2, 2, sf::Lines );
        Window.draw( score.initScore( map.pelletCollected ) );

        Window.display();
    }

    return EXIT_SUCCESS;
}
