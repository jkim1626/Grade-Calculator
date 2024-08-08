// Semester Project Lab
// Jonathan Kim: 1780039
// Problem: As students, you need to track your grades and wonder what grade you need on certain assignments
// Program: A program where you can input your scores, track your grades, and calculate future grades

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

// Function Prototypes
void calcAverage(double[], int, double);
void outputScores(double[], int);
void mergeSort(double[], int, int);
void merge(double[], int, int, int);
void selectionSort(double[], int);
void swap(double *, double *);
void insertionSort(double[], int);
void shellSort(double[], int);
int partition(double[], int, int);
void quickSort(double[], int, int);
void gradeInsert(double *&, int &);
void gradeDelete(double *&, int &);
void findAndReplace(double *&, int);
void calcFinal(double *&, int, double);

int main()
{
    // Prompt user for desired final grade in the class (Letter and Number)
    double finalGrade = 0.0;
    char finalGradeLetter;

    cout << "What grade do you want to end with? (A,B,C,D,F)" << endl;
    cin >> finalGradeLetter;

    while (finalGrade == 0.0)
    {
        if (finalGradeLetter == 'A')
        {
            finalGrade = 90.0;
        }
        else if (finalGradeLetter == 'B')
        {
            finalGrade = 80.0;
        }
        else if (finalGradeLetter == 'C')
        {
            finalGrade = 70.0;
        }
        else if (finalGradeLetter == 'D')
        {
            finalGrade = 60.0;
        }
        else if (finalGradeLetter == 'F')
        {
            finalGrade = 50.0;
        }
        else
        {
            cout << "Please reenter a valid grade " << endl;
            cout << "What grade do you want to end with? (A,B,C,D,F)" << endl;
            cin >> finalGradeLetter;
        }
    }

    // Prompt user for how many assignments they've had so far
    int numAssignments;
    cout << "How many assignments have you had? " << endl;
    cin >> numAssignments;

    // Create an array with the scores they received
    double *grades = new double[numAssignments];
    for (int i = 0; i < numAssignments; i++)
    {
        cout << "Enter the grade you received for assignment " << i + 1 << ": " << endl;
        cin >> grades[i];
    }

    // Output unsorted array of scores as inputted by user
    outputScores(grades, numAssignments);

    // Output the average of the scores from the user
    calcAverage(grades, numAssignments, finalGrade);

    // Output menu options and prompt user to pick an option
    char option;
    cout << endl
         << "Choose an option from the menu: " << endl
         << "A) Sort grades" << endl
         << "B) Insert grade" << endl
         << "C) Delete grade" << endl
         << "D) Find and replace grade" << endl
         << "E) Calculate Average" << endl
         << "F) What you need on the final" << endl
         << "G) Display scores" << endl
         << "H) Quit" << endl
         << endl;
    cin >> option;
    while (option != 'A' && option != 'B' && option != 'C' && option != 'D' && option != 'E' && option != 'F' && option != 'G')
    {
        cout << "Please select a valid option (A)(B)(C)(D)(E)(F)(G): ";
        cin >> option;
    }

    // User option dictates which case to use
    while (true)
    {
        if (option == 'A') // Case A = sorting the array of grades
        {
            char algOption;
            cout << endl
                 << "Which sorting algorithm would you like to use?" << endl
                 << "A) Merge Sort" << endl
                 << "B) Selection Sort" << endl
                 << "C) Insertion Sort" << endl
                 << "D) Shell Sort" << endl
                 << "E) Quicksort" << endl
                 << "F) Quit" << endl
                 << endl;
            cin >> algOption;

            while (true)
            {
                if (algOption == 'A')
                {
                    mergeSort(grades, 0, numAssignments - 1);
                    outputScores(grades, numAssignments);
                }
                else if (algOption == 'B')
                {
                    selectionSort(grades, numAssignments);
                    outputScores(grades, numAssignments);
                }
                else if (algOption == 'C')
                {
                    insertionSort(grades, numAssignments);
                    outputScores(grades, numAssignments);
                }
                else if (algOption == 'D')
                {
                    shellSort(grades, numAssignments);
                    outputScores(grades, numAssignments);
                }
                else if (algOption == 'E')
                {
                    quickSort(grades, 0, numAssignments - 1);
                    outputScores(grades, numAssignments);
                }
                else if (algOption == 'F')
                {
                    break;
                }
                cout << endl
                     << endl
                     << "Which sorting algorithm would you like to use?" << endl
                     << "A) Merge Sort" << endl
                     << "B) Selection Sort" << endl
                     << "C) Insertion Sort" << endl
                     << "D) Shell Sort" << endl
                     << "E) Quicksort" << endl
                     << "F) Quit" << endl
                     << endl;
                cin >> algOption;
            }
        }

        else if (option == 'B') // Case B = Insert Grade into array
        {
            gradeInsert(grades, numAssignments);
        }
        else if (option == 'C') // Case C = Delete a grade from the array
        {
            gradeDelete(grades, numAssignments);
        }
        else if (option == 'D') // Case D = Find and Replace a grade in the array
        {
            findAndReplace(grades, numAssignments);
        }
        else if (option == 'E') // Case E = Calculate and output average of grades
        {
            calcAverage(grades, numAssignments, finalGrade);
        }
        else if (option == 'F') // Case F = Calculate what you need on final
        {
            calcFinal(grades, numAssignments, finalGrade);
        }
        else if (option == 'G') // Case G = Output grades
        {
            outputScores(grades, numAssignments);
        }
        else if (option == 'H') // Case H = Quit Program
        {
            break;
        }

        cout << endl
             << "Choose an option from the menu: " << endl
             << "A) Sort grades" << endl
             << "B) Insert grade" << endl
             << "C) Delete grade" << endl
             << "D) Find and replace grade" << endl
             << "E) Calculate Average" << endl
             << "F) What you need on the final" << endl
             << "G) Display scores" << endl
             << "H) Quit" << endl
             << endl;
        cin >> option;
    }

    // Free memory allocated for grades array
    delete[] grades;

    return 0;
}

// Function to output the scores in the grades array
void outputScores(double grades[], int size)
{
    cout << endl
         << "Your scores: " << endl;
    for (int s = 0; s < size; s++)
    {
        cout << grades[s] << endl;
    }
}

// Function to calculate current score before the final
void calcAverage(double grades[], int size, double finalGrade)
{
    // Get total points and then average it over the number of assignments
    double total = 0.0;
    double average;
    for (int i = 0; i < size; i++)
    {
        total += grades[i];
    }
    average = total / size;
    cout << endl
         << fixed << setprecision(2) << "Average: " << average;

    // Output letter grade alongside numerical grade
    if (average >= 90.0)
    {
        cout << " (A) " << endl;
    }
    else if (average >= 80.0)
    {
        cout << " (B) " << endl;
    }
    else if (average >= 70.0)
    {
        cout << " (C) " << endl;
    }
    else if (average >= 60.0)
    {
        cout << " (D) " << endl;
    }
    else
    {
        cout << " (F) " << endl;
    }

    double difference = finalGrade - average;
    if (difference > 0)
    {
        cout << "You are " << difference << "% under your desired grade" << endl;
    }
    else if (difference < 0)
    {
        cout << "You are " << difference * -1 << "% over your desired grade" << endl;
    }
    else
    {
        cout << "You are right at your desired grade" << endl;
    }
}

// Implementation of merge sort
void mergeSort(double grades[], int left, int right)
{
    if (left < right)
    {
        // Find middle point
        int mid = left + (right - left) / 2;

        // Sort first and secnod halves
        mergeSort(grades, left, mid);
        mergeSort(grades, mid + 1, right);

        merge(grades, left, mid, right);
    }
}

// Merge function to go with merge sort
void merge(double grades[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    double L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
    {
        L[i] = grades[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = grades[mid + 1 + j];
    }

    // Merge the temporary arrays back into grades[left ... right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            grades[k] = L[i];
            i++;
        }
        else
        {
            grades[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remanining elements of L[], if there are any
    while (i < n1)
    {
        grades[k] = L[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        grades[k] = R[j];
        ++j;
        ++k;
    }
}

// Implementation of shell sort
void shellSort(double grades[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            double temp = grades[i];
            int j;
            for (j = i; j >= gap && grades[j - gap] > temp; j -= gap)
            {
                grades[j] = grades[j - gap];
            }

            grades[j] = temp;
        }
    }
}

// Implementation of insertion sort
void insertionSort(double grades[], int size)
{
    double key;
    for (int i = 0; i < size; i++)
    {
        key = grades[i];
        int j = i - 1;

        while (j >= 0 && grades[j] > key)
        {
            grades[j + 1] = grades[j];
            j = j - 1;
        }
        grades[j + 1] = key;
    }
}

// swap function for selection sort
void swap(double *x, double *y)
{
    double temp = *x;
    *x = *y;
    *y = temp;
}

// Implementation of selection sort
void selectionSort(double grades[], int size)
{
    int min;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (grades[j] < grades[min])
            {
                min = j;
            }
        }
        swap(&grades[min], &grades[i]);
    }
}

// Partition function to go with quicksort
int partition(double grades[], int lowIndex, int highIndex)
{

    // Pick middle element as pivot
    int midpoint = lowIndex + (highIndex - lowIndex) / 2;
    double pivot = grades[midpoint];

    // Ensure the leftmost element is less than or equal to the pivot
    if (grades[lowIndex] > grades[highIndex])
    {
        swap(&grades[lowIndex], &grades[highIndex]);
    }
    if (grades[lowIndex] > grades[midpoint])
    {
        swap(&grades[lowIndex], &grades[midpoint]);
    }
    if (grades[midpoint] > grades[highIndex])
    {
        swap(&grades[midpoint], &grades[highIndex]);
    }

    pivot = grades[midpoint];

    while (true)
    {
        while (grades[lowIndex] < pivot)
        {
            lowIndex++;
        }
        while (pivot < grades[highIndex])
        {
            highIndex--;
        }

        // If zero or one elements remain, then all numbers are
        // partitioned
        if (lowIndex >= highIndex)
        {
            return highIndex;
        }
        else
        {
            swap(&grades[lowIndex], &grades[highIndex]);

            // Update lowIndex and highIndex
            lowIndex += 1;
            highIndex -= 1;
        }
    }
    return highIndex;
}

// Implementation of quick sort
void quickSort(double grades[], int low, int high)
{
    // Base case: if the partition size is 1 or 0 elements, then the partition is already sorted
    if (low >= high)
    {
        return;
    }

    // Partition the data within the array. Value lowEndIndex returned from
    // partitioning is the index of the low partition’s last element
    int lowEndIndex = partition(grades, low, high);

    // Recursively sort low partition (lowIndex to lowEndIndex)and high partition
    // (lowEndIndex +1 to highIndex)
    quickSort(grades, low, lowEndIndex);
    quickSort(grades, lowEndIndex + 1, high);
}

// Function to insert a grade into a new dynamically allocated array
void gradeInsert(double *&grades, int &size)
{
    double newGrade;
    cout << endl
         << "Enter the grade for assignment " << size + 1 << ": " << endl;
    cin >> newGrade;

    // Create new array with increased size
    double *newArray = new double[size + 1];

    // Copy existing grades to new array
    for (int i = 0; i < size; ++i)
    {
        newArray[i] = grades[i];
    }

    // Add new grade at the last index
    newArray[size] = newGrade;

    // Delete old array elements
    delete[] grades;

    // Update grades pointer for old array
    grades = newArray;

    // Increment size
    size++;
    cout << "Grade added successfully" << endl;
}

// Function to delete a grade from a new dynamically allocated array
void gradeDelete(double *&grades, int &size)
{
    double oldGrade;
    int index = -1;
    cout << endl
         << "Enter the grade you would like to delete: " << endl;
    cin >> oldGrade;

    // Create new array with increased size
    double *newArray = new double[size - 1];

    // Find index of the grade to be deleted
    for (int i = 0; i < size; i++)
    {
        if (grades[i] == oldGrade)
        {
            index = i;
            break;
        }
    }

    // Grade to be deleted was not found
    if (index == -1)
    {
        cout << "Grade was not found" << endl;
    }
    else
    {
        cout << "Grade deleted successfully" << endl;
    }

    // Copy existing grades to new array going around grades[index]
    for (int s = 0; s < index; s++)
    {
        newArray[s] = grades[s];
    }

    for (int x = index + 1; x < size; x++)
    {
        newArray[x - 1] = grades[x];
    }

    // Delete old array elements
    delete[] grades;

    // Update grades pointer for old array
    grades = newArray;

    // Increment size
    size--;
}

// Function to find grade to be replaced by another grade
void findAndReplace(double *&grades, int size)
{
    double replace;
    double insert;
    bool found = false;
    cout << endl
         << "What grade would you like to replace? ";
    cin >> replace;

    cout << endl
         << "What grade would you like to insert? ";
    cin >> insert;

    for (int i = 0; i < size; i++)
    {
        if (grades[i] == replace)
        {
            grades[i] = insert;
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << endl
             << "Grade replaced successfully" << endl;
    }
    else
    {
        cout << endl
             << "Grade to be replaced was not found" << endl;
    }
}

// Function to find what percent a student needs to get desired grade
void calcFinal(double *&grades, int size, double finalGrade)
{
    // Percent of the grade that final is worth
    double perc;
    cout << endl
         << "What percent of your grade is your final worth? " << endl;
    cin >> perc;

    // Weight of non final category
    double nonPerc = (100.0 - perc) / 100.0;

    // Find grade of non final catgeory
    double total = 0.0;
    for (int i = 0; i < size; i++)
    {
        total += grades[i];
    }
    double currGrade = total / size;

    // Find weight of non final category
    double weightNonPerc = currGrade * nonPerc;

    // Find necessary weight of final category
    double weightPerc = finalGrade - weightNonPerc;

    // Find necessary difference in grade
    double neededGrade = (perc != 0) ? (weightPerc / (perc / 100.0)) : 0;

    cout << "You need a " << neededGrade << " on your final to end with a " << finalGrade << endl;
}
