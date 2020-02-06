
#include "gtest/gtest.h"
#include "gtest/internal/gtest-filepath.h"
#include <string>


#ifdef _OPENMP
#include <omp.h>
#endif

#include <sort/sort.h>

using namespace testing::internal;


class SortLogicalTest : public ::testing::Test
{
protected:

	virtual void SetUp()
	{
	}
};


TEST_F(SortLogicalTest, Zero)
{
  const int vec_size = 1024;

  const std::unique_ptr<uint32_t>	vec = std::unique_ptr<uint32_t>(new uint32_t[vec_size]);
	int* vec_p = reinterpret_cast<int*>(vec.get());

	for (int pos = 0; pos < vec_size; pos++) vec_p[pos] = 0;

	radix_ssort_logical(vec_p, vec_size);
}