#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

int main(int agrc, char *argv[])
{
    char ch, *string, *sentence;
    string = (char *)malloc(sizeof(char) * MAXN);
    sentence = (char *)malloc(sizeof(char) * MAXN);
    scanf("%c", &ch);
    scanf("%s", string);
    scanf("\n");
    scanf("%[^\n]%*c", sentence);
    printf("%c\n%s\n%s\n", ch, string, sentence);
    free(string);
    free(sentence);
    return 0;
}
