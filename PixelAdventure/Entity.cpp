#include "Entity.h"
Entity::Entity() {
	shape.setSize(sf::Vector2f(50.f, 50.f));
	shape.setFillColor(sf::Color::Red);
	movementSpeed = 100.f;
}

Entity::~Entity() {

}

void Entity::move(const float& dt, const float x, const float y)
{
	shape.move(x*movementSpeed*dt,y*movementSpeed*dt);
}

void Entity::update(const float& dt)
{
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(shape);
}
