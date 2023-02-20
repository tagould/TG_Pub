/*
Trent Gould
EECS 348
Extra Credit Lab1
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>    // including header files

using namespace std;    // for ease of use

int main()
{    
    /* This block of code is for receiving the name
    of the input file from the user, opening the file,
    reading the file, and closing the file */
    char u_file[100];
    int prog_array[5][5], dept_array[5][5]; // defining 2D arrays
    cout << ("Enter the name of the input file: ");
    cin >> u_file;  // getting the file from the user
    FILE *fptr = fopen(u_file, "r");    // opening the file to read data
    if (fptr == NULL) {exit(EXIT_FAILURE);} // checking if file is empty
    int i = 0, int_array[50], file_line;
    while( fscanf(fptr, "%d", &file_line) != EOF )  // iterating through the file
    {
        int_array[i++] = file_line;  // storing the data from the file in an array
    }
    fclose(fptr);   // closing the file   
    /* End of using file*/

    /* Making arrays for programmers and departments */
    for (int row = 0; row < 10; row++)    // iterating through all programmers and departments
    {
        for (int col = 0; col < 5; col++) // iterating through preferences of each programmers and departments
        {
            if (row < 5) {dept_array[col][row] = int_array[row*5+col];} // if department
            else {prog_array[col][row-5] = int_array[row*5+col];} // if programmer
            
        }
    }
    /* End of making arrays */

    /* Matching programmers to departments*/ 
    unordered_map<int, vector<int>> prog_prefs; // creating an unordered map to store the programmer preferences from the previously generated arrays
    for (int i = 1; i <= 5; i++)    // iterating through the different programmer
    {
        vector<int> prefs(5);   // creating an empty vector to store a programmer's preferences
        for (int j = 0; j < 5; j++) // itereating through the preferences in order 
        {
            prefs[j] = prog_array[i-1][j];  // accessing the array of the programmer preferences and storing them in the unordered map
        }
        prog_prefs[i] = prefs;  // defining part of the unordered map with a programmer's preferences
    }
    unordered_map<int, vector<int>> dept_prefs; // creating an unordered map to store the department preferences from the previously generated arrays
    for (int i = 1; i <= 5; i++)    // iterating through the differnet departments
    {
        vector<int> prefs(5);   // creating an empty vector to store a department's preferences
        for (int j = 0; j < 5; j++)  // itereating through the preferences in order 
        {
            prefs[j] = dept_array[i-1][j];  // accessing the array of the department preferences and storing them in the unordered map
        }
        dept_prefs[i] = prefs;  // defining part of the unordered map with a departments's preferences
    }
    map<int, int> assignments;    // creating an map of department/programmer assignments
    vector<int> free_progs = {1, 2, 3, 4, 5}; // the numbers of the unassinged programmers
    while (!free_progs.empty()) // iterating through the available programmers
    {
        int prog = free_progs.front();  // front value
        free_progs.erase(free_progs.begin());   // removes the front value
        for (int i = 0; i < 5; i++) // iterating through the department preferences
        {
            int dept = prog_prefs[prog][i]; // iterating through programmer's department preferences 
            if (assignments.find(dept) == assignments.end())    // checking for match
            {
                assignments[dept] = prog;   // setting match
                break;  // breaking from loop
            } 
            else // if no perfect match or conflicting matches
            {
                int current_prog = assignments[dept];   // looking at one programmer
                if (dept_prefs[dept][prog - 1] < dept_prefs[dept][current_prog - 1])    // checking how assignments compare and if it is a good fit
                {
                    assignments[dept] = prog;   // setting match
                    free_progs.push_back(current_prog); // adding progammer back into the search algorithm
                    break; // breaking from loop
                }
            }
        }
    }
    /* End of matching*/
    cout << "Assignments:" << endl; // title print statement
    for (const auto& assignment : assignments) // iterating through the department/programmer assignments
    {     
        cout << "Department #" << assignment.first << " has Programmer #" << assignment.second << endl; // printing outputs to the user
    }
    return 0; // end of main
} // end of code