# Установка минимальной версии CMake 3.10.
cmake_minimum_required(VERSION 3.10)

# Инициализация переменных в CMakeLists.
set(PROJECT_NAME maze_generator)

# Установка названия проекта и минимальной версии компилятора С++17.
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Настройка места хранения скомпилированных файлов.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE})

# Установка исходных файлов проекта.
set(SOURCES
	src/main.cpp
	src/App.cpp
	src/Maze.cpp
	src/Cell.cpp
	src/MazeBuilder.cpp
)

# Формирование итогового исполняемого файла.
add_executable(${PROJECT_NAME} ${SOURCES})

# Подключение заголовков исходных файлов.
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)