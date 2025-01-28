#pragma once
#include "Door.h"
#include "StaticObject.h"

class Door : public StaticObject {
public:
    Door(const sf::Texture& texture, const sf::Vector2f& position);

    void collide(GameObject& other) override;
    void collide(Enemy& other) override;
    void collide(Player& other)override;
    void collide(Explosion& other)override;
};

