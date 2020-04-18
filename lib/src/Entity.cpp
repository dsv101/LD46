#include "CAGE/Entity.hpp"

cage::Entity::Entity(float x, float y, Drawable *drawable) :
  m_transformable(),
  m_drawable(drawable)
{
  m_transformable.setPosition(x, y);
}

cage::Entity::~Entity()
{

}

void cage::Entity::update(float dt)
{

}

void cage::Entity::render(RenderTarget &renderTarget)
{
  if (m_drawable != nullptr)
  {
    renderTarget.draw(*m_drawable, m_transformable.getTransform());
  }
}
