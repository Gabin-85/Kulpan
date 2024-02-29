#pragma once

#include "defines.h"

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

/**
 * @brief Initializes logging system. Call twice; once with state = 0 to get required memory size,
 * then a second time passing allocated memory to state.
 * 
 * @param memory_requirement A pointer to hold the required memory size of internal state.
 * @param state 0 if just requesting memory requirement, otherwise allocated block of memory.
 * @return b8 True on success; otherwise false.
 */
b8 initialize_logging(u64* memory_requirement, void* state);
void shutdown_logging(void* state);

KAPI void log_output(log_level level, const char* message, ...);

KAPI void format_log_output(log_level level, const char* message, ...);

KAPI void format_jump(const int times);

//Logs for fatal messages
#define KFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);
#define KFORMAT_FATAL(message, ...) format_log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);
#define KJUMP(times) format_jump(times);

#ifndef KERROR
//Logs for error messages
#define KERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif
#ifndef KFORMAT_ERROR
//Logs for error messages
#define KFORMAT_ERROR(message, ...) format_log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif
#ifndef KJUMP_ERROR
//Logs for error jump
#define KJUMP_ERROR(times) format_jump(times);
#endif

#if LOG_WARN_ENABLE == 1
//Logs for warning messages and jump
#define KWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#define KFORMAT_WARN(message, ...) format_log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#define KJUMP_WARN(times) format_jump(times);
#else
//Does nothing when false
#define KWARN(message, ...);
#define KFORMAT_WARN(message, ...);
#define KJUMP_WARN(times);
#endif

#if LOG_INFO_ENABLE == 1
//Logs for info messages
#define KINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#define KFORMAT_INFO(message, ...) format_log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#define KJUMP_INFO(times) format_jump(times);
#else
//Does nothing when false
#define KINFO(message, ...);
#define KFORMAT_INFO(message, ...);
#define KJUMP_INFO(times);
#endif

#if LOG_DEBUG_ENABLE == 1
//Logs for debuging
#define KDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#define KFORMAT_DEBUG(message, ...) format_log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#define KJUMP_DEBUG(times) format_jump(times);
#else
//Does nothing when false
#define KDEBUG(message, ...);
#define KFORMAT_DEBUG(message, ...);
#define KJUMP_DEBUG(times);
#endif

#if LOG_TRACE_ENABLE == 1
//Logs for tracing
#define KTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#define KFORMAT_TRACE(message, ...) format_log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#define KJUMP_TRACE(times) format_jump(times);
#else
//Does nothing when false
#define KTRACE(message, ...);
#define KFORMAT_TRACE(message, ...);
#define KJUMP_TRACE(times);
#endif