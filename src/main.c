#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <stdio.h>

#include "dichotomy.h"
#include "glouton.h"

void test_dichotomy()
{
	//vérifie le bon fonctionnement du dichotomy
	int arr[] = {4, 8, 12, 23, 34, 41, 56, 72, 88, 98, 100, 112, 123, 124, 134, 145, 156, 163, 175, 180, 185, 190, 196, 201, 206, 207};
	CU_ASSERT_EQUAL(find_by_dichotomy(arr, 26, 34), 4);
	CU_ASSERT_EQUAL(find_by_dichotomy(arr, 26, 123), 12);
	CU_ASSERT_EQUAL(find_by_dichotomy(arr, 26, 134), 14);
	CU_ASSERT_EQUAL(find_by_dichotomy(arr, 26, 206), 24);

	//valeur non existant
	CU_ASSERT_EQUAL(find_by_dichotomy(arr, 26, 9999), -1);
}

void test_glouton()
{
	glouton g[3] = {{5, 5},
					{7, 6},
					{5, 5}};

	glouton *out = (glouton *)malloc(sizeof(glouton) * 3);
	int sout = 0;
	GloutonFillByQP(&g, 3, 10, out, &sout);
	CU_ASSERT_EQUAL(out[0].c, 7);
	CU_ASSERT_EQUAL(out[0].w, 6);
}

int main()
{
	CU_initialize_registry();
	CU_pSuite *suite = CU_add_suite("test suite", NULL, NULL);
	CU_add_test(suite, "test_dichotomy", test_dichotomy);
	CU_add_test(suite, "test_glouton", test_glouton);
	CU_basic_run_tests();

	return (EXIT_SUCCESS);
}