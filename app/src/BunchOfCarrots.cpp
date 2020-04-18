#include "BunchOfCarrots.hpp"
#include "app.hpp"

BunchOfCarrots::BunchOfCarrots(float x, float y, unsigned int numCarrots, unsigned int capacity, bool isPlanted) :
  m_texCarrot(),
  m_carrots(capacity),
  m_isPlanted(isPlanted),
  cage::Entity(x, y, nullptr)
{
  m_texCarrot.loadFromFile(CARROT_PNG);
  for (int i = 0; i < numCarrots; ++i)
  {
    m_carrots.push_back(new Carrot(m_texCarrot, x, y));
  }
}

BunchOfCarrots::~BunchOfCarrots()
{
  for (Carrot *c : m_carrots)
  {
    delete c;
  }
  m_carrots.clear();
}

void BunchOfCarrots::update(float dt)
{
  cage::Entity::update(dt);

  for (Carrot *c : m_carrots)
  {
    if (c != nullptr)
    {
      cage::Vector2f pos = m_transformable.getPosition();
      c->setPosition(pos.x, pos.y);
    }
  }
}

void BunchOfCarrots::render(cage::RenderTarget &renderTarget)
{
  for (Carrot *c : m_carrots)
  {
    if (c != nullptr)
    {
      c->render(renderTarget);
    }
  }
}

bool BunchOfCarrots::isPlanted() const
{
  return m_isPlanted;
}

void BunchOfCarrots::setPosition(float x, float y)
{
  m_transformable.setPosition(x, y);
}

void BunchOfCarrots::plant(float x, float y)
{
  setPosition(x, y);
  m_isPlanted = true;
}
