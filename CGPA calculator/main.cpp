#include <iostream>
#include <unordered_map>
#include <conio.h>

// To be added in the file of constants
enum GRADES {
  A = 4,
  B = 3,
  C = 2,
  D = 1,
  F = 0
};

int main() {

  bool run = true;
  int numberOfCourses = 0;
  int totalGrade = 0;
  float CGPA = 0.0;

  /*
  Add a file management part to this program so that it can receive data from an excel sheet with a list
  of students in a table with courses as columns and grades for each student under in each row.

  It will read the file, do the calculations and print write the results back into the file at the right
  locations.
  */

  // To be added in the file of constants
  std::unordered_map<char, GRADES> grades = {
    {'A', A}, {'a', A},
    {'B', B}, {'b', B},
    {'C', C}, {'c', C},
    {'D', D}, {'d', D},
    {'F', F}, {'f', F}
  };

  
  while (run)// To turn into a loop over an opened file. Each line read will be passed to the function
  {

    // This will not be useful as the function will receive courses as input.
    std::cout << "Enter a grade in the range (A, B, C, D, F). To exit press 'S':" << std::endl;
    char grade;
    //std::cin >> grade;
    std::cin.get(grade);
    std::cin.get();

    // To be added to the function file. It will be a function that returns the total grades.
    //By taking in the list of courses with grades for a corresponding student    
    if((!(grade >= 'A' && grade <= 'F') && !(grade >= 'a' && grade <= 'f') && grade != 'S' && grade != 's') || grade == 'E' || grade == 'e') {
      
      // In the function, this will be an exception thrown and return
      std::cout << "Invalid grade" << std::endl;
    
    } else if(grade == 'S' || grade == 's') {

      run = false;
    
    } else {

      auto input = grades.find(grade);
      GRADES inputValue = input->second;

      numberOfCourses++;
      totalGrade += inputValue;

    }
  }

  // To be added to the function file. This will calculate the CGPA.
  if(numberOfCourses > 0) { // less than to 0 the function will throw an exception and return

    CGPA = (float)totalGrade / numberOfCourses;
    std::cout << "Your CGPA is: " << CGPA << std::endl;
  
  } else {
  
    std::cout << "No courses entered" << std::endl;
  
  }
  
  return 0;
}