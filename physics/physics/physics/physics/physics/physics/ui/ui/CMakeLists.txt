cmake_minimum_required(VERSION 3.10)
project(SimuladorCampoElectrico)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Encontrar paquetes instalados con vcpkg
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# Dear ImGui (copiar los archivos en include/imgui)
set(IMGUI_DIR "include/imgui")
include_directories(${IMGUI_DIR})
include_directories(${IMGUI_DIR}/backends)

# Archivos del proyecto
set(SOURCES
    main.cpp
    physics/Particula.cpp
    physics/Esfera.cpp
    physics/ObjetoCompartido.cpp
    ui/Panel.cpp
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    glfw
    GLEW::GLEW
    ${OPENGL_LIBRARIES}
    ${GLM_LIBRARY}
)
