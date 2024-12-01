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
        "Week 2/Assignment 2/dynamicArrayW2.c")

# Week 3:
add_executable(Lab3 "Week 3/Lab3.c")
add_executable(main_bag "Week 3/Assignment 3/main_bag.c"
        "Week 3/Assignment 3/listbag.c")

# Week 4:
add_executable(main_deque "Week 4/Lab 4/main_deque.c"
        "Week 4/Lab 4/deque.c")
add_executable(main_cirList "Week 4/Assignment 4/main_cirList.c"
        "Week 4/Assignment 4/cirList.c")

# Week 5:
add_executable(Lab5 "Week 5/lab5.c")
add_executable(skipList_main "Week 5/Assignment 5/skipList_main.c"
        "Week 5/Assignment 5/skipList.c")

# Week 6:
add_executable(main_BST "Week 6/Lab 6/main_BST.c"
        "Week 6/Lab 6/BST.c")
add_executable(main_bst "Week 6/Assignment 6/main_bst.c"
        "Week 6/Assignment 6/bst.c")

# Week 8:
add_executable(Lab8 "Week 8/lab8.c")
add_executable(main_heap "Week 8/Assignment 8/main_heap.c"
        "Week 8/Assignment 8/dynamicArray.c")

# Week 10:
add_executable(hashLab "Week 10/hashLab.c")
