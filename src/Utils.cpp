#include "Utils.hpp"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

bool ImportData(const string& InputFilePath,
                size_t& n,
                double& S,
                double*& w,
                double*& r)
{
    fstream file(InputFilePath);
    if(file.fail())
        return false;
    string tmp;
    string val;
    getline(file,tmp,';');
    getline(file,val);
    S = stod(val);
    getline(file,tmp,';');
    getline(file,val);
    n = stod(val);
    getline(file,tmp);
    string wtemp = "";
    string rtemp = "";
    w = new double[n];
    r = new double[n];
    for(size_t i=0;i<n;i++){
        getline(file,wtemp,';');
        getline(file,rtemp);
        w[i]=stod(wtemp);
        r[i]=stod(rtemp);
    };
    return true;
};
int ComputeResults(size_t& n,
    double& S,
    double*& w,
    double*& r,
    double& rRate,
    double& fVal)
{
    for(size_t i=0;i<n;i++){
        fVal += (1+r[i])*S*w[i];
    };
    rRate = fVal / S - 1;
    return 0;
};

int PrintResults(size_t& n,
    double& S,
    double*& w,
    double*& r,
    double& rRate,
    double& fVal)
{
    string outputFile = "./results.txt";
    ofstream oFile(outputFile);
    oFile << "S = " <<  fixed << setprecision(2) << S << ", n = " << n << endl;
    oFile << "w = [ ";
    for(size_t i=0;i<n;i++){
        oFile << w[i] << " ";
    }
    oFile << " ]" << endl;
    oFile << "r = [ ";
    for(size_t i=0;i<n;i++){
        oFile << r[i] << " ";
    }
    oFile << " ]" << endl;
    oFile << "Rate of return of the portfolio: " << setprecision(4) << rRate << endl;
    oFile << "V: " << setprecision(2) << fVal << endl;
    return 0;
}