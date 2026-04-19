#include <App.h>
#include <clocale>

int main() {
	setlocale(LC_ALL, "Russian");

	App app;
	app.run();
	return 0;
}