#include <stdio.h>
int main()
{
  int N;
  printf("Make an input for size of Array:\n");
  scanf("%d", &N);

  int a[N+1];
  printf("Fill in your Array\n");
  for(int i=0; i<N; i++)
  {
    printf("Position %d: \n", i+1);
    scanf("%d", &a[i]);
  }

  int pos, new;
  printf("Enter the position and New value\n");
  scanf("%d\n%d", &pos, &new);

  //[][][][][]+[]

  for(int j=N; j>=pos; j--)
  {
    a[j] = a[j-1];
  }
  a[pos-1]=new;

  printf("Updated Array:\n");
  for(int i=0; i<=N; i++)
  {
    printf("%d\n", a[i]);
  }
  return 0;
}
