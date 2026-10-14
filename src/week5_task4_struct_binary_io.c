// week5_task4_struct_binary_io.c   (BONUS)
// Name: Kamer  Surname: Akcin  Student ID: 241ADB155
//
// Task 4: Save and load a struct in binary format with fwrite()/fread()
// Week 5 – Files & Modular Programming
//
// Build: make lab5   Run: ./bin/week5_task4_struct_binary_io

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct Student {
  char name[MAX_NAME_LEN];
  int age;
  float gpa;
} Student;

// Function prototypes (do not change these signatures – the autograder calls
// them directly)
int save_student_binary(const Student* s,
                        const char* filename);  // 0 on success, -1 on error
int load_student_binary(const char* filename,
                        Student* out);  // 0 on success, -1 on error
long file_size(const char* filename);   // bytes, -1 on error

int main(void) {
  Student s1 = {
      0};  // zero-initialised so unused name bytes are not garbage on disk
  strcpy(s1.name, "Alice");
  s1.age = 21;
  s1.gpa = 3.75f;

  Student loaded = {0};
  const char* bin_file = "student.bin";
  const char* txt_file = "student.txt";

  printf("Saving student in binary format...\n");
  if (save_student_binary(&s1, bin_file) != 0) {
    printf("Could not save binary file.\n");
    return EXIT_FAILURE;
  }

  FILE* dosya = fopen(txt_file, "w");
  if (dosya == NULL) {
    printf("Could not open text file.\n");
    return EXIT_FAILURE;
  }

  int sonuc = fprintf(dosya, "%s %d %.2f\n", s1.name, s1.age, s1.gpa);
  int kapanis = fclose(dosya);

  if (sonuc < 0 || kapanis != 0) {
    printf("Could not save text file.\n");
    return EXIT_FAILURE;
  }

  printf("Loading student from binary file...\n");
  if (load_student_binary(bin_file, &loaded) != 0) {
    printf("Could not load binary file.\n");
    return EXIT_FAILURE;
  }

  printf("Loaded student: %s, %d, GPA %.2f\n", loaded.name, loaded.age,
         loaded.gpa);
  printf("Text file size: %ld bytes\n", file_size(txt_file));
  printf("Binary file size: %ld bytes\n", file_size(bin_file));

  return EXIT_SUCCESS;
}

int save_student_binary(const Student* s, const char* filename) {
  FILE* dosya = fopen(filename, "wb");
  if (dosya == NULL) {
    return -1;
  }

  size_t yazilan = fwrite(s, sizeof(Student), 1, dosya);
  int kapanis = fclose(dosya);

  if (yazilan != 1 || kapanis != 0) {
    return -1;
  }

  return 0;
}
int load_student_binary(const char* filename, Student* out) {
  FILE* dosya = fopen(filename, "rb");
  if (dosya == NULL) {
    return -1;
  }

  size_t okunan = fread(out, sizeof(Student), 1, dosya);
  int kapanis = fclose(dosya);

  if (okunan != 1 || kapanis != 0) {
    return -1;
  }

  return 0;
}

long file_size(const char* filename) {
  FILE* dosya = fopen(filename, "rb");
  if (dosya == NULL) {
    return -1;
  }

  if (fseek(dosya, 0, SEEK_END) != 0) {
    fclose(dosya);
    return -1;
  }

  long boyut = ftell(dosya);
  int kapanis = fclose(dosya);

  if (boyut < 0 || kapanis != 0) {
    return -1;
  }

  return boyut;
}
