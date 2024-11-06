clear

g++ -c -I./include src/Perceptron.cpp      -o build/Perceptron.o
g++ -c -I./include src/NeuronalNetwork.cpp -o build/NeuronalNetwork.o
g++ -c -I./include main.cpp                -o build/main.o

g++ build/Perceptron.o build/NeuronalNetwork.o build/main.o -o build/main.exe 

./build/main.exe