#include <Character.h>

Character::Character(const char* src, int x, int y)
: m_x(x), m_y(y) {
  m_texture = new sf::Texture;

  if (!m_texture->loadFromFile(src)) { 
    printf("File tidak ditemukan\n");
    exit(1);
  }

  m_sprite = new sf::Sprite;
  m_sprite->setOrigin(m_texture->getSize().x / 2, m_texture->getSize().y / 2);
  m_sprite->setPosition(m_x, m_y);
  m_sprite->setTexture(*m_texture);
}

Character::~Character() {
  delete m_sprite;
  delete m_texture;
}

void Character::Move(sf::Vector2f direction) {
  m_sprite->move(direction);
}
