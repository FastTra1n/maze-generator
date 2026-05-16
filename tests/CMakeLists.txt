add_executable(tests
	test_cell.cpp
	test_maze.cpp
	test_dfs_generator.cpp
	test_kruskal_generator.cpp
    test_astar_finder.cpp
    test_bfs_finder.cpp
	test_helpers.cpp
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain maze_lib)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(integration)