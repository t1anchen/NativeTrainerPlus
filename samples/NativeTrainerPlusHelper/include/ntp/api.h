#pragma once

#ifdef NATIVETRAINERPLUSHELPER_EXPORTS
#define NATIVETRAINERPLUSHELPER_API __declspec(dllexport)
#else
#define NATIVETRAINERPLUSHELPER_API __declspec(dllimport)
#endif