#include <stdio.h>

int main(int argc, char* argv[])
{
	int ages[] = {1,2,3,4,5};
	char* names[] = {"Jane", "Jessie", "Tom", "Peter", "Jack"};
	
	int count = sizeof(ages)/sizeof(int);
	int i = 0;
	
	for(i = 0; i < count; i++){
		printf("%s has %d age \n", names[i], ages[i]);
	}
	
	int *cur_age = ages;
	char **cur_names = names;
	return 0;

}
