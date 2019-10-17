compiler = clang++
FLAGS = -pthreads $(flags)
output = project.o

ifeq ($(shell uname -s), Darwin)
    flags = -framework OpenGL -framework GLUT
else
    flags = -lGL -lGLU -lglut
endif

run: compile
	@./$(output)

compile:
	@$(compiler) -o $(output) main.cpp $(FLAGS)

clear:
	@rm ./$(output)
