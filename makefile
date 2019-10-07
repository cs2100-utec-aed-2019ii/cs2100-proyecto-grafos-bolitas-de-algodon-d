run: compile
	@./project.o

compile:
	@clang++ -o project.o main.cpp -pthreads -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

clear:
	@rm ./project.o
