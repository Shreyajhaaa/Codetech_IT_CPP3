#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

const int cellSize = 20;
const int width = 800;
const int height = 600;
const int cols = width / cellSize;
const int rows = height / cellSize;

enum Direction { UP, DOWN, LEFT, RIGHT };

struct SnakeSegment {
    int x, y;
};

class SnakeGame {
private:
    sf::RenderWindow window;
    std::vector<SnakeSegment> snake;
    Direction direction;
    bool gameOver;
    sf::Vector2i food;
    sf::Font font;
    sf::Text gameOverText;
    sf::SoundBuffer eatBuffer, gameOverBuffer;
    sf::Sound eatSound, gameOverSound;
    int speed;

public:
    SnakeGame() : window(sf::VideoMode(width, height), "Snake Game"), direction(RIGHT), gameOver(false), speed(150) {
        srand(time(0));
        snake.push_back({cols / 2, rows / 2});
        spawnFood();
        
        font.loadFromFile("arial.ttf");
        gameOverText.setFont(font);
        gameOverText.setString("Game Over! Press R to Restart");
        gameOverText.setCharacterSize(30);
        gameOverText.setFillColor(sf::Color::Red);
        gameOverText.setPosition(width / 4, height / 3);
        
        eatBuffer.loadFromFile("eat.wav");
        gameOverBuffer.loadFromFile("gameover.wav");
        eatSound.setBuffer(eatBuffer);
        gameOverSound.setBuffer(gameOverBuffer);
    }

    void spawnFood() {
        food.x = rand() % cols;
        food.y = rand() % rows;
    }

    void handleInput() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction != DOWN) direction = UP;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction != UP) direction = DOWN;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction != RIGHT) direction = LEFT;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction != LEFT) direction = RIGHT;
    }

    void update() {
        if (gameOver) return;

        SnakeSegment newHead = snake.front();
        if (direction == UP) newHead.y--;
        else if (direction == DOWN) newHead.y++;
        else if (direction == LEFT) newHead.x--;
        else if (direction == RIGHT) newHead.x++;

        if (newHead.x < 0 || newHead.y < 0 || newHead.x >= cols || newHead.y >= rows) {
            gameOver = true;
            gameOverSound.play();
            return;
        }

        for (auto &segment : snake) {
            if (segment.x == newHead.x && segment.y == newHead.y) {
                gameOver = true;
                gameOverSound.play();
                return;
            }
        }

        snake.insert(snake.begin(), newHead);
        if (newHead.x == food.x && newHead.y == food.y) {
            eatSound.play();
            spawnFood();
            speed = std::max(50, speed - 5);
        } else {
            snake.pop_back();
        }
    }

    void render() {
        window.clear();

        sf::RectangleShape segmentShape(sf::Vector2f(cellSize, cellSize));
        segmentShape.setFillColor(sf::Color::Green);
        for (auto &segment : snake) {
            segmentShape.setPosition(segment.x * cellSize, segment.y * cellSize);
            window.draw(segmentShape);
        }

        sf::RectangleShape foodShape(sf::Vector2f(cellSize, cellSize));
        foodShape.setFillColor(sf::Color::Red);
        foodShape.setPosition(food.x * cellSize, food.y * cellSize);
        window.draw(foodShape);

        if (gameOver) {
            window.draw(gameOverText);
        }

        window.display();
    }

    void run() {
        sf::Clock clock;
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                    resetGame();
                }
            }

            handleInput();
            if (clock.getElapsedTime().asMilliseconds() > speed) {
                update();
                clock.restart();
            }
            render();
        }
    }

    void resetGame() {
        snake.clear();
        snake.push_back({cols / 2, rows / 2});
        direction = RIGHT;
        gameOver = false;
        spawnFood();
        speed = 150;
    }
};

int main() {
    SnakeGame game;
    game.run();
    return 0;
}