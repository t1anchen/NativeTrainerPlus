// NativeTrainerPlusHelper.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "NativeTrainerPlusHelper.h"


// This is an example of an exported variable
NATIVETRAINERPLUSHELPER_API int nNativeTrainerPlusHelper=0;

// This is an example of an exported function.
NATIVETRAINERPLUSHELPER_API int fnNativeTrainerPlusHelper(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CNativeTrainerPlusHelper::CNativeTrainerPlusHelper()
{
    return;
}
