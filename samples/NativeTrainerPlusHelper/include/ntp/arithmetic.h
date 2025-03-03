#pragma once
#include "api.h"

namespace NTP {
    struct NATIVETRAINERPLUSHELPER_API floordiv_t {
        int quot;
        int rem;
    };
    floordiv_t NATIVETRAINERPLUSHELPER_API floordiv(int a, int b);
}