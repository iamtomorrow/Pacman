# Pacman
Pacman was developed by iamtomorrow using C++, SFML library, and CMake. This project has a very basic mathematical foundation in geometry which is responsible for determining Monsters' movements inside the grid based on Pacman's x and y coordinates relative to it, but further implementation will make their movements in charge of the Laniakea neural network, a forward project developed by ourselves.

# Installing SFML (Linux Distros)
```
sudo apt-get install libsfml-dev
```

# Clone Repository
```
git clone https://github.com/iamtomorrow/Pacman/tree/iamtomorrow
```

# Setup and Run
This project was made with CMake, so to run the program on your computer you will need to create a build directory and compile the code through simpole CMake commands.
```
$ mkdir build
```
```
$ cd build
```
```
$ make Pacman
```
```
$ ./Pacman
```

# Textures
You can find all the textures used in this project in (assets/images/texture) path. A detailed explanation of the logic behind applying each texture in each shape inside the game can be found in the following images.

# Pacman Textures
![PacmanTextures](https://github.com/iamtomorrow/Pacman/assets/72582696/6fdad860-0447-471b-8772-c80af0cd784a)

# Monster Textures
![MonsterTextures](https://github.com/iamtomorrow/Pacman/assets/72582696/c300fa44-5105-4e07-bb0b-4c9f59149758)

# Cell Texture
![CellTextures](https://github.com/iamtomorrow/Pacman/assets/72582696/dcc96981-68f6-4e67-97b5-b7e85566575c)
