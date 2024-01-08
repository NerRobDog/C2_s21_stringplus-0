#include <stdio.h>
#include <stdlib.h>

typedef struct String {
    char *str;         // указатель на начало строки
    size_t length;     // длина строки
    size_t capacity;   // общий размер выделенной пятмяти
} String;

size_t s21_strlen(const char *str);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcpy(char *destination, const char *source);
char *s21_strcat(char *destination, const char *source);
char *s21_strchr(const char *str, int ch);
char *s21_strstr(const char *str1, const char *str2);
void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memmove(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strncpy(char *dest, const char *src, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int ch);
size_t s21_strspn(const char *str1, const char *str2);
char *s21_strtok(char *str, const char *delim);
