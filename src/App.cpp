#include "App.h"
#include "MazeBuilder.h"
#include "DFSGenerator.h"
#include "KruskalGenerator.h"
#include "AStarFinder.h"
#include "BFSFinder.h"
#include <iostream>

App::App()
	: maze(nullptr)
	, generator(nullptr)
	, finder(nullptr)
	, width(0)
	, height(0) {
} ;

void App::run() {
	std::cout << "MazeGenerator: Генератор лабиринтов и поиск пути" << std::endl;
	
	while (true) {
		int cmd;

		showMenu();
		std::cin >> cmd;

		if (cmd == 0) {
			break;
		}
		handleCommand(cmd);
	}
}

void App::showMenu() {
	std::cout << "Выберите один из доступных пунктов в меню:\n"
			  << "1. Установить размер лабиринта\n"
			  << "2. Выбрать алгоритм генерации лабиринта\n"
			  << "3. Выбрать алгоритм поиска пути\n"
		      << "4. Установить начальную и конечную точки\n"
		      << "5. Сгенерировать лабиринт\n"
			  << "6. Показать лабиринт\n"
		      << "Выберите один из вышеупомянутых пунктов (для выхода введите '0'): ";
}

void App::handleCommand(int choice) {
	switch (choice) {
		case 1: setMazeSize(); break;
		case 2: setGenerator(); break;
		case 3: setFinder(); break;
		case 4: break;
		case 5: generate(); break;
		case 6: display(); break;
		default: std::cout << "Неизвестная команда: проверьте корректность введённого пункта.\n"; break;
	}
}

void App::setMazeSize() {
	std::cout << "Введите ширину лабиринта (5-200): ";
	std::cin >> width;
	std::cout << "Введите высоту лабиринта (5-200): ";
	std::cin >> height;

	if (width < 5 || width > 200 || height < 5 || height > 200) {
		std::cout << "Некорректные размеры. Используйте диапазон 5-200.\n\n";
		width = height = 0;
		return;
	}

	maze = MazeBuilder().setSize(width, height).build();
	std::cout << "Лабиринт успешно создан.\n\n";
}

std::unique_ptr<IGeneratorStrategy> App::createGenerator(int generatorType) {
	switch (generatorType) {
		case 1: return std::make_unique<DFSGenerator>();
		case 2: return std::make_unique<KruskalGenerator>();
		default: return nullptr;
	}
}

void App::setGenerator() {
	std::cout << "Выберите алгоритм генерации:\n"
		<< "1. DFS (Depth-First Search)\n"
		<< "2. Kruskal\n"
		<< "Ваш выбор: ";
	int choice;
	std::cin >> choice;
	
	generator = createGenerator(choice);
	if (generator) {
		std::cout << "Алгоритм генерации успешно выбран.\n\n";
	}
	else {
		std::cout << "Неверный тип генератора. Проверьте корректность выбора.\n\n";
	}
}

std::unique_ptr<IPathFinderStrategy> App::createFinder(int finderType) {
	switch (finderType) {
		case 1: return std::make_unique<AStarFinder>();
		case 2: return std::make_unique<BFSFinder>();
		default: return nullptr;
	}
}

void App::setFinder() {
	std::cout << "Выберите алгоритм поиска пути:\n"
		<< "1. A*\n"
		<< "2. BFS (Breadth-First Search)\n"
		<< "Ваш выбор: ";
	int choice;
	std::cin >> choice;

	finder = createFinder(choice);
	if (finder) {
		std::cout << "Алгоритм поиска пути успешно выбран.\n\n";
	}
	else {
		std::cout << "Неверный тип алгоритма поиска пути. Проверьте корректность выбора.\n\n";
	}
}

void App::generate() {

}

void App::display() {

}