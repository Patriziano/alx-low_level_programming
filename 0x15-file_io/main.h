#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int main(int ac, char **av);
void to_copy_file_from_to(char *file_from, char *file_to);
void read_write(int cf, int ct);

/**** elf_header ****/


/*void system_search(char *buff);*/
/*int main(int ac, char **av);*/
/*int elf_search(char *buff);*/
/*void display_info(char *buff);*/
/*void display_data( char *buff);*/
/*void display_version(char *buff);*/
/*void display_osabi(char *buff);*/
/*void display_type(char *buff);*/
/*void display_address(char *buff);*/


int main(int ac, char **av);
void display_magic(unsigned char *e_ident);
void display_class(unsigned char *e_ident);
void display_data(unsigned char *e_ident);
void diplay_osabi(unsigned char *e_ident);
void display_version(unsigned char *e_ident);
void display_type(unsigned int e_entry, unsigned char *e_ident);
void display_entry(unsigned long int e_entry, unsigned char *e_ident);
void display_abi(unsigned char *e_ident);
void to_close(int fo);
void elf_check(unsigned char *e_ident);

#endif
