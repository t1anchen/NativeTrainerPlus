// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the NATIVETRAINERPLUSHELPER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// NATIVETRAINERPLUSHELPER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef NATIVETRAINERPLUSHELPER_EXPORTS
#define NATIVETRAINERPLUSHELPER_API __declspec(dllexport)
#else
#define NATIVETRAINERPLUSHELPER_API __declspec(dllimport)
#endif

// This class is exported from the dll
class NATIVETRAINERPLUSHELPER_API CNativeTrainerPlusHelper {
public:
	CNativeTrainerPlusHelper(void);
	// TODO: add your methods here.
};

extern NATIVETRAINERPLUSHELPER_API int nNativeTrainerPlusHelper;

NATIVETRAINERPLUSHELPER_API int fnNativeTrainerPlusHelper(void);
