/*
 * week4_2_struct_student.c
 * Author: [Kamer]
 * Student ID: [241ADB155]
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Define a 'Student' struct with name, id and grade, create two
 *   instances with the values from the instructions, and print them.
 *
 *   This program reads no input. Output must match the format in the
 *   Week 4 instructions exactly (it is checked by the autograder).
 */

#include <stdio.h>
#include <string.h>

struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  struct Student ogrenci1;
  struct Student ogrenci2;

  strcpy(ogrenci1.name, "Alimalik");
  ogrenci1.id = 1001;
  ogrenci1.grade = 9.1f;

  strcpy(ogrenci2.name, "Bob smith");
  ogrenci2.id = 1002;
  ogrenci2.grade = 8.7f;

  printf("Student 1 : %s, ID: %d, Grade: %.1f\n", ogrenci1.name, ogrenci1.id,
         ogrenci1.grade);
  printf("Student 2 : %s, ID: %d, Grade: %.1f\n", ogrenci2.name, ogrenci2.id,
         ogrenci2.grade);

  return 0;
}
