#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char name[21];
  char rollno[5];
  int score;
  struct STUDENT *next;
} STUDENT;

int compareStudents(void *rec1, void *rec2)
{

  STUDENT *s1 = (STUDENT *)rec1;
  STUDENT *s2 = (STUDENT *)rec2;

  int roll1 = atoi(s1->rollno);
  int roll2 = atoi(s2->rollno);

  if (roll1 > roll2)
  {
    return 1;
  }
  else if (roll1 < roll2)
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

void insertStudent(STUDENT **head, STUDENT *newStudent)
{
  if (*head == NULL || compareStudents(newStudent, *head) < 0)
  {
    newStudent->next = *head;
    *head = newStudent;
  }

  else
  {
    STUDENT *current = *head;
    while (current->next != NULL && compareStudents(newStudent, current->next) >= 0)
    {
      current = current->next;
    }
    newStudent->next = current->next;
    current->next = newStudent;
  }
}

int main()
{
  STUDENT *head = NULL;

  int n;

  printf("How many students : ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    STUDENT *s = (STUDENT *)malloc(sizeof(STUDENT));

    printf("Student %d: ", i + 1);
    scanf("%s %s %d", s->name, s->rollno, &s->score);
    s->next = NULL;

    insertStudent(&head, s);
  }

  STUDENT *current = head;
  while (current != NULL)
  {
    printf("%s %s %d\n", current->name, current->rollno, current->score);
    current = current->next;
  }

  while (head != NULL)
  {
    STUDENT *temp = head;
    head = head->next;
    free(temp);
  }

  return 0;
}