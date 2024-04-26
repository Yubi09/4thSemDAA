#include <stdio.h>
#include <string.h>
int main()
{
  char ps[100], s[10], c, o[100];
  int i = 0, j, l, k = 0;
  fgets(ps, 100, stdin);
  scanf("%c", &c);
  scanf("%s", s);
  l = strlen(ps);
  while(i < l){
    if(ps[i] == c){
      for(j = 0; j < strlen(s); j++){
        o[k] = s[j];
        k++;
      }
    }
    else{
      o[k] = ps[i];
      k++;
    }
    i++;
  }
  o[k] = '\0';
  printf("Output: ");
  puts(o);
  printf("\n");

  return 0;
}