#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct mystring{
   uint8_t* data;
   uint8_t lenght;

}str_t;

static str_t* string_create(uint8_t lenght) {
    str_t* string = (str_t*)malloc(sizeof(str_t));
    string->data =(uint8_t*)malloc(lenght);
    string->lenght = lenght;
    return string;
}

void string_free(str_t* string) {
    free(string->data);
    free(string);
}

uint8_t string_lenght(str_t * string) {
    return string->lenght;
}

void print_string(str_t* string, FILE* file)
{
    fwrite(string->data, sizeof(uint8_t), string->lenght, file);
}

str_t* string_dup(const char* str) {
    str_t* string = string_create((uint8_t)strlen(str));
    memcpy(string->data, str, string->lenght);
    return string;
}

str_t* string_concat(str_t* left, str_t* right) {
    str_t* string = string_create(left->lenght + right->lenght);
    memcpy(string->data, left->data, left->lenght);
    memcpy(string->data + left->lenght, right->data, right->lenght);
    return string;
}
