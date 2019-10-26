compiler = clang++
FLAGS = -std=c++2a -D $(directive) -pthread $(flags)
output = project.o

ifeq ($(shell uname -s), Darwin)
    flags = -framework OpenGL -framework GLUT
		directive = OSX
else
    flags = -lGL -lGLU -lglut
		directive = LINUX
endif

run: compile
	@./$(output)

compile:
	@$(compiler) -o $(output) main.cpp $(FLAGS)

clear:
	@rm ./$(output)
