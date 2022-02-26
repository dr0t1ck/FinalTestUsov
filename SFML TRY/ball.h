#pragma once
#include<iostream>;
#include<SFML/Graphics.hpp>
namespace mt
{
	const float g = 9.8;
	class Circle
	{
	public:
		Circle(int x, int y, float r, float angle, float v0)
		{
			m_x = x;
			m_y = y;
			m_r = r;
			m_angle = (360-angle)/180*acos(-1);
			m_v0 = v0;
			m_circle = new sf::CircleShape(m_r);
			m_circle->setOrigin(m_r, m_r);
			m_circle->setPosition(m_x, m_y);
			m_circle->setFillColor(sf::Color::Red);

		}
		//bool Setup()
		//{
		//	if (!m_texture.loadFromFile("C:/Users/Super/OneDrive/Изображения/ball.png"))
		//	{
		//		std::cout << "Error when loading ball.png" << std::endl;
		//		return false;
		//	}
		//	m_circle = new sf::Sprite();
		//	m_circle->setTexture(m_texture);
		//	m_circle->setOrigin(m_r, m_r);
		//	m_circle->setPosition(m_x, m_y);
		//	return true;
	//	}
		~Circle()
		{
			delete m_circle;
		}
		void Move(float t)
		{
			float sx = m_x + m_v0 * cos(m_angle) * t;
			float sy = m_y + m_v0 * sin(m_angle) * t + g * t * t / 2;
			m_circle->setPosition(sx, sy);
		}
		//sf::Sprite* Get() { return m_circle; }
		//int GetX() { return m_x }
		//int GetY() { return m_y }
		sf::CircleShape* Get() { return m_circle; }

	private:
		int m_x, m_y;
		float m_r;
		float m_angle;
		float m_v0;
		sf::CircleShape* m_circle;
	};
}