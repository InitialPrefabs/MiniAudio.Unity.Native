#ifndef MINIAUDIO_UNITY_BINDINGS_DEBUG_H
#define MINIAUDIO_UNITY_BINDINGS_DEBUG_H

#ifdef DEBUG_EXPORTS
#define DEBUG_API __declspec(dllexport)
#else
#define DEBUG_API __declspec(dllimport)
#endif

extern "C" {

typedef void(*debug_ptr)(const char* message);

// Hook this in with Debug.Log from Unity.
DEBUG_API void InitializeLogger(debug_ptr log_ptr, debug_ptr warn_ptr, debug_ptr error_ptr);
};

#endif //MINIAUDIO_UNITY_BINDINGS_DEBUG_H
