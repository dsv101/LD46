#ifndef BUNCHOFCARROTS_HPP
#define BUNCHOFCARROTS_HPP

#include "CAGE/lib.hpp"
#include "Carrot.hpp"
#include <vector>

class BunchOfCarrots : public cage::Entity
{
  private:
    cage::Texture m_texCarrot;
    std::vector<Carrot*> m_carrots;
    bool m_isPlanted;
  public:
    BunchOfCarrots(float x = 0.0f, float y = 0.0f, unsigned int numCarrots=1, unsigned int capacity=6, bool isPlanted=false);
    virtual ~BunchOfCarrots();

    void update(float dt) override;
    void render(cage::RenderTarget &renderTarget) override;
    bool isPlanted() const;
    void setPosition(float x, float y);
    void plant(float x, float y);
    void moveX(float offsetX);
};

#endif
