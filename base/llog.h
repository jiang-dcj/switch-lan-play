#ifndef _LOG_H_
#define _LOG_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define LLOG_ERROR 1
#define LLOG_WARNING 2
#define LLOG_NOTICE 3
#define LLOG_INFO 4
#define LLOG_DEBUG 5

#define LLOG_DISPLAY_LEVEL LLOG_DEBUG

/* expands to the first argument */
#define FIRST(...) FIRST_HELPER(__VA_ARGS__, throwaway)
#define FIRST_HELPER(first, ...) first

// #define LLOG(level, ...) ((level <= LLOG_DISPLAY_LEVEL) && fprintf(stderr, "[%s]%.0s: " FIRST(__VA_ARGS__) "\n", llog_level_names[level], __VA_ARGS__))
#define LLOG(level, ...) LLog_log(level, __VA_ARGS__)

static char *llog_level_names[] = { NULL, "ERROR", "WARNING", "NOTICE", "INFO", "DEBUG" };
static void LLog_log(int level, const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);

  if (level <= LLOG_DISPLAY_LEVEL) {
    fprintf(stderr, "[%s]: ", llog_level_names[level]);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
  }

  va_end(ap);
}

#endif // _LOG_H_
