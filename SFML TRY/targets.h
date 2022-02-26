#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
namespace nt
{
	class Target
	{
	public:
		Target(int x, int y, float r)
		{
			m_x = x;
			m_y = y;
			m_r = r;
		}
		bool Setup()
		{
			if (!m_texture.loadFromFile("C:/Users/Super/OneDrive/Изображения/target.png"))
			{
				std::cout << "Error when loading target.png" << std::endl;
				return false;
			}
			m_target = new sf::Sprite();
			m_target->setTexture(m_texture);
			m_target->setOrigin(m_r, m_r);
			m_target->setPosition(m_x, m_y);
			m_target->setScale(0.2, 0.2);
			return true;

		}
		~Target()
		{
			if (m_target != nullptr)
				delete m_target;
		}
		sf::Sprite* Get() { return m_target; }
	private:
		int m_x, m_y;
		float m_r;
		sf::Texture m_texture;
		sf::Sprite* m_target = nullptr;
	};
}