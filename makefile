compiler = clang++
FLAGS = -D $(directive) -pthreads $(flags)
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
