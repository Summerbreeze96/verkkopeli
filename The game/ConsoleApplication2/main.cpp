#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>


int main()
{
	//window
	sf::RenderWindow window(sf::VideoMode(1000, 700), "PONG");

	//Border top
	sf::RectangleShape borderTop(sf::Vector2f(998.f, 2.f));
	borderTop.setFillColor(sf::Color::White);
	borderTop.setPosition(sf::Vector2f(1, 1));

	//Border bottom
	sf::RectangleShape borderBottom(sf::Vector2f(998.f, 2.f));
	borderBottom.setFillColor(sf::Color::White);
	borderBottom.setPosition(sf::Vector2f(1, 697));

	//Border left
	sf::RectangleShape borderLeft(sf::Vector2f(2.f, 698.f));
	borderLeft.setFillColor(sf::Color::White);
	borderLeft.setPosition(sf::Vector2f(1, 1));

	//Border right
	sf::RectangleShape borderRight(sf::Vector2f(2.f, 698.f));
	borderRight.setFillColor(sf::Color::White);
	borderRight.setPosition(sf::Vector2f(997, 1));

	//Left Player
	sf::RectangleShape leftPlayer(sf::Vector2f(10.f, 130.f));
	leftPlayer.setFillColor(sf::Color::Magenta);
	leftPlayer.setOutlineColor(sf::Color::Blue);
	leftPlayer.setOutlineThickness(2.f);
	leftPlayer.setPosition(sf::Vector2f(20, 60));

	//Right Player
	sf::RectangleShape rightPlayer(sf::Vector2f(10.f, 130.f));
	rightPlayer.setFillColor(sf::Color::Magenta);
	rightPlayer.setOutlineColor(sf::Color::Blue);
	rightPlayer.setOutlineThickness(2.f);
	rightPlayer.setPosition(sf::Vector2f(970, 60));



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


	// Left player movement: ////////////////////////////////////////////////////////
		
		// Player movement upwards
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			leftPlayer.move(0, -0.5f);
			std::cout << "No collision" << std::endl;

			// If the player hits the wall, it stops
			if (leftPlayer.getGlobalBounds().intersects(borderTop.getGlobalBounds()))
			{
				std::cout << "Collision" << std::endl;
				leftPlayer.move(0, 0.5f);
			}
		}

		// Player movement downwards
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			leftPlayer.move(0, 0.5f);
			std::cout << "No collision" << std::endl;

			// if the player hits the wall, it stops
			if (leftPlayer.getGlobalBounds().intersects(borderBottom.getGlobalBounds()))
			{
				std::cout << "Collision" << std::endl;
				leftPlayer.move(0, -0.5f);
			}
		}

	/////////////////////////////////////////////////////////////////////////////////

	// Right player movement: ///////////////////////////////////////////////////////

		// Player movement upwards
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			rightPlayer.move(0, -0.5f);
			std::cout << "No collision" << std::endl;

			// If the player hits the wall, it stops
			if (rightPlayer.getGlobalBounds().intersects(borderTop.getGlobalBounds()))
			{
				std::cout << "Collision" << std::endl;
				rightPlayer.move(0, 0.5f);
			}
		}

		// Player movement downwards
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			rightPlayer.move(0, 0.5f);
			std::cout << "No collision" << std::endl;

			// if the player hits the wall, it stops
			if (rightPlayer.getGlobalBounds().intersects(borderBottom.getGlobalBounds()))
			{
				std::cout << "Collision" << std::endl;
				rightPlayer.move(0, -0.5f);
			}
		}

	/////////////////////////////////////////////////////////////////////////////////


		window.clear();

		window.draw(borderTop);
		window.draw(borderBottom);
		window.draw(borderLeft);
		window.draw(borderRight);
		window.draw(leftPlayer);
		window.draw(rightPlayer);

		window.display();

	}

	return 0;
}