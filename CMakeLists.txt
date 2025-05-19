#минимальная версия cmake
cmake_minimum_required(VERSION 3.10)
#имя проекта
project(PPC_DZ3_Task2_BezzabotnovDV_UnitTest)
#добавляем поддиректорию, в которой будет catch2
add_subdirectory(catch2)
#добавляем цель - приложение, у которого исходник с единственным приложением
add_executable(${PROJECT_NAME} "PPC_DZ3_Task2_BezzabotnovDV_UnitTest.cpp")
#линкуемся к catch2, в котором уже есть main
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)