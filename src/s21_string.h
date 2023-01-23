#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
//#include <check.h>
#include "s21_sscanf.h"

#define S21_NULL (void *)0
#define BUFF_SIZE 4096
typedef long unsigned s21_size_t;

s21_size_t s21_strlen(const char *str);
s21_size_t s21_strspn(const char *str1, const char *str2);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
int s21_atoi(const char *str_carriage);
int s21_sscanf(const char *str, const char *format, ...);

#endif  // SRC_S21_STRING_H_
