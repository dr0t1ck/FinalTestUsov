#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include "ball.h"


	using namespace std::chrono_literals;
	int main()
	{
		float t = 0;
		sf::RenderWindow window(sf::VideoMode(800, 600), L"Полёт мячика!");
		mt::Circle circle(20, 500, 20, 75, 75);
		while (window.isOpen())
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				while (sf::Mouse::isButtonPressed(sf::Mouse::Left));
				std::cout << " PRESS !!!" << std::endl;
			}
			circle.Move(t);
		window.clear();
		window.draw(*circle.Get());
		window.display();
		std::this_thread::sleep_for(40ms);
		t + -0.04;
	




	}

