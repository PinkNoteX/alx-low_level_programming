#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <elf.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

void elf_checker(unsigned char *e_ident);
void magic_pr(unsigned char *e_ident);
void class_pr(unsigned char *e_ident);
void data_pr(unsigned char *e_ident);
void version_pr(unsigned char *e_ident);
void abi_pr(unsigned char *e_ident);
void osabi_pr(unsigned char *e_ident);
void type_pr(unsigned int e_type, unsigned char *e_ident);
void entry_pr(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);
#endif
