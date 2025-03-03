#pragma once
#include <numeric>

div_t floordiv(int a, int b) {
    div_t dv = std::div(a, b);
    if (dv.rem < 0) {
        dv.rem += b;
        dv.quot -= 1;
    }
    return dv;
}