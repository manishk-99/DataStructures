# include <stdio.h>
# include <string.h>
# include <stdlib.h>
  
int areRotations(char *str1, char *str2)
{
  int size1   = strlen(str1);
  int size2   = strlen(str2);
  char *temp;
  void *ptr;
  if (size1 != size2)
     return 0;
  temp   = (char *)malloc(sizeof(char)*(size1*2 + 1));
  temp[0] = ' ';
  strcat(temp, str1);
  strcat(temp, str1);

  ptr = strstr(temp, str2);
  
  free(temp); 
  if (ptr != NULL)
    return 1;
  else
    return 0;
}
int main()
{
    char str1[20];
    scanf("%s" , str1);
    char str2[20];
    scanf("%s" , str2);
    if (areRotations(str1, str2))
       printf("1");
    else
       printf("-1");
  
    getchar();
    return 0;
}