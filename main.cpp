#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <Character.h>
using namespace std;

sf::Vector2f normalize(sf::Vector2f vector) {
  constexpr auto units_in_last_place = 2;
  auto norm = std::sqrt((vector.x * vector.x) + (vector.y * vector.y));
  // Prevent division by zero
  if (norm <= std::numeric_limits<float>::epsilon() * norm * units_in_last_place
    || norm < std::numeric_limits<float>::min()) {
    return sf::Vector2f{};
  }

  return vector / norm;
}


int main(int argc, char const *argv[]) {
  cout << "Hello World" << endl;
  sf::RenderWindow window(sf::VideoMode(800.0f, 600.0f), "Hello World");
  window.setFramerateLimit(60);

  sf::Vector2f direction;
  sf::Clock clock;
  float speed = 200.0f;

  Character player("assets/images/Player_Square.png", 800 / 2, 600 / 2);

  while (window.isOpen()) {
    sf::Event e;
    sf::Time time = clock.restart();
    float delta = time.asSeconds();

    while (window.pollEvent(e)) {
      if (e.type == sf::Event::Closed)
        window.close();

      direction.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) -
                    sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
      direction.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) -
                    sf::Keyboard::isKeyPressed(sf::Keyboard::Up);

      direction = normalize(direction) * speed * delta;

      if (e.type == sf::Event::KeyReleased)
        direction = sf::Vector2f(0, 0); 
    }

    player.Move(direction);
    window.clear(sf::Color::White);
    window.draw(player.GetSprite());
    window.display();
  }

  return 0;
}