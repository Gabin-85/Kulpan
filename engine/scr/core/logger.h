#pragma once

#include "../defines.h"

#define LOG_WARN_ENABLE 1
#define LOG_INFO_ENABLE 1
#define LOG_DEBUG_ENABLE 1
#define LOG_TRACE_ENABLE 1

//Disable debug and trace logging while being in a release build.
#if KRELEASE == 1
#DEFINE LOG_DEBUG_ENABLE 0
#DEFINE LOG_TRACE_ENABLE 0
#endif

typedef enum log_level {
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5
} log_level;

b8 initialize_logging();
void shutdown_logging();

KAPI void log_output(log_level level, const char* message, ...);

//Logs for fatal messages
#define KFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);

#ifndef KERROR
//Logs for error messages
#define KERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLE == 1
//Logs for warning messages
#define KWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
//Does nothing when false
#define KWARN(message, ...)
#endif

#if LOG_INFO_ENABLE == 1
//Logs for info messages
#define KINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
//Does nothing when false
#define KINFO(message, ...)
#endif

#if LOG_DEBUG_ENABLE == 1
//Logs for debuging
#define KDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
//Does nothing when false
#define KDEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLE == 1
//Logs for tracing
#define KTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
//Does nothing when false
#define KTRACE(message, ...)
#endif