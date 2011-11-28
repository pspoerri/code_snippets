project(OpenGLTest)
find_package(GLUT)
find_package(OpenGL)
INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})
set(SRCS
    src/main.c
    )

ADD_EXECUTABLE(opengl_minimal ${SRCS})
TARGET_LINK_LIBRARIES(opengl_minimal ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
