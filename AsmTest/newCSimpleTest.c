/* 
 * File:   newCSimpleTest.c
 * Author: raikanarimani
 *
 * Created on May 24, 2013, 6:40 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Simple C Test Suite
 */

void test1() {
    printf("newCSimpleTest test 1\n");
}

void test2() {
    printf("newCSimpleTest test 2\n");
    printf("%%TEST_FAILED%% time=0 testname=test2 (newCSimpleTest) message=error message sample\n");
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% newCSimpleTest\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% test1 (newCSimpleTest)\n");
    test1();
    printf("%%TEST_FINISHED%% time=0 test1 (newCSimpleTest) \n");

    printf("%%TEST_STARTED%% test2 (newCSimpleTest)\n");
    test2();
    printf("%%TEST_FINISHED%% time=0 test2 (newCSimpleTest) \n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
