#include "Explosion.h"

Explosion::Explosion(const sf::Texture& texture, const sf::Vector2f& position, sf::Font font)
    : StaticObject(texture, position) {
}

void Explosion::update(float deltaTime, LevelManager& levelManager) {
    if (m_lifetimeClock.getElapsedTime().asSeconds() >= m_lifetime) {
		m_isActive = false;

        // ������ �� ������ ������
       // levelManager.getGameObjects().
    }
}

void Explosion::draw(sf::RenderWindow& window) const {
    if(m_isActive){
		window.draw(m_sprite);
    }
}
