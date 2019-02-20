/*************************************************************************************************************
CIS 22B
Lab 1: This program reads from a file containing 10 scores of a student in each line.
       Then it calculates the average final score of each student and stores them in
       a vector. The vector is then sorted before the class average and median are
       calculated. The scores are displayed to in ascending order along with the median
       and average score.
Author: Vincent Nguyen
Date: 1/18/19
*************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/*************************************************************************************************************
This function processes the file and stores the average of each student in the vector passed to it.
The variable "number" holds an individual number from inputFile before it is added to lineTotal.
*************************************************************************************************************/
void readFile (vector<double> &v)
{
    string fileName;
    ifstream inputFile;
    int lineTotal;
    int number;

    inputFile.open("lab1.txt");
    if (!inputFile)
    {
        inputFile.close();
        cout << "Error opening file. Please enter a file name: ";
        cin >> fileName;
        inputFile.open(fileName.c_str());
        while(inputFile.fail())
        {
            cout << "Error opening file. Please enter a file name: ";
            cin >> fileName;
            inputFile.open(fileName.c_str());
        }
    }
    while (!inputFile.eof())
    {
            lineTotal = 0;
            for (int i = 0; i < 10; i++)
            {
                inputFile >> number;
                lineTotal += number;
            }

            v.push_back(lineTotal / 10);
    }
    v.pop_back();
}

/*************************************************************************************************************
This function sorts the vector passed to it into ascending order.
*************************************************************************************************************/
void sortScores (vector<double> &v)
{
    sort(v.begin(),v.end());
}

/*************************************************************************************************************
This function uses the vector passed to it to calculate and return the class average.
*************************************************************************************************************/
double calcAverage (vector<double> &v)
{
    double average, total = 0;
    for (int i = 0; i < v.size(); i++)
    {
        total += v[i];
    }
    average = total / v.size();
    return average;
}

/*************************************************************************************************************
This function uses the vector passed to calculate and return the class median.
*************************************************************************************************************/
double calcMedian (vector<double> &v)
{
    double median;
    int remainder = v.size() % 2;
    if (remainder == 0)
        median = (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2;
    else
        median = v[v.size() / 2];
    return median;
}

/*************************************************************************************************************
This function receives the vector of sorted final scores, the class average, and class median and
displays the information to standard output.
*************************************************************************************************************/
void displayInfo (vector<double> v, double average, double median)
{
    cout << "The final scores of each student sorted from least to greatest are ";
    for(int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << ", ";
    }
    cout << "and " << v[v.size() - 1] << ".\n";
    cout << "The class average is " << average << ".\n";
    cout << "The class median is " << median << ".\n";
}

/*************************************************************************************************************
The main function creates the finalScores vector, calls the file processing function, the
sorting function, and the information display function.
*************************************************************************************************************/
int main()
{
    vector<double> finalScores;
    readFile (finalScores);
    sortScores (finalScores);
    displayInfo (finalScores, calcAverage (finalScores), calcMedian (finalScores));
}

/*************************************************************************************************************
Output:
The final scores of each student sorted from least to greatest are 66, 71, 73, 81, 82, 84, 86, 91, 93, and 95.
The class average is 82.2.
The class median is 83.

Process returned 0 (0x0)   execution time : 0.459 s
Press any key to continue.
*************************************************************************************************************/
