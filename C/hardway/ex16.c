#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person{
    char *name;
    int age;
    int heigth;
    int weigth;
};

struct Person *Person_create(char *name, int age, int heigth, int weigth)
{
    struct Person *who = malloc(sizeof(struct Person));
    assert (who != NULL);

    who->name = strdup(name);
    who->age = age;
    who->heigth = heigth;
    who->weigth = weigth;

    return who;
}

void Person_destroy(struct Person *who)
{
    assert(who != NULL);

    free(who->name);
    free(who);
}

void Person_print(struct Person *person)
{
    printf("Name: %s\n", person->name);
    printf("\tAge: %d\n", person->age);
    printf("\tHeigth: %d\n", person->heigth);
    printf("\tWeigth: %d\n", person->weigth);
}

int main()
{
    struct Person *Joe = Person_create("Joey", 18, 185, 85);
    printf("Joe	is	at	memory	location	%p:\n",	Joe);
	Person_print(Joe);
    Person_destroy(Joe);
    return 0;
}
