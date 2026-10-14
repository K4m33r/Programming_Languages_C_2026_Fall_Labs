// week5_task1_file_io.c
// Name: Kamer  Surname: Akcin Student ID: 241ADB155
//
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// TODO: Fill in the missing parts marked below.
//
// Build: make lab5   Run: ./bin/week5_task1_file_io

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_FILENAME "data.txt"
#define LINE_LEN 256

int main(int argc, char* argv[]) {
  FILE* fp = NULL;
  const char* filename = DEFAULT_FILENAME;
  char line[LINE_LEN];
  int line_count = 0;

  printf("Writing lines to %s...\n", filename);
  fp = fopen(filename, "w");

  if (fp == NULL) {
    perror(filename);
    return EXIT_FAILURE;
  }

  fprintf(fp, "Hello, file I/O in C!\n");
  fprintf(fp, "This is another line.\n");

  fclose(fp);

  fp = fopen(filename, "r");

  if (fp == NULL) {
    perror(filename);
    return EXIT_FAILURE;
  }

  printf("Reading contents:\n");

  while (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
  }

  fclose(fp);

  // BONUS: printf("Lines read: %d\n", line_count);

  (void)argc;
  (void)argv;
  (void)fp;
  (void)filename;
  (void)line;
  (void)line_count;

  return EXIT_SUCCESS;
}
