#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void computeLPSArray(char *pat, int M, int *lps) {
  int len = 0;
  int i = 1;

  lps[0] = 0; 

  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++; 
      }
    }
  }
}

void KMPSearch(char *pat, char *txt) {
  int M = strlen(pat);
  int N = strlen(txt);

  int *lps = (int *)malloc(sizeof(int) * M);

  computeLPSArray(pat, M, lps);

  int i = 0; // index for txt[]
  int j = 0; // index for pat[]
  int found=0;

  while (i < N) {	 	  	 	  	   	 		  	     	  	 	
    if (pat[j] == txt[i]) {
      i++;
      j++;
    }

    if (j == M) {
      printf("%d ", i - j);
      found = 1;
      j = lps[j - 1];
    } else if (i < N && pat[j] != txt[i]) {
      if (j != 0)
        j = lps[j - 1];
      else
        i++;
    }
  }
    if (found==0) {
        int c=-1;
    printf("%d",c);
  }

  free(lps);
}

int main() {
  char *txt = (char *)malloc(sizeof(char) * 100);
  scanf("%s",txt);
  char *pat = (char *)malloc(sizeof(char) * 100);
  scanf("%s",pat);
  KMPSearch(pat, txt);
  return 0;
  free(txt); 
  free(pat); 
}
	 	  	 	  	   	 		  	     	  	 	
