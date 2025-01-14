#include "Game.h"
#include <iostream>

Game::Game()
	: m_window(sf::VideoMode(800, 600), "SFML Game")
	, m_isRunning(true) 
{
	//set frame rate limit
	m_window.setFramerateLimit(60);
	loadTextures();
	initializeGame();
}

void Game::handleEvents() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_isRunning = false;
		}
	}
}

void Game::update(float deltaTime) {
	if (m_player) {
		m_player->update(deltaTime);

		// ����� �� ����� ���� ������ ����
		sf::Vector2f pos = m_player->getPosition();
		sf::Vector2u windowSize = m_window.getSize();

		pos.x = std::max(32.0f, std::min(pos.x, windowSize.x - 32.0f));
		pos.y = std::max(32.0f, std::min(pos.y, windowSize.y - 32.0f));
		//4 ����� ��� ���� �� ������ ������ �� ���� ������� ���� �� ��� ���� ������� ���� ���� ����� ����� ��� ���� ���� �� �����

		m_player->setPosition(pos);
	}

	for (auto& enemy : m_enemies) {
		enemy->update(deltaTime);
	}
}

void Game::render() {
	m_window.clear(sf::Color::Black);

	if (m_player) {
		m_player->draw(m_window);
	}

	for (const auto& enemy : m_enemies) {
		enemy->draw(m_window);
	}

	m_window.display();
}

void Game::run() {
	sf::Clock clock;
	while (m_isRunning && m_window.isOpen()) {  // ���� ����� window.isOpen
		float deltaTime = clock.restart().asSeconds();
		handleEvents();
		update(deltaTime);
		render();
	}
}

void Game::loadTextures() {
	
}

void Game::initializeGame() {
	auto it = m_textures.find("/");  // ����� ����� �-"player"
	if (it != m_textures.end()) {
		float centerX = m_window.getSize().x / 2.0f;
		float centerY = m_window.getSize().y / 2.0f;

		//create player and set its origin to the center
		m_player = std::make_unique<Player>(it->second, sf::Vector2f(centerX, centerY));

		if (m_player) {
			m_player->setOrigin();
		}
	}
	else {
		std::cout << "Failed to find player texture!\n";
	}

	createEnemies();
}

void Game::createEnemies() {
	auto it = m_textures.find("!");
	if (it != m_textures.end()) {
		// ����� 4 ������ ������ ����
		std::vector<sf::Vector2f> positions = {
			{0.f, 0.f},          // ���� �����
			{0.f, 0.f},          // ���� �����
			{0.f, 0.f},          // ���� �����
			{0.f, 0.f},          // ���� �����

			//{800.f - 32.f, 0.f},          // ���� �����
			//{0.f, 600.f - 32.f},          // ���� ����
			//{800.f - 32.f, 600.f - 32.f}           // ���� ����
		};

		for (const auto& pos : positions) {
			m_enemies.push_back(std::make_unique<Enemy>(it->second, pos));
		}
	}
}