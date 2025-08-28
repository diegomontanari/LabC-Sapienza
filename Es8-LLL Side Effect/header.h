#pragma once

#include <stdbool.h>

// ---------- SCL FLOAT ----------
typedef float TipoInfoSCL;
struct ElemSCL {
    TipoInfoSCL info;
    struct ElemSCL *next;
};

typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL * TipoSCL;

// ---------- SCL CHAR ----------
typedef char TipoInfoChar;
struct ElemSCLChar {
    TipoInfoChar info;
    struct ElemSCLChar *next;
};
typedef struct ElemSCLChar* TipoSCLChar;

// Utility functions
TipoSCL scl_append(TipoSCL scl, TipoInfoSCL val);
void printSCLFloat(TipoSCL scl);
void printSCLChar(TipoSCLChar scl);
TipoSCL createFloatList(float *arr, int n);