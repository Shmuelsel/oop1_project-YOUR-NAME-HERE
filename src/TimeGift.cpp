#include "TimeGift.h"

TimeGift::TimeGift(const sf::Texture& texture, const sf::Vector2f& position)
    : Gift(texture, position)
{
}

void TimeGift::collide(Player& player) {
    setActive(false);
}