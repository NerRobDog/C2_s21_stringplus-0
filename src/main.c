#include <string.h>
#include "s21_string.h"
#include <check.h>
#include <stdlib.h>

START_TEST (test_s21_memset)
{
  char original[10];
  char custom[10];

  memset(original, 'a', 10);
  s21_memset(custom, 'a', 10);

  ck_assert_str_eq(original, custom);
}
END_TEST

START_TEST (test_s21_strlen)
{
  char str[] = "Hello, World!";

  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST (test_s21_strcmp)
{
  char str1[] = "Hello, World!";
  char str2[] = "Hello, World!";
  char str3[] = "Hello, There!";

  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
  ck_assert_int_eq(s21_strcmp(str1, str3), strcmp(str1, str3));
}
END_TEST

START_TEST (test_s21_memcpy)
{
  char original[50], custom[50];

  strcpy(original, "This is string.h library function");
  strcpy(custom, "This is string.h library function");

  memcpy(original + 5 , original, 10);
  s21_memcpy(custom + 5 , custom, 10);

  ck_assert_str_eq(original, custom);
}
END_TEST

START_TEST (test_s21_strcpy)
{
  char source[] = "Source string";
  char target[50];
  char compare[50];

  s21_strcpy(target, source);
  strcpy(compare, source);
  ck_assert_str_eq(target, compare);
}
END_TEST

START_TEST (test_s21_strcat)
{
  char dest[50] = "Hello";
  char source[] = ", World!";
  char compare[50] = "Hello";

  s21_strcat(dest, source);
  strcat(compare, source);
  ck_assert_str_eq(dest, compare);
}
END_TEST

START_TEST (test_s21_strchr)
{
  char str[] = "This is a sample string";
  char c = 's';

  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strstr)
{
  char haystack[] = "This is a sample string";
  char needle[] = "sample";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
  ck_assert_ptr_eq(s21_strstr(haystack, "notfound"), strstr(haystack, "notfound"));
}
END_TEST

START_TEST(test_s21_memchr)
{
  char mem[] = "This is a sample string";
  char c = 's';

  ck_assert_ptr_eq(s21_memchr(mem, c, strlen(mem)), memchr(mem, c, strlen(mem)));
  ck_assert_ptr_eq(s21_memchr(mem, 'z', strlen(mem)), memchr(mem, 'z', strlen(mem)));
}
END_TEST

START_TEST(test_s21_memcmp)
{
  char mem1[] = "abc";
  char mem2[] = "abc";
  char mem3[] = "abe";

  ck_assert_int_eq(s21_memcmp(mem1, mem2, 3), memcmp(mem1, mem2, 3));
  ck_assert_int_eq(s21_memcmp(mem1, mem3, 3), memcmp(mem1, mem3, 3));
}
END_TEST

START_TEST(test_s21_memmove)
{
  char str[50] = "This is a sample string";
  char original[50];

  strcpy(original, str);

  s21_memmove(str + 3, str, strlen(str) + 1);
  memmove(original + 3, original, strlen(original) + 1);

  ck_assert_str_eq(str, original);
}
END_TEST

START_TEST(test_s21_strncat)
{
  char dest[50] = "Hello";
  char src[] = "World";
  char original[50] = "Hello";

  s21_strncat(dest, src, 3);
  strncat(original, src, 3);

  ck_assert_str_eq(dest, original);
}
END_TEST

START_TEST(test_s21_strncmp)
{
  char str1[] = "abc";
  char str2[] = "abd";

  ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}
END_TEST

START_TEST(test_s21_strncpy)
{
  char dest[50];
  char original[50];
  char src[] = "source string";

  s21_strncpy(dest, src, strlen(src) + 1);
  strncpy(original, src, strlen(src) + 1);

  ck_assert_str_eq(dest, original);
}
END_TEST

START_TEST(test_s21_strcspn)
{
  char str1[] = "abcdef";
  char str2[] = "g";

  ck_assert_uint_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk)
{
  char str1[] = "abcdef";
  char str2[] = "eg";

  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strrchr)
{
  char str[] = "This is a simple string";

  ck_assert_ptr_eq(s21_strrchr(str, 'i'), strrchr(str, 'i'));
}
END_TEST

START_TEST(test_s21_strspn)
{
  char str1[] = "abcdef";
  char str2[] = "c";

  ck_assert_uint_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strtok)
{
  char str[50] = "This-is-a-simple-string";
  char original[50] = "This-is-a-simple-string";
  char *token;
  char *original_token;
  char delim[] = "-";

  token = s21_strtok(str, delim);
  original_token = strtok(original, delim);

  while(token != NULL) {
    ck_assert_str_eq(token, original_token);
    token = s21_strtok(NULL, delim);
    original_token = strtok(NULL, delim);
  }
}
END_TEST

START_TEST (test_s21_strerror)
{
  // Given an error number, s21_strerror should not return NULL
  ck_assert_ptr_nonnull(s21_strerror(EPERM));

  // Subsequent calls to s21_strerror should not modify previous result
  const char *err1 = s21_strerror(EPERM);
  const char *err2 = s21_strerror(EACCES);
  ck_assert_ptr_nonnull(err1);
  ck_assert_ptr_nonnull(err2);
  ck_assert_str_ne(err1, err2);
}
END_TEST

Suite * string_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_string");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_s21_memset);
    tcase_add_test(tc_core, test_s21_strlen);
    tcase_add_test(tc_core, test_s21_strcmp);
    tcase_add_test(tc_core, test_s21_memcpy);
    tcase_add_test(tc_core, test_s21_memcpy);
    tcase_add_test(tc_core, test_s21_strcpy);
    tcase_add_test(tc_core, test_s21_strcat);
    tcase_add_test(tc_core, test_s21_strchr);
    tcase_add_test(tc_core, test_s21_strstr);
    tcase_add_test(tc_core, test_s21_memchr);
    tcase_add_test(tc_core, test_s21_memcmp);
    tcase_add_test(tc_core, test_s21_memmove);
    tcase_add_test(tc_core, test_s21_strncat);
    tcase_add_test(tc_core, test_s21_strncmp);
    tcase_add_test(tc_core, test_s21_strncpy);
    tcase_add_test(tc_core, test_s21_strcspn);
    tcase_add_test(tc_core, test_s21_strpbrk);
    tcase_add_test(tc_core, test_s21_strrchr);
    tcase_add_test(tc_core, test_s21_strspn);
    tcase_add_test(tc_core, test_s21_strtok);
    tcase_add_test(tc_core, test_s21_strerror);
    
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void){
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = string_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;  
}