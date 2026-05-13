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
	, width(0), height(0)
	, startX(0), startY(0), endX(0), endY(0)
	, pathData(std::nullopt) {};

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
			  << "6. Найти путь\n"
			  << "7. Показать лабиринт\n"
		      << "Выберите один из вышеупомянутых пунктов (для выхода введите '0'): ";
}

void App::handleCommand(int choice) {
	switch (choice) {
		case 1: setMazeSize(); break;
		case 2: setGenerator(); break;
		case 3: setFinder(); break;
		case 4: setStartEndPoints(); break;
		case 5: generate(); break;
		case 6: findPath(); break;
		case 7: display(); break;
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
	if (!maze) {
		std::cout << "Невозможно сгенерировать лабиринт без предварительного указания размеров лабиринта.\n\n";
		return;
	}
	if (!generator) {
		std::cout << "Необходимо выбрать алгоритм генерации лабиринта перед его непосредственной генерацией.\n\n";
		return;
	}

	maze->generate(*generator);
	std::cout << "Лабиринт успешно сгенерирован. Для просмотра результата выберите 7 пункт.\n\n";
	currentPath.clear();
}

void App::setStartEndPoints() {
	if (!maze) {
		std::cout << "Сначала создайте лабиринт, перед тем как устанавливать начальную и конечную точки.\n\n";
		return;
	}

	std::cout << "Положение точек определяется в декартовой системе координат.\n"
			  << "Формат ввода координат: x y. Начальная клетка слева сверху имеет координаты x=0 и y=0.\n";
	std::cout << "Введите координаты начальной точки: ";
	std::cin >> startX >> startY;
	if (startX < 0 || startX >= width || startY < 0 || startY >= height) {
		std::cout << "Заданная координата находится вне границ лабиринта. Проверьте корректность введённых x и y.\n\n";
		return;
	}
	std::cout << "Введите координаты конечной точки: ";
	std::cin >> endX >> endY;
	if (endX < 0 || endX >= width || endY < 0 || endY >= height) {
		std::cout << "Заданная координата находится вне границ лабиринта. Проверьте корректность введённых x и y.\n\n";
		return;
	}
	
	if (startX == endX && startY == endY) {
		std::cout << "Координаты начальной и конечной точек совпадают. Путь нулевой длины.\n\n";
	}
	std::cout << "Точки успешно установлены.\n\n";
	currentPath.clear();
}

void App::findPath() {
	if (!maze) {
		std::cout << "Сначала создайте лабиринт, перед тем как находить оптимальный путь.\n\n";
		return;
	}
	if (!finder) {
		std::cout << "Необходимо сначала выбрать алгоритм поиска пути.\n\n";
		return;
	}
	if (startX == 0 && startY == 0 && endX == 0 && endY == 0) {
		std::cout << "Для поиска оптимального пути поставьте начальную и конечную точки.\n\n";
		return;
	}
	Cell startCell(startX, startY);
	Cell endCell(endX, endY);
	currentPath = maze->findPath(*finder, startCell, endCell);
	if (currentPath.empty()) {
		std::cout << "Оптимальный путь не найден.\n\n";
	}
	else {
		std::cout << "Путь найден, длина: " << currentPath.size() << " клеток.\n\n";
	}
	pathData = { startX, startY, endX, endY, currentPath };
	display();
}

void App::display() {
	if (!maze) {
		std::cout << "Невозможно посмотреть лабиринт без предварительной генерации самого лабиринта.\n\n";
		return;
	}

	maze->display(pathData);
}