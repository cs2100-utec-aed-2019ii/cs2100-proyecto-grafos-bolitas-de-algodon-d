run: compile
	@./project.o

compile:
	@clang++ -o project.o main.cpp

clear:
	@rm ./project.o
