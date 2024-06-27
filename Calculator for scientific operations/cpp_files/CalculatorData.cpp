#include <iostream>
#include "..\header_files\CalculatorData.h"

CalculatorData::CalculatorData() {}
CalculatorData::CalculatorData(double op1, double op2, char oper) : operand1(op1), operand2(op2), operation(oper) {}
CalculatorData::~CalculatorData() {}

double CalculatorData::getOperand1() { return operand1; }
double CalculatorData::getOperand2() { return operand2; }
void CalculatorData::setOperand1(double op1) { operand1 = op1; }
void CalculatorData::setOperand2(double op2) { operand2 = op2; }
void CalculatorData::setOperation(char oper) { operation = oper; }

double CalculatorData::getResult() { return calculateResult(); }

double CalculatorData::calculateResult() {
  double result = 0.0;
  std::cout << "Calculating..." << operand1 << " " << operation << " " << operand2 << std::endl;
  switch (operation) {
    case '+':
      result = operand1 + operand2;
      break;
    case '-':
      result = operand1 - operand2;
      break;
    case '*':
      result = operand1 * operand2;
      break;
    case '/':
      result = operand1 / operand2;
      break;
  }

  return result;
}