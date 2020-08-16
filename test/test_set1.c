#include <string.h>

#include "unity.h"
#include "unity_fixture.h"

#include "set1.h"


TEST_GROUP(set1);


TEST_SETUP(set1) {};
TEST_TEAR_DOWN(set1) {};


TEST(set1, test_base64_first_of_four) {
  TEST_ASSERT_EQUAL(0, base64_first_of_four(0));
  TEST_ASSERT_EQUAL(63, base64_first_of_four(255));
  TEST_ASSERT_EQUAL(24, base64_first_of_four(97));
}


TEST(set1, test_base64_second_of_four) {
  TEST_ASSERT_EQUAL(0, base64_second_of_four(0, 0));
  TEST_ASSERT_EQUAL(63, base64_second_of_four(255, 255));
  TEST_ASSERT_EQUAL(22, base64_second_of_four(97, 98));
}


TEST(set1, test_base64_third_of_four) {
  TEST_ASSERT_EQUAL(0, base64_third_of_four(0, 0));
  TEST_ASSERT_EQUAL(63, base64_third_of_four(255, 255));
  TEST_ASSERT_EQUAL(9, base64_third_of_four(98, 99));
}


TEST(set1, test_base64_fourth_of_four) {
  TEST_ASSERT_EQUAL(0, base64_fourth_of_four(0));
  TEST_ASSERT_EQUAL(63, base64_fourth_of_four(255));
  TEST_ASSERT_EQUAL(35, base64_fourth_of_four(99));
}


TEST(set1, test_array_to_base64) {
  uint8_t *base64_data;

  base64_data = array_to_base64(string_to_array("abc"));
  TEST_ASSERT_EQUAL_MESSAGE(0, strcmp(base64_data, "YWJj"), base64_data);

  base64_data = array_to_base64(string_to_array("ab"));
  TEST_ASSERT_EQUAL_MESSAGE(0, strcmp(base64_data, "YWI="), base64_data);

  base64_data = array_to_base64(string_to_array("a"));
  TEST_ASSERT_EQUAL_MESSAGE(0, strcmp(base64_data, "YQ=="), base64_data);
}


TEST(set1, test_hex_to_array) {
  Array string_data = hex_to_array("FF00F01C");

  TEST_ASSERT_EQUAL(4, string_data.length);

  uint8_t expected[4] = {255, 0, 240, 28};
  for(size_t i; i < 4; i += 1) {
    TEST_ASSERT_EQUAL(expected[i], string_data.data[i]);
  }
}


TEST(set1, test_string_to_base64) {
  uint8_t *base64_data = string_to_base64("abc123X");
  TEST_ASSERT_EQUAL_MESSAGE(0, strcmp(base64_data, "YWJjMTIzWA=="), base64_data);
}


TEST(set1, test_hex_to_base64) {
  uint8_t *base64_data = hex_to_base64(
        "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
  );

  uint8_t expected[512] = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
  TEST_ASSERT_EQUAL_MESSAGE(0, strcmp(base64_data, expected), base64_data);
}


TEST_GROUP_RUNNER(set1) {
  RUN_TEST_CASE(set1, test_base64_first_of_four);
  RUN_TEST_CASE(set1, test_base64_second_of_four);
  RUN_TEST_CASE(set1, test_base64_third_of_four);
  RUN_TEST_CASE(set1, test_base64_fourth_of_four);
  RUN_TEST_CASE(set1, test_array_to_base64);
  RUN_TEST_CASE(set1, test_hex_to_array);
  RUN_TEST_CASE(set1, test_string_to_base64);
  RUN_TEST_CASE(set1, test_hex_to_base64);
}
