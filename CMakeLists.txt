cmake_minimum_required(VERSION 3.17)
project(QtOpenCV)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        ${PROJECT_SOURCE_DIR}/include

        ${Qt5Widgets_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS}
)


add_executable(QtOpenCV
        src/main.cpp
        src/MainWindow.cpp
        )


target_link_libraries(${CMAKE_PROJECT_NAME}
        ${Qt5Widgets_LIBRARIES}
        ${OpenCV_LIBRARIES}
        )


