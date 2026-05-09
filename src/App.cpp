#include "App.h"
#include "MazeBuilder.h"
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
	std::cout << maze;
	std::cout << "Лабиринт успешно создан.\n\n";
}

void App::setGenerator() {

}

void App::setFinder() {

}

void App::generate() {

}

void App::display() {

}