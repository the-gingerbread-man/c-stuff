#import <stdio.h>
#define MAXLINE 1000

int strindexright(char source[], char target[], int slen, int tlen);

int main(void)
{
  char tsource[22] = "Good Morning, Vietnam!";
  char tt1[3] = "ing";
  char tt2[3] = "log";
  char tt3[3] = "eng";
  char tt4[3] = "orn";

  strindexright(tsource, tt1, 22, 3); // -> 9
  strindexright(tsource, tt2, 22, 3); // -> -1
  strindexright(tsource, tt3, 22, 3); // -> -1
  strindexright(tsource, tt4, 22, 3); // -> 6
}

/* strindexright: finds the rightmost location of target in source,
    returning the index of the first character of the target or -1 */
int strindexright(char source[], char target[], int slen, int tlen)
{
  int is, it; /* indexs for source and target */

  for (is = slen - 1, it = tlen - 1; is > tlen; --is) {

    if (source[is] == target[it]) {

      while(it > 0)
        if (source[--is] != target[--it])
          break;

      if (it == 0 && source[is] == target[it]) /* loop gives false positive when the final character doesn't match */
        return is;

      is += tlen - it - 1;
      it = tlen - 1;
    }
  }

  return -1; /* match not found */
}
