#include <stdio.h>
#include <string.h>
#define d 10
void rabinKarp(char pat[], char txt[], int q)
{
    int m= strlen(pat);
    int n= strlen(txt);
    int i,j;
    int p=0;
    int t=0;
    int h=1;
    for(i=0;i<m-1;i++){
        h=(h*d)%q;
    }
    for(i=0;i<m;i++){
        p=(d*p+pat[i])%q;
        t=(d*t+txt[i])%q;
    }
    for(i=0;i<=n-m;i++){
        if(p==t){
            for(j=0;j<m;j++){
                if(txt[j+1]!=pat[j])
                break;
            }
            if(j==m){
                printf("%d\n",i);//print index of string match
            }
        }
        if(i<n-m){
            t=(d*(t-txt[i]*h)+txt[i+m])%q;
        if(t<0)
            t=(t+q);
        }
    }
}
int main(){
    char pat[100];
    char txt[100];
    int q=101;
    scanf("%s",txt);
    scanf("%s",pat);
    rabinKarp(pat,txt,q);
    return 0;
}	 	  	 	  	   	 		  	     	  	 	