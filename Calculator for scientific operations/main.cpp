/**
 * The programme has a class CalculatorData that handles all of the operations once
 * the operands and operator that it needs are received from the user.
 * 
 * Two possible implementations are seen here under the #ifdef and #ifndef:
 * 
 * On the one hand, we can have local variables in the main that we pass as pointers to
 * the function receiveInput. The later updates the variables and these are passed to
 * a constructor for the calculator whose method is then used to calculate the result.
 * 
 * On the other hand, a constructor is used to create an object of the class CalculatorData
 * and the adress of the object is then passed to a different version of the receiveInput function
 * which updates the attributes of the class using its getters and setters and 
 * the getResult method of the class is then called.
 * 
 * In Both cases, the user only interacts with the receiveInput function and never with
 * the CalculatorData Class itself.
 */
#include "header_files\CalculatorData.h"
#include "header_files\functionFile.h"

//#define OBJECT

int main(void) {

  int operationCompleted = 0;

  std::cout << "Welcome to our Calculator App!" << std::endl;
  char operate = 'y';

  while(operate == 'y' || operate == 'Y') {

    #ifdef OBJECT
      double operand1, operand2;
      char operation;

      // Initializatin phase
      try {
        operationCompleted = receiveInput(&operand1, &operand2, &operation);
        std::cout << "Input received" << std::endl;
      } catch(std::exception &e) {
        operationCompleted = 2;
        std::cout << e.what() << std::endl;
      }
      
      if(operationCompleted == 1) {
        // Creation of CalculatorData object to store data and make it possible to carry out operations with methods
        CalculatorData data = CalculatorData(operand1, operand2, operation);
        std::cout << "Object created" << std::endl;

        // Calculation phase
        std::cout << data.getResult() << std::endl;
      } else if(operationCompleted == 0) {
        std::cout << "Thanks for using our App! :)" << std::endl;
      }
    #endif

    #ifndef OBJECT
      CalculatorData data = CalculatorData();

      // Initializatin phase
      try {
        operationCompleted = receiveInput(&data);
      } catch(std::exception &e) {
        operationCompleted = 2;
        std::cout << e.what() << std::endl;
      }

      // Calculation phase
      if(operationCompleted == 1) std::cout << data.getResult() << std::endl;
      else if(operationCompleted == 0) std::cout << "Thanks for using our App! :)" << std::endl;
    #endif

    std::cout << "Do you want to continue? (y/n)" << std::endl;
    std::cin >> operate;
  }

  return 0;
}