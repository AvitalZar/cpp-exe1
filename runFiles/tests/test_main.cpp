//tchykzr@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

int main(int argc, char** argv) {
    doctest::Context context;
    context.addFilter("reporters", "console");   // options: "console", "xml", "empty", "grader"
    context.run();
}