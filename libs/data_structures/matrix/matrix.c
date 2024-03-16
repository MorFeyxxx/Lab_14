#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "../../data_structures/matrix/matrix.h"
#include "../../algorithms/algorithm.h"

matrix getMemMatrix(int nRows, int nCols){
    int** values = (int**) malloc(sizeof(int*) * nRows);

    for (size_t i = 0; i < nRows; i++)
        values[i] = (int*) malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix*) malloc(sizeof(matrix) * nMatrices);

    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix *m){
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);

    free(m->values);
    m->values = NULL;
    m->nRows = 0;
    m->nCols = 0;
}

void freeMemMatrices(matrix *ms, int nMatrices){
    for (size_t i = 0; i < nMatrices; i++)
        freeMemMatrix(ms + i);

    free(ms->values);
    ms->values = NULL;
    ms->nRows = 0;
    ms->nCols = 0;
}
