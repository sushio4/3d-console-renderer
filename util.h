#pragma once
#include <stdlib.h>

size_t getSize(const char* str);

double lerp(double a, double b, double t);


//function templates


template<typename T, size_t Nigger>
constexpr size_t getSize(const T (&&arr)[Nigger])
{
    return Nigger;
}

template<typename T>
constexpr int sign(T num)
{
    return (num < (T)0) ? -1 : 1;
}