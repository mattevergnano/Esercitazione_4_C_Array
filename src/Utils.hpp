#pragma once
#include<iostream>
using namespace std;
bool ImportData(const string& InputFilePath,
                size_t& n,
                double& S,
                double*& w,
                double*& r);
int ComputeResults(size_t& n,
                double& S,
                double*& w,
                double*& r,
                double& rRate,
                double& fVal);
int PrintResults(size_t& n,
                double& S,
                double*& w,
                double*& r,
                double& rRate,
                double& fVal);