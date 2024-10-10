cmake_minimum_required(VERSION 3.29)
project(Data_Structures C)

set(CMAKE_C_STANDARD 90)

# Week 1:
add_executable(Lab1 "Week 1/Lab1.c")
add_executable(Assignment1 "Week 1/Assignment1.c"
        "Week 3/Lab3.c")

# Week 2:
add_executable(testDynArr "Week 2/Lab 2/testDynArr.c"
        "Week 2/Lab 2/dynArr.c")
add_executable(testDynArray "Week 2/Assignment 2/testDynArray.c"
        "Week 2/Assignment 2/dynamicArray.c")

# Week 3:
add_executable(Lab3 "Week 3/Lab3.c")
add_executable(main_bag "Week 3/Assignment 3/main_bag.c"
        "Week 3/Assignment 3/listbag.c")