cmake_minimum_required(VERSION 3.22) # SFML 3 требует более новый CMake
project(bruh)

# SFML 3 строго требует стандарт C++17 или выше
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Локальная установка SFML рядом с репозиторием (some_bullshit/SFML-3.1.0)
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../some_bullshit/SFML-3.1.0")

# Имена компонентов и целей — SFML::Graphics и т.д. (регистр как в SFMLConfig.cmake)
find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(bruh WIN32 main.cpp
    canvas.h
    canvas.cpp
    render.h
    render.cpp
    inputhandler.h 
    inputhandler.cpp
    tools.h
    tools.cpp
    )

target_link_libraries(bruh PRIVATE SFML::Graphics SFML::Window SFML::System)
# Копирование DLL рядом с exe (импортированные SHARED-цели дают путь через $<TARGET_FILE:...>)
if(WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -static")
    add_custom_command(TARGET bruh POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SFML::Graphics> $<TARGET_FILE_DIR:bruh>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SFML::Window> $<TARGET_FILE_DIR:bruh>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SFML::System> $<TARGET_FILE_DIR:bruh>
    )
endif()
