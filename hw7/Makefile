all: hashing catcher

hashing: hashing.cpp HashMap.cpp
	g++ hashing.cpp HashMap.cpp -o bin/hashing

catcher: plagiarismCatcher.cpp HashMap.cpp sorting.cpp
	g++ plagiarismCatcher.cpp HashMap.cpp sorting.cpp -o bin/catcher
