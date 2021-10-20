#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <stdio.h>

#include "dichotomy.h"

void test_dichotomy()
{
	//vérifie le bon fonctionnement du dichotomy
	int arr[] = {4, 8, 12, 23, 34, 41, 56, 72, 88, 98, 100, 112, 123, 124, 134, 145, 156, 163, 175, 180, 185, 190, 196, 201, 206, 207};
	CU_ASSERT_EQUAL(find_by_dichotomy(arr, 26, 34), 4);
	CU_ASSERT_EQUAL(find_by_dichotomy(arr, 26, 123), 12);
	CU_ASSERT_EQUAL(find_by_dichotomy(arr, 26, 134), 14);
	CU_ASSERT_EQUAL(find_by_dichotomy(arr, 26, 206), 24);
	CU_ASSERT_EQUAL(find_by_dichotomy(arr, 26, 9999), -1);
}

int main()
{
	CU_initialize_registry();
	CU_pSuite *suite = CU_add_suite("test suite", NULL, NULL);
	CU_add_test(suite, "test_dichotomy", test_dichotomy);
	CU_basic_run_tests();

	return (EXIT_SUCCESS);
}