# Assignment 1 - Weighted Undirected Graph (25%)
## Overview
Your task is to implement a Graph class, where every vertex is denoted by a `string`, and every edge has a weight. The class should allow the weight to be any numeric data type, such as `int`, `float`, or `double`.

_For example, the following graph has 5 vertices and 6 edges. These edges have weights of 6, 9, 1, 3, 7, 5._


The class should offer a reasonably effective suite of operations, including but not limited to:

* Adding and removing nodes and edges.

* Depth-first and breadth-first traversals (DFS, BFS).

* Generating a Minimum Spanning Tree (MST).

## The Code
You are provided with two files:

`graph.hpp`: this includes most of the basic definitions you will need. You should define data structures to represent a weighted undirected graph and implement the functions so that they can work correctly. You may add new includes, classes, functions, and/or variables to the class per your need, as long as they do not interfere with the existing definitions. You must NOT change the class name, template, parameters, or return types of functions. 

`main.cpp`: this includes a `main` function. You may write some code to test your data structures and function implementations for the class. This file will not be marked so you can do anything you like with it -- just ensure it does not cause any error. When the "run" button is pressed, it will compile and run main.cpp.

The code has been commented on to explain the purpose of each function. Remember to read over all the code before starting.

When the "_mark_" button is pressed, your code in `graph.hpp` will be run against the tests in Ed. The testing code can only mark your code when your code does not cause a program crash. If you get any error during compiling or your program cannot stop by itself, make sure you fix that problem first!

The basic data structures and the possibilities for implementing graphs have been covered in the lectures. Some parts of the task may require you to develop some thinking because the lectures may not readily give you the solution. Don't hesitate to ask questions if you are unclear about the task requirements. 

## Marking
The assignment will be marked against three components:

**Functionality (18%)** will be marked automatically when you press the "mark" button and will be verified by the teaching team.

**Design (5%)** will be marked by your tutor, who will evaluate your design of data structures & algorithms and may ask questions regarding your code. It will be marked qualitatively against the following rubric:

* Pass The code shows a basic understanding of how to employ data structures to achieve a goal. The design should avoid unnecessary data structures and should make reasonable use of iteration and recursion when appropriate.

* Credit The design shows a solid understanding of data structures and demonstrates effective use of control structures to achieve the program’s goals.

* Distinction The design shows a high degree of understanding of how to use data structures to achieve a goal efficiently and demonstrates some evidence that the design does not use unnecessary resources. The design should be clean and efficient.

* High Distinction The design demonstrates a high degree of understanding of data structures and how to efficiently employ them to build algorithms that not only meet technical goals but also support maintenance and future development.

**Style (2%)** will also be marked by your tutor. It will be marked qualitatively against the following rubric:

* Pass The code mostly uses some formatting standards and is somewhat readable.

* Credit The code adheres well to a formatting standard and variables are well named.

* Distinction At least as well formatted as for Credit standards, along with sufficient inline commenting to explain the code.

* High Distinction Excellent formatting and variable naming. Excellent, judiciously employed comments that explain the code without just repeating the code.

We highly recommend you to attend your Week 9-10 tutorials in person so that you can demonstrate your code and get immediate feedback when you are being marked in design and style. Alternatively, if you cannot attend tutorials in person, you should provide a video (2-3 mins length) explaining the merits (in design and style) of your code for Programming Assignment 1. Your tutor will give your marks in design and style based on your code and video explanation. You may share your video through Google Drive, OneDrive, YouTube, or in any other form with your tutor -- just make sure your tutor can access it.

## Submission
**You must submit your code by pressing the "mark" button on Ed.** No other forms of submission will be accepted. You are welcome to develop your code elsewhere, but remember it must compile and run on Ed. The underlying g++ compiler in Ed is set to C++17 for this assessment. Usually, code that compiles with clang++ should also work with g++.

You may submit as many times as you like before the due date.

## Due Date
Code submission is due by 23 April 2021 at 5:00 PM. A 10% penalty applies to all late submissions made within a week after the due date. No code submissions will be accepted after 30 April 2021.

In-class code demonstration is due in Week 9-10 tutorials. Alternatively, video submission should be made before your Week 10 Tutorial. No late demonstration or video submission will be accepted.

## Plagiarism Checking
All code will be checked for student misconduct and plagiarism using specialised code similarity detection software.
