#include "Player.h"
#include <iostream>
#include "Config.h"

Player::Player(const sf::Texture& texture, const sf::Vector2f& position)
    : MoveableObject(texture, position, Config::PLAYER_SPEED)
    , m_moveSpeed(Config::PLAYER_SPEED), m_direction(0.0f, 0.0f)
{
    //setOrigin();
}

void Player::update(float deltaTime, LevelManager& levelManager){

    m_direction = sf::Vector2f(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        m_direction.x = -1.0f;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        m_direction.x = 1.0f;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        m_direction.y = -1.0f;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        m_direction.y = 1.0f;


    sf::Vector2f movement = m_direction * m_moveSpeed * deltaTime;

    //set the move to int
    movement.x = std::round(movement.x);
    movement.y = std::round(movement.y);

    tryMove(movement, levelManager);
}


void Player::collide(GameObject& other)  {
    other.collide(*this);  // Double dispatch
}


void Player::collide(Enemy& other)  {

    undoMove();  // ���� �����
    // ����� ������
}

void Player::collide(Wall& other)  {
    undoMove(); 
    std::cout << "collision" << std::endl;// ���� ����
}

void Player::collide(Rock& other)  {
    undoMove();  // ���� ����
}

void Player::collide(Door& other)  {
    undoMove();  // ���� ����
}

void Player::collide(Explosion& other)  {
    // ����� ������ ������
}

void Player::collide(Player& other) {
   
}