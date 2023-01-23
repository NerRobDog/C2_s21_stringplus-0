cmake_minimum_required(VERSION 3.23)
project(s21_string_plus C)

set(CMAKE_C_STANDARD 11)

add_library(s21_string.h s21_strlen.c s21_sscanf.c s21_sscanf.h s21_strtold.c s21_srtntollu.c s21_strspn.c s21_memset.c s21_strcpy.c main.c s21_atoi.c)
