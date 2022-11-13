# Arkanoid
My the first game ever written :D.
![](https://media.giphy.com/media/13QyATkrHD39nebXIB/giphy.gif)

# Description
This is a simple Arkanoid game written in C++ using Framework library based on SDL2 library.
All formulas and algorithms are described in the INFO folder. Also, there are demo videos.

# Rules
1. If ball hits the brick, it(brick) will be destroyed.
2. If ball hits the paddle, it(ball) will bounce back.
3. If ball hits the bottom of the screen, the game is over - LOOSE.
4. If all bricks are destroyed, the game is over - WIN.
5. After win your score will be saved in the next game.
6. After lose your score will be reset.
7. Game restarts after pressing any key.
8. Each block has 10 points.
9. Destroying 3 blocks in a row (means that the ball was not touching the player’s platform) gives you 30 points for each block.
10. If orange block is destroyed, he "explodes" and destroys all blocks around him.

# How to build
1. Install SDL2 library
2. Install SDL2_image library
3. Clone this repository
4. Go to the root of the repository 
5. Go to the Framework folder
6. Run `cmake.` and then `make`
7. Go to the root of the repository
8. Run `cmake .` and then `make`
9. Voilà! You have the game!
