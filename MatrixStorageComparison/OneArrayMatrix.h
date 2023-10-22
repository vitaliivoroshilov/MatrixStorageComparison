﻿#pragma once

#include <iostream>
using namespace std;

class OneArrayMatrix
{
public:
    int* array;
    int n, m;

    OneArrayMatrix(int _n, int _m) : n(_n), m(_m)
    {
        array = new int[n * m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                array[i * m + j] = 0;
    }

    OneArrayMatrix(OneArrayMatrix& matr) : n(matr.n), m(matr.m)
    {
        array = new int[n * m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                array[i * m + j] = matr.array[i * m + j];
    }

    friend istream& operator>>(istream& istr, OneArrayMatrix& matr)
    {
        for (int i = 0; i < matr.n; i++)
            for (int j = 0; j < matr.m; j++)
                istr >> matr.array[i * matr.m + j];
        return istr;
    }

    friend ostream& operator<<(ostream& ostr, const OneArrayMatrix& matr)
    {
        for (int i = 0; i < matr.n; i++)
        {
            for (int j = 0; j < matr.m; j++)
                ostr << matr.array[i * matr.m + j] << " ";
            ostr << endl;
        }
        ostr << endl;
        return ostr;
    }

    OneArrayMatrix OneArrayMult(OneArrayMatrix& matr)
    {
        OneArrayMatrix res(n, matr.m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < matr.m; j++)
                for (int k = 0; k < m; k++)
                    res.array[i * matr.m + j] += array[i * m + k] * matr.array[k * matr.m + j];
        return res;
    }
};