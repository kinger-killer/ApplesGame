cmake_minimum_required(VERSION 3.20)
project(ApplesGame LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG 3.1.0
	GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(SFML)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



add_executable(ApplesGame 
src/main.cpp
)

target_compile_definitions(ApplesGame PRIVATE ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")

target_link_libraries(ApplesGame PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
   )
