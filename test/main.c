#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include "ll.h"

static void test_insert(void **state) {
  uint8_t test1 = 5;
  uint8_t test2 = 3;
  ll_t *ll = NULL;

  ll_insert(&ll, &test1);

  assert_true(ll->data == &test1);

  ll_insert(&ll, &test2);

  assert_true(ll->data == &test2);
  assert_true(ll->next->data == &test1);
  assert_true(ll->next->next == NULL);

  ll_remove(&ll, &test2);
  ll_remove(&ll, &test1);
}

static void test_remove(void **state) {
  uint8_t test1 = 5;
  uint8_t test2 = 3;
  ll_t *ll = NULL;

  ll_insert(&ll, &test1);
  ll_insert(&ll, &test2);
  ll_remove(&ll, &test1);
  
  assert_true(ll->data == &test2);
  assert_true(ll->next == NULL);

  ll_remove(&ll, &test2);
  assert_true(ll == NULL);
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_insert),
    cmocka_unit_test(test_remove),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
