cmake_minimum_required(VERSION 3.5)
project("LiteEngine")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

# Tell CMake where to find the static library
add_library(glfw STATIC IMPORTED)
add_library(freetype STATIC IMPORTED)

set_target_properties(glfw PROPERTIES
    IMPORTED_LOCATION "C:/projects/LiteEngineV003/lib/libglfw3.a"          # Linux/macOS
    # IMPORTED_LOCATION "C:/path/to/glfw3.lib"       # Windows
    INTERFACE_INCLUDE_DIRECTORIES "C:/projects/LiteEngineV003/include/GLFW"
)

#C:\projects\LiteEngineV003\ext\ft27\ft.compiled\lib
set_target_properties(freetype PROPERTIES
    IMPORTED_LOCATION "C:/projects/LiteEngineV003/ext/ft27/ft.compiled/lib/libfreetype.a"
    INTERFACE_INCLUDE_DIRECTORIES "C:/projects/LiteEngineV003/ext/ft27/ft.compiled/include/freetype2"
    )





#C:/projects/LiteEngineV003/ext/ft27/ft.compiled/include/freetype2
#C:\projects\LiteEngineV003\ext\ft27\ft.compiled\lib
#C:\projects\LiteEngineV003\
#add_subdirectory(ext/ft27/ft.compiled/lib)
#target_link_libraries(YourTarget PRIVATE freetype)


add_executable(${PROJECT_NAME}
	src/glad.c
	src/main.cpp
    src/Scene.cpp
	src/imgui.cpp 
    src/imgui_draw.cpp 
    src/imgui_impl_glfw.cpp 
    src/imgui_impl_opengl3.cpp 
    src/imgui_tables.cpp 
    src/imgui_widgets.cpp 
    src/imgui_demo.cpp
    src/FTexture.cpp
    src/Texture.cpp
    src/IndexBuffer.cpp
    src/Renderer.cpp
    src/Parser.cpp
    src/Shader.cpp
    src/VertexArray.cpp
    src/VertexBuffer.cpp
    src/VertexBufferLayout.cpp
    src/Entity.cpp
    #src/Cgrain.cpp
    src/Components.cpp
    src/CTransform.cpp
    src/EntityManager.cpp
    src/EntityMemoryPool.cpp
    src/Csand.cpp
    src/Cgravity.cpp
    src/EntityFactory.cpp
    #src/Scene_Play.cpp
    #src/Scene_CGOL.cpp
    #src/Scene_test.cpp
    src/Scene_FS.cpp
    src/GameEngine.cpp
    #src/SpawnSand.cpp
    #src/PlayRec.cpp
    src/assetManager.cpp
    src/Invoker.cpp
    src/InputHandler.cpp
    src/Library.cpp
    src/miniaudio.c
    )

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE include/GLFW)
target_include_directories(${PROJECT_NAME} PRIVATE include/glad)
target_include_directories(${PROJECT_NAME} PRIVATE include/KHR)
target_include_directories(${PROJECT_NAME} PRIVATE include/glm)
target_include_directories(${PROJECT_NAME} PRIVATE include/glm/detail)
target_include_directories(${PROJECT_NAME} PRIVATE include/glm/ext)
target_include_directories(${PROJECT_NAME} PRIVATE include/glm/gtc)
target_include_directories(${PROJECT_NAME} PRIVATE include/glm/gtx)
target_include_directories(${PROJECT_NAME} PRIVATE include/glm/simd)
#target_include_directories(${PROJECT_NAME} PRIVATE ext/ft27/ft.compiled/include/freetype2)
#C:\projects\LiteEngineV003\ext\ft27\ft.compiled\include\freetype2




target_compile_definitions(${PROJECT_NAME} PRIVATE LITE_ENGINE_RES_DIR="${CMAKE_SOURCE_DIR}/res/")

# OpenGL (always static on Windows)
find_package(OpenGL REQUIRED)
find_package(freetype REQUIRED)



# Link static C/C++ runtime and Windows libraries
if(WIN32)

	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")

    target_link_libraries(${PROJECT_NAME} 
    	glfw
    	winmm
    	OpenGL::GL
    	opengl32
    	gdi32
    	dwmapi
        imm32
        freetype
    )
endif()