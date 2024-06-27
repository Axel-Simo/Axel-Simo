#include <iostream>
#include "..\header_files\CalculatorData.h"

void help() {

  std::cin.get();
  std::cout << "The possible operations currently supported are:" << std::endl;
  std::cout << "Addition: +\nSubtraction: -\nMultiplication: *\nDivision: /\n" << std::endl;
  std::cout << "logaritms:\n\tl(for base 2), \n\tL(for base 10)\n" << std::endl;
  std::cout << "Trigonometric functions:\n\tsine: s,\n\tcosine: c,\n\ttangent: t\n" << std::endl;
  std::cout << "Exponential function: e\n" << std::endl;
  std::cout << "Power function: ^\n" << std::endl;
  std::cout << "Square root function: r\n" << std::endl;
  std::cout << "Factorial function: !\n" << std::endl;
  std::cout << "IMPORTANT: The current implementation does not use the rules of PEMDAS.\n" << std::endl;
  std::cout << "Enter a mathematical expression:" << std::endl;

}

/**
 * Function in charge of initializing the variables and receiving the user input
 * It has different if statements aimed at making sure the user inputs the right charaters.
 * The code reads each character one by one until a '\n' is found(the user presses enter).
 * 
 * @param operand1 const point to first operand
 * @param operand2 const point to second operand
 * @param operation const point to operation
 * 
 * They are all updated at the end of the function. Because they are pointers
 * the values are updated in the main function.
 * 
 * @returns didNotInteroptedOperations which tells the calling function if the user did or did not
 * interopt operations
 */
bool receiveInput(double * const operand1, double * const operand2, char * const operation) {

  /*
  0 = did interopted operations
  1 = did not interopted operations
  2 = invalid input
  */
  int didNotInteroptedOperations = 1;

  std::string operand1String;
  std::string operand2String;
  char input = ' ';
  bool firstOperandCompleted =  false;
  bool operationSelected = false;

  std:: cout << "For help on what you can do, type 'h' else..." << std::endl << "Enter the mathematical expression: " << std::endl;
  
  while(input != '\n' || operand2String.length() == 0) {
    input = std::cin.get();
    
    //If user needs help
    if(input == 'h') { help(); continue;}

    //If user wants to stop prematurely
    if(input == '\n' && (operand2String.length() == 0 || !operationSelected)) {
      std::cout << "You must complete the second operand to go ahead.\nDo you want to continue? (Y/N): " << std::endl;

      char ans = std::cin.get();

      if(ans == 'Y' || ans == 'y') {
        ans = std::cin.get();
        std::cout << "Keep on adding digits from where you stopped: " << std::endl;
        continue;
      } else {
        didNotInteroptedOperations = 0;
        break;
      }
    };

    /*
    This 'if' statement is needed because since input is updated INSIDE the loop,
    when one presses enter, the inpput will be tested only at the NEXT iteration
    making it so that the rest of the code in the loop will be executed.
    Now, if the user presses enter, the code in this if will be skipped, and the 
    condition for the while will fail and we will move to the next block of code
    outside the while loop.
    */
    if(input != '\n') {

      //if user puts space between operands and operator
      if(input == ' ' && !firstOperandCompleted) {
        firstOperandCompleted = true;
        continue;
      } else if(input == ' ' && firstOperandCompleted) { continue; }
      
      
      if((std::isdigit(input) || input == '.') && !firstOperandCompleted) {
        // Setting digits and decimal point for the first operand
        operand1String += input;

      } else if((std::isdigit(input) || input == '.') && firstOperandCompleted) {
        // Setting digits and decimal point for the first operand
        operand2String += input;

      } else if(input == '+' || input == '-' || input == '*' || input == '/') {
        // Setting the operator
        *operation = input;
        operationSelected = true;
        firstOperandCompleted = true;

      } else {
        // Invalid input
        didNotInteroptedOperations = 2;
        throw std::invalid_argument("Invalid input");
      }
    }
  }

  *operand1 = std::stod(operand1String);
  *operand2 = std::stod(operand2String);
  
  if(*operation == '/' && *operand2 == 0) {
    throw std::runtime_error("Cannot divide by zero");
  } 

  return didNotInteroptedOperations;
}

/**
 * This is the same as the function above but instead receives just a pointer to a
 * CalculatorData and manipulates the variables it needs to manipulate straight from there.
 */
int receiveInput(CalculatorData * const data) {

  /*
  0 = did interopted operations
  1 = did not interopted operations
  2 = invalid input
  */
  int didNotInteroptedOperations = 1;

  std::string operand1String;
  std::string operand2String;
  char input = ' ';
  bool firstOperandCompleted =  false;
  char operation = ' ';
  bool operationSelected = false;

  std:: cout << "For help on what you can do, type 'h' else..." << std::endl << "Enter the mathematical expression: " << std::endl;

  while(input != '\n' || operand2String.length() == 0) {
    input = std::cin.get();

    if(input == 'h') help();

    if(input == '\n' && (operand2String.length() == 0 || !operationSelected)) {
      std::cout << "You must complete the second operand to go ahead.\nDo you want to continue? (Y/N): " << std::endl;

      char ans = std::cin.get();

      if(ans == 'Y' || ans == 'y') {
        continue;
      } else {
        didNotInteroptedOperations = 0;
        break;
      }
    }

  /*
  This 'if' statement is needed because since input is updated INSIDE the loop,
  when one presses enter, the inpput will be tested only at the NEXT iteration
  making it so that the rest of the code in the loop will be executed.
  Now, if the user presses enter, the code in this if will be skipped, and the 
  condition for the while will fail and we will move to the next block of code
  outside the while loop.
  */
    if(input != '\n') {
      if((std::isdigit(input) || input == '.') && !firstOperandCompleted) {

      operand1String += input;

      } else if((std::isdigit(input) || input == '.') && firstOperandCompleted) {

        operand2String += input;

      } else if(input == '+' || input == '-' || input == '*' || input == '/') {

        operation = input;
        operationSelected = true;
        firstOperandCompleted = true;

      } else {
        didNotInteroptedOperations = 2;
        throw std::invalid_argument("Invalid input");
      }
    }
  }

  data->setOperand1(std::stod(operand1String));
  data->setOperand2(std::stod(operand2String));
  data->setOperation(operation);
  
  if( operation == '/' && data->getOperand2() == 0) {
    throw std::runtime_error("Cannot divide by zero");
  } 

  return didNotInteroptedOperations;
}