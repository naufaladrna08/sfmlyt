#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>
#include <cstdio>

class Character {
  public: 
    Character(const char* src, int x, int y);
    ~Character();

    void Move(sf::Vector2f direction);
    inline sf::Sprite GetSprite() { return *m_sprite;  }

  private:
    int m_x, m_y;
    sf::Sprite* m_sprite;
    sf::Texture* m_texture;
};

#endif