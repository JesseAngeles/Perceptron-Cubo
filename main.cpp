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

    vector<float> weights;
    float training_rate;

    // Lectura de datos
    cout << "Set weights:\n"; 
    float weight;
    for (int i = 0; i < 4; i++)
    {
        cin >> weight;
        weights.push_back(weight);
    }

    cout << "Set training rate:\n";
    cin >> training_rate;
    


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

    print(neuronal_network.getPerceptron().getWeights());

    return 0;
}

void print(vector<float> vec)
{
    for (auto &&v : vec)
        cout << v << "\t";
    cout << endl;
}
