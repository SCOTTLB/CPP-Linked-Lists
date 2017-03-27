################################################################################
################################################################################
##                                                                            ##
##                           Scott's Linked List                              ##
##                                  2017                                      ##
##                                                                            ##
################################################################################
################################################################################

Description:

  This is a linked list library written in C++, it contains multiple functions for operating on linked the linked list data structure. It also includes a test
  application to test the methods.

--------------------------------------------------------------------------------

Build:

  Building using the include Makefile:

    llvm/clang/g++ can be used to build the library and the test app.

    The included Makefile contains 3 different targets:

      all:

        This target compiles the library and the test application
        then runs the test application

      library:

        Just builds the library into linkedlist.a

      clean:

        Removes all object code, libraries and executables.


  Toolchain:

    GNU Make 3.81
    LLVM/CLANG - 8.0.0

--------------------------------------------------------------------------------
Author: Scott Bean (40274024)
Date last modified: 27/03/17
Module: Programming Fundamentals
