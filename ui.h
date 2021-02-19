#ifndef UI_H
#define UI_H

#include "calculator.h"

typedef struct {
    void *text_displayer;
    CalcContext *context;
} UiContext;

#endif //UI_H

