/*
CS260 - Assignment 1
Name:
Date:
Solution description:
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
struct Dog
age - int - 0 to 16 years
sex - char - (M)ale or (F)email
*/
struct Dog{
    int age;
    char sex;
};

void foo(int* ptr);
int bar(int*, int*, int);

struct Dog* allocate();
void generate(struct Dog* dogs);
void output(struct Dog* dogs);
void stats(struct Dog* dogs);
void deallocate(struct Dog* dogs);

int main() {
    /*#1*/
    printf("#1 \n");

    /*declare an integer x*/

    /*print the address of x*/
    /*HINT - You might get warnings about format specifiers not agreeing with
    address formats when printing - Don't worry about it*/

    /*Write foo - see below main*/

    /*Call foo() with the address of x*/


    /*#2*/
    printf("#2 \n");

    /*Declare three integers a, b and c and initialize them to 11, 12, & 13
    respectively*/

    /*Print the values of a, b and c*/

    /*Write the bar() function*/

    /*
    The next two steps are one line of code
    Call bar() appropriately, passing a,b,c as parameters
    Print the return value of the call to bar
    */

    /*Print the values of a, b and c again*/
    /*
    Is the return value different than the value of c? Why?
    Express your short answer as a comment below
    */


    /*#3*/
    printf("#3 \n");
    /*create a pointer to Dog struct called dogs*/

    /*Write the allocate function*/

    /*
    call the allocate() function
    set dogs to the pointer returned by the allocate function
    */

    /*Write the generate function*/

    /*call generate*/

    /*Write the output function*/

    /*call output*/

    /*Write the stats function*/

    /*call stats*/

    /*Write the deallocate function*/

    /*call deallocate*/


    return 0;
}

/*
function: foo - the function prints various things about the argument and parameter
arg1: int pointer
pre: ptr is not null
post: output has been written to the console
return: none
*/
void foo(int* ptr) {
    /*Print the value pointed to by ptr*/

    /*Print the address pointed to by ptr*/

    /*Print the address of ptr itself*/

}

/*
function: bar - alters the value of arguments and returns a value. No real purpose
arg1: a - int pointer
arg2: b - int pointer
arg3: c - any integer
pre: a and b are not null
post: the value of a is doubled, the value of b is halved
return: c, the result of some math
*/
int bar(int* a, int* b, int c){
    assert(a != NULL);
    assert(b != NULL);
    /*Set a to double its original value*/

    /*Set b to half its original value*/

    /*Assign a+b to c*/

    /* Do not return 0 - this is just here to make the function compile */
    return c;
}

/*
allocate: uses malloc to allocate memory for 10 dog structs
args: none
pre: none
post - memory has been allocated for 10 dogs
return: pointer to newly allocated dog array
*/
struct Dog* allocate() {
    /*Allocate memory for ten dogs - use malloc*/


    return 0;
}

/*
function: generate - ages and sexes are randomly assigned to 10 dogs
arg1: dogs - Pointer to Dog struct - memory has been allocated for 10 dogs
pre: dogs is not null
post - 10 dogs have been initialized
return: none
*/
void generate(struct Dog* dogs) {
    assert(dogs != NULL);
    /*
    Generate random age and sex for 10 Dogs and store in dogs
    Age is between 0 and 16
    sex is either M or F
    HINT - generate a random between 0 and 1 and convert to char
    HINT - chars use ' vs "
    Calculate random numbers between using rand().
    Simply assigning ages 9, 10, 11... is not sufficient
    */

}

/*
function: output - used to display the values assigned to the age and sex members
of dog structs
arg1: dogs - Pointer to Dog struct - memory has been allocated for 10 dogs and dogs
have been assigned
pre: dogs is not null
post - age and sex of 10 dogs are displayed to the console
return: none
*/
void output(struct Dog* dogs) {
    assert(dogs != NULL);
    /*
    Output information about the ten dogs in the format:
    Dog 1: Age: varAge Sex: varSex
    ...
    Dog 10: Age: varAge Sex: varSex
    */

}

/*
function: stats - used to display the max, min and average age members of dog
structs
arg1: dogs - Pointer to Dog struct
pre: dogs is not null
pre: memory has been allocated for 10 dogs and dogs have been assigned
post: min, max and average of 10 dogs are displayed to the console
*/
void stats(struct Dog* dogs) {
    assert(dogs != NULL);
    /*Compute and print the minimum, maximum and average age of the ten dogs*/

}

/*
function: deallocate - free the memory allocated to dogs
arg1: dogs - Pointer to Dog struct
pre: dogs is not null
pre: memory has been allocated for 10 dogs
post: memory has been freed for dogs
return: none
*/
void deallocate(struct Dog* dogs) {
    /*Deallocate memory from dogs by calling free()*/

}
