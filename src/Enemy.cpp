#include "Enemy.h"
#include "Wall.h"
#include <iostream>

Enemy::Enemy(const sf::Texture& texture, const sf::Vector2f& position)
    : MoveableObject(texture, position, ENEMY_SPEED)
{
    //setOrigin();
    randomLocation();
}

//===============================================
void Enemy::update(float deltaTime, LevelManager& levelManager) {
    sf::Vector2f movement = m_currentDirection * getSpeed() * deltaTime;

    movement.x = std::round(movement.x);
    movement.y = std::round(movement.y);

    //if (getPosition().x + movement.x < 0 || getPosition().x + movement.x > Config::WINDOW_WIDTH - Config::TILE_WIDTH) {
    //    //m_currentDirection.x *= -1;  // ����� ����� �����
    //    changeDirection(deltaTime);
    //}
    //if (getPosition().y + movement.y < 0 || getPosition().y + movement.y > Config::WINDOW_HEIGHT - Config::TILE_WIDTH) {
    //    //m_currentDirection.y *= -1;  // ����� ����� ����
    //    changeDirection(deltaTime);
    //}

    tryMove(movement, levelManager);
}


//===============================================
void Enemy::changeDirection(float deltaTime) {
    const sf::Vector2f possibleDirections[] = {
                {1.0f, 0.0f},   // �����
                {-1.0f, 0.0f},  // �����
                {0.0f, 1.0f},   // ����
                {0.0f, -1.0f}   // �����
    };

    // save the current direction
    sf::Vector2f oldDirection = m_currentDirection;

    // chake if diferrent diraction
 /*   do {
        int randomIndex = rand() % 4;
        m_currentDirection = possibleDirections[randomIndex];
    } */
//while (!isValidPosition(getPosition() + (m_currentDirection * getSpeed() * deltaTime)));
}

//===============================================
void Enemy::randomLocation() {
    const sf::Vector2f possibleDirections[] = {
                {1.0f, 0.0f}, {-1.0f, 0.0f},
                {0.0f, 1.0f}, {0.0f, -1.0f}
    };
    m_currentDirection = possibleDirections[rand() % 4];
}

//===============================================
void Enemy::collide(GameObject& other) {
    other.collide(*this);
}

void Enemy::collide(Player& other)  {
    // ����� ����
}

void Enemy::collide(Enemy& other)  {
    // ������ ������ ��� ��� ����
}

void Enemy::collide(Wall& other) {
    // ����� ���� ����� ����� ����� � ����� ����
    sf::FloatRect enemyBounds = getBounds();
    sf::FloatRect wallBounds = other.getBounds();

    // �� ����� ���� ����� ���� ���� X
    if (enemyBounds.left + enemyBounds.width > wallBounds.left && enemyBounds.left < wallBounds.left + wallBounds.width) {
        if (enemyBounds.top + enemyBounds.height > wallBounds.top && enemyBounds.top < wallBounds.top + wallBounds.height) {
            // ���� �� ����� ���� ��� ������ (����, �� ��� �� ����� �� �����)
            if (enemyBounds.left < wallBounds.left) {  // ���� ���� ������ �� ����
                setPosition(sf::Vector2f(wallBounds.left - enemyBounds.width, enemyBounds.top));  // ���� �� X �-Y �- sf::Vector2f
            }
            else {  // ���� ���� ����� �� ����
                setPosition(sf::Vector2f(wallBounds.left + wallBounds.width, enemyBounds.top));  // ���� �� X �-Y �- sf::Vector2f
            }
        }
    }
}


void Enemy::collide(Rock& other)  {
    undoMove();  // ���� ����
}

void Enemy::collide(Door& other)  {
    undoMove();  // ���� ����
}

void Enemy::collide(Explosion& other)  {
    //setActive(false);  // ���� ������
}