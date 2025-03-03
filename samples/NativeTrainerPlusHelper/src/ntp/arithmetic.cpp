#include "ntp/arithmetic.h"
#include "ntp/api.h"
#include "pch.h"

namespace NTP {
    floordiv_t NATIVETRAINERPLUSHELPER_API floordiv(int a, int b) {
        int q = a / b;
        int r = a % b;
        floordiv_t dv{ q, r };
        if (dv.rem < 0) {
            dv.rem += b;
            dv.quot -= 1;
        }
        return dv;
    }
}