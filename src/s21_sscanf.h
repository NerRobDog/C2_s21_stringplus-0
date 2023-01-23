#include "s21_string.h"

#ifndef SRC_S21_SSCANF_H_
#define SRC_S21_SSCANF_H_

typedef enum token_width {
    NONE_WIDTH,
    WIDTH_NUMBER,
    WIDTH_AST
} token_width;

typedef enum token_length {
    NONE_LENGTH,
    LENGTH_SHORT,
    LENGTH_LONG,
    LENGTH_LONG_LONG,
    LENGTH_DOUBLE,
    LENGTH_LONG_DOUBLE
} token_length;

typedef struct token {
    // %[width][.precision][length][specifier]
    void *address;
    token_width width;
    unsigned int width_status;
    token_length token_length;
    char buff[1024];
    char spec;
} token;

/* СТРУКТУРА:
 * флаг(плюс/минус)
 * ширина - width (число перед спецификатором)
 * точность - precision (точка)
 * длина - length ()
 * спецификатор(буква после ширины)
 */

token token_parse(char **format, va_list *ap);
int space_check(char c);
int register_check(char c);

long double s21_strtold(const char *buffer);
unsigned long long int s21_strntollu(const char *string, char **endptr, int basis, int n_byte);

void skip_chars_in_buffer(char **src_carriage, int *fail, token *t);
void skip_spaces_in_str(char **src);

int check_EOF_string(const char *src);

void format_parse_width(char **format, token *t);
void format_parse_length(char **format, token *t);
void format_parse_specifier(char **format, token *t);

int parse_number_from_format(char **format);

void write_tokens_to_memory(char **str_carriage, token *t, int token_carriage, int *res);
void write_char_to_memory(char **str_carriage, int *res, token *t);
void write_int_to_memory(char **str_carriage, int *fail_flag, int *res, token *t);
void write_float_to_memory(char **str_carriage, int *res, token *t);
void write_string_to_memory(char **str_carriage, const int *fail_flag, int *res, token *t);
void write_unsigned_to_memory(char **str_carriage, int *fail_flag, int *res, token *t);
void write_8_16_to_memory(char **str_carriage, int *fail_flag, int *res, token *t, int base);
void write_unspec_int_to_memory(char **str_carriage, int *fail_flag, int *res, token *t);

void unsigned_type_converter(token *t, unsigned long long int result, int sign);
void int_type_converter(token *t, long long int result, int sign);
void float_type_converter(token *t, long double result);
#endif // SRC_S21_SSCANF_H_