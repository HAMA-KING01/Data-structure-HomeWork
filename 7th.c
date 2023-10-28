//Write the function that prints the record with the longest name in the list.
//Output : the longest name in the list: Abdurrahmangazi
//Length : 15

#include <stdio.h>
#include <string.h>

typedef struct Student {
  char name[64];
  int roll_number;
 
} Student;


void print_record_with_longest_name(Student students[], int num_students) {
  int max_length = 0;
  int longest_name_index = -1;
  for (int i = 0; i < num_students; i++) {
    int length = strlen(students[i].name);
    if (length > max_length) {
      max_length = length;
      longest_name_index = i;
    }
  }

  if (longest_name_index >= 0) {
    printf("The longest name in the list is: %s\n", students[longest_name_index].name);
    printf("Length: %d\n", max_length);
  } else {
    printf("The list is empty.\n");
  }
}

int main() {
  Student students[] = {
    {"mohammed", 1},
    {"ahmet", 2},
    {"Abdurrahmangazi", 3},
  };
  int num_students = sizeof(students) / sizeof(students[0]);

  
  print_record_with_longest_name(students, num_students);

  return 0;
}
