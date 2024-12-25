all: compile run

compile:
		g++ -I ./include/ -o ./lib/BinarySearchTree.o -c ./src/BinarySearchTree.cpp
		g++ -I ./include/ -o ./lib/FileReader.o -c ./src/FileReader.cpp
		g++ -I ./include/ -o ./lib/LinkedList.o -c ./src/LinkedList.cpp
		g++ -I ./include/ -o ./lib/TreeNode.o -c ./src/TreeNode.cpp

		g++ -I ./include/ -o ./bin/program ./lib/BinarySearchTree.o ./lib/FileReader.o ./lib/LinkedList.o ./lib/TreeNode.o ./src/main.cpp
run:
	./bin/program
