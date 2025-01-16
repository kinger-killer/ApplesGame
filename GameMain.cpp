// libraries
#include <SFML/Graphics.hpp>

//constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const float INITIAL_SPEED = 100.f; // pixels per second 
const float PLAYER_SIZE = 20.f;
const float ADDITIONAL_TIME_SPEED = 10.f; // additional speed per second
const float ADDITIONAL_APPLE_SPEED = 40.f; // additional speed per apple 
const int NUM_APPLES = 11;
const int NUM_LEMONS = 5;
const int APPLE_SIZE = 10;
const int LEMON_SIZE = 10;
const int DEAD_ZONE_RADIUS = 200;//the dead zones around the lemonz to apples

int main()
{
    //random init
    int seed = (int)time(nullptr);
    srand(seed);
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");

    //player init
    float playerX = SCREEN_WIDTH / 2.0f;
    float playerY = SCREEN_HEIGHT / 2.0f;
    float playerSpeed = INITIAL_SPEED;
    int playerDirection = 0; // 0 - Right , 1 - Up , 2 - Left , 3 - Down

    sf::RectangleShape playerShape;
    playerShape.setSize(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
    playerShape.setFillColor(sf::Color::Cyan);
    playerShape.setOrigin(PLAYER_SIZE / 2.f, PLAYER_SIZE / 2.f);
    playerShape.setPosition(playerX, playerY);


    // lemonz init
    float lemonX[NUM_LEMONS];
    float lemonY[NUM_LEMONS];
    sf::CircleShape lemonsShape[NUM_LEMONS];

    for (int i = 0; i < NUM_LEMONS; ++i)
    {
        lemonX[i] = (2.5 * PLAYER_SIZE) + rand() / (float)RAND_MAX * ((SCREEN_WIDTH - (2.5f * PLAYER_SIZE)) - (2.5 * PLAYER_SIZE));
        lemonY[i] = (2.5 * PLAYER_SIZE) + rand() / (float)RAND_MAX * ((SCREEN_HEIGHT - (2.5f * PLAYER_SIZE)) - (2.5 * PLAYER_SIZE));
        lemonsShape[i].setRadius(LEMON_SIZE / 2.f);
        lemonsShape[i].setFillColor(sf::Color::Yellow);
        lemonsShape[i].setOrigin(LEMON_SIZE / 2.f, LEMON_SIZE / 2.f);
        lemonsShape[i].setPosition(lemonX[i], lemonY[i]);
    }


    // apple init
    float appleX[NUM_APPLES];
    float appleY[NUM_APPLES];
    sf::CircleShape applesShape[NUM_APPLES];

    for (int i = 0; i < NUM_APPLES; ++i)
    {
        applesShape[i].setRadius(APPLE_SIZE / 2.f);
        applesShape[i].setFillColor(sf::Color::Red);
        applesShape[i].setOrigin(APPLE_SIZE / 2.f, APPLE_SIZE / 2.f);
        bool IsTheApplesLocationCorrect = false;
        while (!IsTheApplesLocationCorrect)
        {


            appleX[i] = (2.5 * PLAYER_SIZE) + rand() / (float)RAND_MAX * ((SCREEN_WIDTH - (2.5f * PLAYER_SIZE)) - (2.5 * PLAYER_SIZE));
            appleY[i] = (2.5 * PLAYER_SIZE) + rand() / (float)RAND_MAX * ((SCREEN_HEIGHT - (2.5f * PLAYER_SIZE)) - (2.5 * PLAYER_SIZE));
            for (int l = 0; l < NUM_LEMONS; ++l)
            {
                //checking lemonz dead zone
                float squareAppleDistance = (appleX[i] - lemonX[l]) * (appleX[i] - lemonX[l]) +
                    (appleY[i] - lemonY[l]) * (appleY[i] - lemonY[l]);
                if (squareAppleDistance > DEAD_ZONE_RADIUS * DEAD_ZONE_RADIUS)
                {
                    applesShape[i].setPosition(appleX[i], appleY[i]);
                    IsTheApplesLocationCorrect = true;
                }
            }
        }
    }



    int numEatenApples = 0;

    // clock init
    sf::Clock gameClock;
    float lastTime = gameClock.getElapsedTime().asSeconds();

    while (window.isOpen())
    {
        // time colculate
        float currentTime = gameClock.getElapsedTime().asSeconds();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        playerSpeed += ADDITIONAL_TIME_SPEED * deltaTime;
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // reading input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            playerDirection = 0;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            playerDirection = 1;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            playerDirection = 2;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            playerDirection = 3;
        }

        // setting new player position
        if (playerDirection == 0)
        {
            playerX += playerSpeed * deltaTime;
        }
        else if (playerDirection == 1)
        {
            playerY -= playerSpeed * deltaTime;
        }
        else if (playerDirection == 2)
        {
            playerX -= playerSpeed * deltaTime;
        }
        else if (playerDirection == 3)
        {
            playerY += playerSpeed * deltaTime;
        }
        // checking lines
        if (playerX - PLAYER_SIZE <= 0 || playerX + PLAYER_SIZE >= SCREEN_WIDTH
            || playerY - PLAYER_SIZE <= 0 || playerY + PLAYER_SIZE >= SCREEN_HEIGHT)
        {
            // resetting game 
            for (int i = 0; i < NUM_APPLES; ++i)
            {
                appleX[i] = (2.5 * PLAYER_SIZE) + rand() / (float)RAND_MAX * ((SCREEN_WIDTH - (2.5f * PLAYER_SIZE)) - (2.5 * PLAYER_SIZE));
                appleY[i] = (2.5 * PLAYER_SIZE) + rand() / (float)RAND_MAX * ((SCREEN_HEIGHT - (2.5f * PLAYER_SIZE)) - (2.5 * PLAYER_SIZE));
                applesShape[i].setPosition(appleX[i], appleY[i]);
            }
            for (int i = 0; i < NUM_LEMONS; ++i)
            {
                lemonX[i] = (2.5 * PLAYER_SIZE) + rand() / (float)RAND_MAX * ((SCREEN_WIDTH - (2.5f * PLAYER_SIZE)) - (2.5 * PLAYER_SIZE));
                lemonY[i] = (2.5 * PLAYER_SIZE) + rand() / (float)RAND_MAX * ((SCREEN_HEIGHT - (2.5f * PLAYER_SIZE)) - (2.5 * PLAYER_SIZE));
                lemonsShape[i].setPosition(lemonX[i], lemonY[i]);
            }
            playerX = SCREEN_WIDTH / 2.0;
            playerY = SCREEN_HEIGHT / 2.0;
            playerSpeed = INITIAL_SPEED;
            playerShape.setPosition(playerX, playerY);
            lastTime = 0;
            currentTime = 0;
            gameClock.restart();
        }
        //checking apples
        for (int i = 0; i < NUM_APPLES; ++i)
        {
            float squareDistance = (playerX - appleX[i]) * (playerX - appleX[i]) +
                (playerY - appleY[i]) * (playerY - appleY[i]);

            float squareRadiusSum = (APPLE_SIZE + PLAYER_SIZE) * (APPLE_SIZE + PLAYER_SIZE) / 4;

            if (squareDistance <= squareRadiusSum)
            {
                bool IsTheApplesLocationCorrect = false;
                while (!IsTheApplesLocationCorrect)
                {
                    ++numEatenApples;
                    appleX[i] = (2.5 * PLAYER_SIZE) + rand() / (float)RAND_MAX * ((SCREEN_WIDTH - (2.5f * PLAYER_SIZE)) - (2.5 * PLAYER_SIZE));
                    appleY[i] = (2.5 * PLAYER_SIZE) + rand() / (float)RAND_MAX * ((SCREEN_HEIGHT - (2.5f * PLAYER_SIZE)) - (2.5 * PLAYER_SIZE));
                    for (int l = 0; l < NUM_LEMONS; ++l)
                    {
                        float squareAppleDistance = (appleX[i] - lemonX[l]) * (appleX[i] - lemonX[l]) +
                            (appleY[i] - lemonY[l]) * (appleY[i] - lemonY[l]);
                        if (squareAppleDistance > DEAD_ZONE_RADIUS * DEAD_ZONE_RADIUS)
                        {
                            applesShape[i].setPosition(appleX[i], appleY[i]);
                            IsTheApplesLocationCorrect = true;
                        }
                    }
                }


            }
        }
        // checking lemons
        for (int i = 0; i < NUM_LEMONS; ++i)
        {
            float squareDistance = (playerX - lemonX[i]) * (playerX - lemonX[i]) +
                (playerY - lemonY[i]) * (playerY - lemonY[i]);

            float squareRadiusSum = (LEMON_SIZE + PLAYER_SIZE) * (LEMON_SIZE + PLAYER_SIZE) / 4;

            if (squareDistance <= squareRadiusSum)
            {
                // Resetting game
                // setting lemonz position
                for (int l = 0; l < NUM_LEMONS; ++l)
                {
                    lemonX[l] = rand() / (float)RAND_MAX * SCREEN_WIDTH;
                    lemonY[l] = rand() / (float)RAND_MAX * SCREEN_HEIGHT;
                    lemonsShape[l].setPosition(lemonX[l], lemonY[l]);
                }

                //setting apples position
                for (int i = 0; i < NUM_APPLES; ++i)
                {
                    bool IsTheApplesLocationCorrect = false;
                    while (!IsTheApplesLocationCorrect)
                    {
                        ++numEatenApples;
                        appleX[i] = (2.5 * PLAYER_SIZE) + rand() / (float)RAND_MAX * ((SCREEN_WIDTH - (2.5f * PLAYER_SIZE)) - (2.5 * PLAYER_SIZE));
                        appleY[i] = (2.5 * PLAYER_SIZE) + rand() / (float)RAND_MAX * ((SCREEN_HEIGHT - (2.5f * PLAYER_SIZE)) - (2.5 * PLAYER_SIZE));
                        for (int l = 0; l < NUM_LEMONS; ++l)
                        {
                            //checking lemonz dead zone
                            float squareAppleDistance = (appleX[i] - lemonX[l]) * (appleX[i] - lemonX[l]) +
                                (appleY[i] - lemonY[l]) * (appleY[i] - lemonY[l]);
                            if (squareAppleDistance > DEAD_ZONE_RADIUS * DEAD_ZONE_RADIUS)
                            {
                                applesShape[i].setPosition(appleX[i], appleY[i]);
                                IsTheApplesLocationCorrect = true;
                            }
                        }
                    }
                }
                //setting player position & speed
                playerX = SCREEN_WIDTH / 2.0;
                playerY = SCREEN_HEIGHT / 2.0;
                playerSpeed = INITIAL_SPEED;
                playerShape.setPosition(playerX, playerY);
                //restarting the game clock
                lastTime = 0;
                currentTime = 0;
                gameClock.restart();
                break;
            }
        }
        //drawing
        window.clear();
        playerShape.setPosition(playerX, playerY);
        for (int i = 0; i < NUM_APPLES; ++i)
        {
            window.draw(applesShape[i]);
        }
        for (int i = 0; i < NUM_LEMONS; ++i)
        {
            window.draw(lemonsShape[i]);
        }
        window.draw(playerShape);
        window.display();
    }

    return 0;
}

