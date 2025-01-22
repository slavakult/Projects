#include "test.h"

double get_rand(double min, double max) {
  double val = (double)rand() / RAND_MAX;
  return min + val * (max - min);
}

int main(void) {
  Suite *test_suites[] = {
      suite_create_m(),    suite_remove(),    suite_eq(),
      suite_sum(),         suite_sub(),       suite_mult_number(),
      suite_mult(),        suite_transpose(), suite_calc_complements(),
      suite_determinant(), suite_inverse(),   NULL};

  SRunner *sr = srunner_create(test_suites[0]);
  srunner_set_fork_status(sr, CK_NOFORK);
  int nf;

  for (size_t i = 1; test_suites[i] != NULL; i++)
    srunner_add_suite(sr, test_suites[i]);
  srunner_run_all(sr, CK_NORMAL);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
