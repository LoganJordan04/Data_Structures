/*
CS260 - Lab 1
Name: Logan Jordan
Date: 9/26/2024
Solution description: Various exercises including structures, pointers, and dynamic memory allocation.
*/

#include <stdio.h>
#include <stdlib.h>

/*
struct Kitty
age - int - 0 to 20 years
*/
struct Kitty{
    int age;
};

void baz(int* ptr);

int main() {
    /*declare an integer num*/
    int num = 100;

    /*print the address of num*/
    printf("The address of num is: %p\n", &num);

    /*print the value of num*/
    printf("The value of num is: %d\n", num);

    /*Call baz() with the address of num*/
    baz(&num);

    /*print the value of num*/
    printf("Double the value of num is: %d\n", num);

    printf("\n");

    /*create a pointer to a Kitty*/
    struct Kitty *kitties = 0;

    /*
    use malloc to allocate memory for 3 Kitty structs
    store the memory as the pointer created above
    */
    kitties = malloc(sizeof(struct Kitty)*3);

    /*assign random ages to each Kitty in kitties*/
    int i;
    for(i = 0; i < 3; i++) {
        kitties[i].age = rand()%20;
    }

    /*print the age of each Kitty in kitties*/
    for(i = 0; i < 3; i++) {
        printf("The age of Kitty %d is: %d\n", i, kitties[i].age);
    }

    /*find the age of the oldest Kitty in kitties*/
    int oldestKitty = kitties[0].age;
    for(i = 0; i < 3; i++) {
        if(kitties[i].age > oldestKitty) {
            oldestKitty = kitties[i].age;
        }
    }

    /*print the age of the oldest Kitty in kitties*/
    printf("The oldest kitty is: %d\n", oldestKitty);

    /*free kitties*/
    free(kitties);
    kitties = 0;

    return 0;
}

/*
function: baz - the function doubles the value of the parameter
arg1: pointer to an int - ptr
pre: ptr has been initialized
post: ptr argument has been doubled
return: none
*/
void baz(int* ptr) {
    /*double the value of ptr*/
    *ptr *= 2;
}
