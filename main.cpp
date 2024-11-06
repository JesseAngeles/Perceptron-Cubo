#include <iostream>
#include <vector>
#include <fstream>

#include "NeuronalNetwork.h"
#include "Perceptron.h"
#include <json.hpp>

#define DIMENTION 3

using namespace std;

void print(vector<float>);

int main()
{
    vector<vector<float>> firstClass = {
        {1, 0, 0},
        {0, 0, 0},
        {1, 1, 0},
        {1, 0, 1}};
    vector<vector<float>> secondClass = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 1},
        {0, 0, 1}};

    vector<float> weights = {1, 1, 1, 1};
    float training_rate = 1;

    Perceptron perceptron(weights, training_rate);

    NeuronalNetwork neuronal_network(firstClass, secondClass, perceptron);
    neuronal_network.calculate();

    nlohmann::json j;
    j["firstClass"] = firstClass;
    j["secondClass"] = secondClass;
    j["weights"] = neuronal_network.getPerceptron().getWeights();

    ofstream file("build/data.json");
    file << j.dump(4);  
    file.close();

    int result = std::system("python python/Grapher.py");

    return 0;
}

void print(vector<float> vec)
{
    for (auto &&v : vec)
        cout << v << "\t";
    cout << endl;
}
