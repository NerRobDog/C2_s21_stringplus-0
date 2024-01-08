# Названия исполняемого файла
TARGET = s21_string

# Компилятор
CC = gcc

# Опции компиляции
CFLAGS = -std=c11 #-Wall -Wextra -Werror -pedantic

# Создаем список исходных файлов .c и .h
SOURCE = main.c s21_string.c
HEADER = s21_string.h

# Правило по умолчанию, связывающее выполняемый файл с исходными файлами
all: $(TARGET)

$(TARGET): $(SOURCE) $(HEADER)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

clean:
	rm -f $(TARGET)