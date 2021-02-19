#ifndef OPERATION_H
#define OPERATION_H

typedef struct {
    double left;
    double right;
    double (*operator)(double, double);
} Operation;

double OperationApply(Operation *operation);

double Plus(double left, double right);

double Minus(double left, double right);

double Multiply(double left, double right);

double Divide(double left, double right);

#endif //OPERATION_H
