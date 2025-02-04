#include "Door.h"

Door::Door(const sf::Texture& texture, const sf::Vector2f& position)
    : StaticObject(texture, position)
{
}

void Door::collide(GameObject& other, float deltaTime, LevelManager& levelManager) {
    other.collide(*this, deltaTime,levelManager);  // Double dispatch
}


void Door::collide(Enemy& other, float deltaTime, LevelManager& levelManager) {
    undoMove();  // ���� �����
    // ����� ������
}

void Door::collide(Player& other, float deltaTime, LevelManager& levelManager) {
    undoMove();  // ���� ����
}

void Door::collide(Explosion& other, float deltaTime, LevelManager& levelManager) {
    undoMove();  // ���� ����
}

void Door::update(float deltaTime, LevelManager& levelManager) {

}

void Door::draw(sf::RenderWindow& window) const {
	window.draw(m_sprite);
}
