#include <iostream>
#include <fstream>
#include "utils.hpp"
using namespace std;
int main()
{
    string inputFile = "data.txt";
    //creo la funzione che legge i valori in input
    //devo prima inizializzarli nel main e li passo come reference puntatori
    double S = 0.0;
    size_t n = 0;
    double *w = nullptr;
    double *r = nullptr;
    ImportData(inputFile,n,S,w,r);
    double returnRate = 0.0;
    double finalValue = 0.0;
    ComputeResults(n,S,w,r,returnRate,finalValue);
    PrintResults(n,S,w,r,returnRate,finalValue);
    return 0;
}

