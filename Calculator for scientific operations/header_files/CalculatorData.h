#ifndef CALCULATORDATA_H
#define CALCULATORDATA_H

class CalculatorData {
  public:
    CalculatorData();
    CalculatorData(double op1, double op2, char oper);
    ~CalculatorData();

    double getOperand1();
    double getOperand2();
    void setOperand1(double op1);
    void setOperand2(double op2);
    void setOperation(char oper);
    double getResult();
  
  private:
    double operand1;
    double operand2;
    char operation;
    double result;
    double calculateResult();
};

#endif