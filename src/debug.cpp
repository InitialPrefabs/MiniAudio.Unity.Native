#include "../headers/debug.h"

// The following function pointers should not be externed.
// You should call safe_debug_log and variants instead.
static debug_ptr debug_log;
static debug_ptr debug_warn;
static debug_ptr debug_error;

void InitializeLogger(debug_ptr log_ptr, debug_ptr warn_ptr, debug_ptr error_ptr) {
	if (debug_log == nullptr) {
		debug_log = log_ptr;
	}

	if (debug_warn == nullptr) {
		debug_warn = warn_ptr;
	}

	if (debug_error == nullptr) {
		debug_error = error_ptr;
	}
}

void safe_debug_log(const char* message) {
	if (debug_log != nullptr) {
		debug_log(message);
	}
}

void safe_debug_warn(const char* message) {
	if (debug_warn != nullptr) {
		debug_warn(message);
	}
}

void safe_debug_error(const char* message) {
	if (debug_error != nullptr) {
		debug_error(message);
	}
}
