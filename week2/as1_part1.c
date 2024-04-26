#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char name[21];
  char rollno[5];
  int score;
} STUDENT;

int compareStudents(void *rec1, void *rec2)
{
  STUDENT *s1 = (STUDENT *)rec1;
  STUDENT *s2 = (STUDENT *)rec2;
  return ("%d", strcmp(s1->rollno, s2->rollno));
}

int main()
{
  int n, m;
  STUDENT *rec1, *rec2;
  rec1 = (STUDENT *)malloc(sizeof(STUDENT));
  rec2 = (STUDENT *)malloc(sizeof(STUDENT));
  printf("Student 1: ");
  scanf("%s %s %d", rec1->name, rec1->rollno, &rec1->score);
  printf("Student 2: ");
  scanf("%s %s %d", rec2->name, rec2->rollno, &rec2->score);

  printf("%d\n", compareStudents(rec1, rec2));

  return 0;
}