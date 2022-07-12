#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct student
{
    string studentName;
    double score;
};

void readFromRecord (student studScoreRec[]);
double recAverage (student studScoreRec[], int s);
double recSTDev(student studScoreRec[], int s);
void writeResultToFile (double ave, double stDev);

student arr[7];

int main()
{
    readFromRecord(arr);
    recAverage(arr,7);
    recSTDev(arr, 7);
    writeResultToFile(recAverage(arr, 7), recSTDev(arr, 7));
}

void readFromRecord (student studScoreRec[])
{
    ifstream StreamObj;

    StreamObj.open("StudentScore.txt");

    while(!StreamObj.eof())
    {
       for(int i = 0; i < 7; i++)
       {
           StreamObj>>studScoreRec[i].studentName;
           StreamObj>>studScoreRec[i].score;
       }
    }

    StreamObj.close();
}

double recAverage (student studScoreRec[], int s)
{
    double average = 0.0;
    double total = 0.0;

    for (int index = 0; index < s; index++)
    {
        total += studScoreRec[index].score;
    }

    average = total / s;

    return average;
}

double recSTDev(student studScoreRec[], int s)
{
    double summation = 0.0;
    double difference = 0.0;
    double mean;
    mean = recAverage(arr,7);

    for (int i = 0; i < s; i++)
    {
        difference = pow((studScoreRec[i].score - mean),2);
        summation += difference;
    }

    return sqrt(summation/(s-1));
}

void writeResultToFile(double ave, double stDev)
{
    ofstream StreamObj;

    StreamObj.open("scoreDescStat.txt");
    if(StreamObj.is_open())
    {
        StreamObj<<"Average:\t"<<ave<<endl;
        StreamObj<<"Standard Deviation:\t"<<stDev;

        StreamObj.close();
    }
}
