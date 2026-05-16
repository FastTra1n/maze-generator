add_library(test_helpers STATIC ../test_helpers.cpp)
target_include_directories(test_helpers PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(test_helpers PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# Сценарий №1
add_executable(scenario1 scenario1_full_cycle.cpp)
target_link_libraries(scenario1 PRIVATE maze_lib test_helpers)
target_include_directories(scenario1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# Сценарий №2
add_executable(scenario2 scenario2_kruskal_bfs.cpp)
target_link_libraries(scenario2 PRIVATE maze_lib test_helpers)
target_include_directories(scenario2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# Сценарий №3
add_executable(scenario3 scenario3_different_sizes.cpp)
target_link_libraries(scenario3 PRIVATE maze_lib test_helpers)
target_include_directories(scenario3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# Сценарий №4
add_executable(scenario4 scenario4_same_start_end.cpp)
target_link_libraries(scenario4 PRIVATE maze_lib test_helpers)
target_include_directories(scenario4 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)