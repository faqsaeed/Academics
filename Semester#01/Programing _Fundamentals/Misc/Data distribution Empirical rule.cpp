#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;


void sort(float arr[], int size)
{
  for ( int i = 0 ; i < size - 1 ; i ++)
  {
    for (int j = 0 ; j < size - i - 1 ; j++)
    {
      if (arr[j + 1] < arr[j])
      {
        swap(arr[j + 1] , arr[j] );
      }
    }
  }
}

float getStandardDeviation(float arr[], int size , float avg)
{
  int std = 0 ;
  float sum = 0.00f;
  float temp = 0.00f;
  for (int num = 0 ; num < size ; num ++)
  {
    temp = arr [num] - avg;
    temp = temp * temp;
    sum = temp + sum;
  }
  std = sum / (size - 1);
  return sqrt(std);
}

float getAverage(float arr[], int size)
{
  float sum=0.0f;
  for ( int i = 0 ; i < size ; i ++)
  {
    sum = sum + arr[i];
  }
  sum = sum / size;
  return sum;
}

void inputArray(float arr[], int size)
{
  srand(time(0));
  for (int i = 0 ; i < size ; i++)
  {
    arr [i] = (rand() % 99) + 1;
  }
}

float percentage(float arr[], int size, float average, float std)
{
  float max = average + std , min = average - std; 
  int count = 0;
  for ( int i = 0 ; i < size ; i ++)
  {
    if (arr [i] < max && arr [i] > min )
    {
      count ++;
    }
  }
  return ((count * 100.0)/size);
}

int main()
{
  float arr[100] , size;
  cout << "Enter the size for the array: \t";
  cin >> size;
  inputArray(arr, size);
  float average = getAverage(arr , 10);
  float standard_deviation = getStandardDeviation(arr , 10 , average);
  cout << percentage( arr , 10 , average , standard_deviation);
}