#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Marge d'erreur sur les tests CUNIT en float
 * 
 */
#define CUNIT_GRANULARITY 0.001

void test_dichotomy()
{

}

int main()
{
	CU_initialize_registry();
	CU_pSuite *suite = CU_add_suite("test suite", NULL, NULL);
	CU_add_test(suite, "test_stack", test_dichotomy);
	CU_basic_run_tests();

	return (EXIT_SUCCESS);
}