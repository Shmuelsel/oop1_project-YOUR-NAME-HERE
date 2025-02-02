#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "StaticObject.h"
#include "LevelManager.h"

class Explosion : public StaticObject {
public:
    Explosion(const sf::Texture& texture, const sf::Vector2f& position, sf::Font font);
    void update(float deltaTime, LevelManager& levelManager) override;
    void draw(sf::RenderWindow& window) const override;

private:
    sf::Clock m_lifetimeClock;
    float m_lifetime = 1.0f; // ��� ����� �� ������
	bool m_isActive = true;
};
