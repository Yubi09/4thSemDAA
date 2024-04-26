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
  int n, i, j, flag;

  printf("Enter the number of students: ");
  scanf("%d", &n);

  STUDENT *studentArray = (STUDENT *)malloc(n * sizeof(STUDENT));

  for (i = 0; i < n; i++)
  {
    printf("Student %d: ", i + 1);
    scanf("%s %s %d", studentArray[i].name, studentArray[i].rollno, &studentArray[i].score);
  }

  for (i = 0; i < n; i++)
  {
    flag = 0;
    for (j = 0; j < n - i - 1; j++)
    {
      if (compareStudents(&studentArray[j], &studentArray[j + 1]) > 0)
      {
        STUDENT tempData = studentArray[j];
        studentArray[j] = studentArray[j + 1];
        studentArray[j + 1] = tempData;
        flag = 1;
      }
    }
    if (flag == 0)
    {
      break;
    }
  }

  printf("Sorted Array of Students:\n");
  for (i = 0; i < n; i++)
  {
    printf("%s %s %d\n", studentArray[i].name, studentArray[i].rollno, studentArray[i].score);
  }

  return 0;
}
