# Установка минимальной версии CMake 3.10.
cmake_minimum_required(VERSION 3.10)

# Инициализация переменных в CMakeLists.
set(PROJECT_NAME maze_generator)
set(CMAKE_OBJECT_PATH_MAX 400)

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

# Подключение Catch2 для тестирования.
include(FetchContent)

FetchContent_Declare(
	Catch2
	GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	GIT_TAG		   v3.15.0
)

FetchContent_MakeAvailable(Catch2)

# Установка исходных файлов проекта.
set(SOURCES
	src/main.cpp
	src/App.cpp
	src/Maze.cpp
	src/Cell.cpp
	src/MazeBuilder.cpp
	src/DFSGenerator.cpp
	src/KruskalGenerator.cpp
	src/AStarFinder.cpp
	src/BFSFinder.cpp
)

# Статическая библиотека с основной логикой.
add_library(maze_lib STATIC ${SOURCES})
target_include_directories(maze_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(maze_lib PROPERTIES CXX_STANDARD 17)

# Формирование итогового исполняемого файла.
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE maze_lib)

# Подключение заголовков исходных файлов.
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Добавление поддиректории под тесты.
add_subdirectory(tests)