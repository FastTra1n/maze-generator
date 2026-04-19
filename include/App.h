#ifndef APP_H
#define APP_H

class App {
public:
	App();
	~App() = default;

	void run();

private:
	void showMenu();
	void handleCommand(int choice);
	void setMazeSize();
	void setGenerator();
	void setFinder();
	void generate();
	void display();
};

#endif