FILE-MANAGEMENT-TOOL *COMPANY *: CODTECH IT SOLUTIONS

*NAME *: SHREYA KUMARI

*INTERN ID *: CT12VYO

"DOMAIN *: C++ PROGRAMING

"DURATION *: 8 WEEEKS

*MENTOR *: NEELA SANTOSH

*DESCRIOTON: 
Introduction
The Snake Game is a classic arcade game where the player controls a growing snake to eat food while avoiding collisions with the walls and itself. This implementation uses the SFML (Simple and Fast Multimedia Library) to create a graphical version of the game with smooth animations and sound effects.

Features
Smooth Gameplay: Uses SFML for rendering and handling events efficiently.

Keyboard Controls: Arrow keys control the snake's movement.

Random Food Generation: Food appears at random positions on the grid.

Increasing Difficulty: Speed increases as the snake eats more food.

Collision Detection: Ends the game if the snake hits the wall or itself.

Game Over Message: Displays a restart prompt when the game ends.

Sound Effects: Eating food and game-over sounds enhance the experience.

How It Works
Game Logic
Snake Movement: The snake moves in the chosen direction (UP, DOWN, LEFT, RIGHT).

Food Consumption: When the snake eats food, it grows longer, and the game speed increases.

Collision Detection: If the snake collides with the wall or itself, the game ends.

Game Reset: Pressing 'R' restarts the game after a game-over.

Grid System
The game screen is divided into a grid of cells, each having a size of 20x20 pixels. The window dimensions are 800x600, resulting in a grid of 40x30 cells.

Window	Cell Size	Grid Dimensions
800x600 px	20x20 px	40 columns x 30 rows
Game Speed Control
The initial speed is 150ms per move.

Every time the snake eats food, the speed decreases by 5ms, making the game progressively harder.

The minimum speed is capped at 50ms to prevent excessive difficulty.

Code Breakdown
1. Game Initialization
The SFML RenderWindow is created with dimensions 800x600.

The snake starts at the center of the grid.

A random food position is generated.

Fonts, sounds, and game-over text are loaded.

2. Handling User Input
The player controls the snake using arrow keys:

Up Arrow → Move Up

Down Arrow → Move Down

Left Arrow → Move Left

Right Arrow → Move Right

The 'R' key resets the game after a Game Over.

3. Game Update Logic
New head position is calculated based on the current direction.

If the snake collides with the walls or itself, the game ends.

If the snake eats food, it grows longer, and speed increases.

Otherwise, the snake moves forward normally.

4. Rendering Graphics
The snake is drawn as a series of green rectangles.

The food is drawn as a red square.

If the game is over, a Game Over message is displayed.

Collision Detection Mechanism
Collision Type	Condition Checked
Wall Collision	If the snake’s head moves out of bounds (x < 0, y < 0, x >= cols, y >= rows)
Self Collision	If the new head position matches any existing body segment
When a collision is detected, the game-over sound plays, and the game stops until the player presses 'R' to restart.

Use Cases
Casual Gaming: Enjoy a classic game with modern graphics.

Learning SFML: Understand event handling, rendering, and game loops.

Game Development Practice: Apply object-oriented programming to game design.

Performance Optimization: Explore real-time game mechanics and efficiency improvements.

Future Enhancements
Score System: Display the player’s score based on food collected.

Multiple Difficulty Levels: Allow the player to choose an initial speed.

Custom Skins: Add different themes and colors for the snake.

Power-Ups: Introduce special food items that provide temporary boosts.

Mobile Compatibility: Adapt controls for touchscreens.

Conclusion
This SFML-based Snake Game provides an engaging and fun experience while demonstrating key game development concepts. It features smooth movement, collision handling, sound effects, and dynamic difficulty adjustment.


#OUTPUT:![Image](https://github.com/user-attachments/assets/696e7608-86f3-4adc-9e82-5760ec0ffa94)
