all:
	@g++ -o 'run' main.cpp rsa.cpp -std=c++11
	@./run
