#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <stdio.h>
#include <assert.h>

#ifdef DEBUG
extern FILE *log_fp;
#	define Log_write(format, ...) \
  do { \
    if (log_fp != NULL) { \
      fprintf(log_fp, format, ## __VA_ARGS__); \
      fflush(log_fp); \
    } \
  } while (0)
#else
#	define Log_write(format, ...)
#endif

#define Log(format, ...) \
  do { \
    fprintf(stdout, "\33[1;34m[%s,%d,%s] " format "\33[0m\n", \
        __FILE__, __LINE__, __func__, ## __VA_ARGS__); \
    fflush(stdout); \
    Log_write("[%s,%d,%s] " format "\n", \
        __FILE__, __LINE__, __func__, ## __VA_ARGS__); \
  } while (0)

#define Assert(cond, ...) \
  do { \
    if (!(cond)) { \
      fflush(stdout); \
      fprintf(stderr, "\33[1;31m"); \
      fprintf(stderr, __VA_ARGS__); \
      fprintf(stderr, "\33[0m\n"); \
      assert(cond); \
    } \
  } while (0)

#define panic(format, ...) \
  Assert(0, format, ## __VA_ARGS__)

#define TODO() panic("please implement me")

enum { black = 30, red, green, yellow, blue, purple, darkgreen, white
};

#define kurumi(back, front, format, ...) \
  do { \
      fflush(stdout); \
      fprintf(stdout, "\x1b[%d;%dm", back+10, front); \
      fprintf(stdout, format, ## __VA_ARGS__); \
      fprintf(stdout, "\x1b[0m"); \
  } while (0)

#define DebugText(format, ...) \
  do { \
      fflush(stdout); \
      fprintf(stdout, "\x1b[0;32m"); \
      fprintf(stdout, format, ## __VA_ARGS__); \
      fprintf(stdout, "\x1b[0m"); \
  } while (0)

#define AlarmText(format, ...) \
  do { \
      fflush(stdout); \
      fprintf(stdout, "\x1b[0;31m"); \
      fprintf(stdout, format, ## __VA_ARGS__); \
      fprintf(stdout, "\x1b[0m"); \
  } while (0)

#define TipText(format, ...) \
  do { \
      fflush(stdout); \
      fprintf(stdout, "\x1b[43;34m"); \
      fprintf(stdout, format, ## __VA_ARGS__); \
      fprintf(stdout, "\x1b[0m"); \
  } while (0)

#endif
