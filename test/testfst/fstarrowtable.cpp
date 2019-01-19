
// google test
#include "gtest/gtest.h"

// fst
#include <interface/fststore.h>
#include "testhelpers.h"

// arrow
#include <arrow/api.h>


#ifdef _OPENMP
#include <omp.h>
#endif

using namespace testing::internal;
using namespace arrow;

class ArrowIntegerTest : public ::testing::Test
{
  protected:

	  std::string filePath;

	  virtual void SetUp()
	  {
		  filePath = GetFilePath("logical.fst");
	  }
};


TEST_F(ArrowIntegerTest, BuildArrowTable)
{
  Int8Builder builder;
  builder.Append(1);
  builder.Append(-1);
  std::shared_ptr<Array> i8_array;
  builder.Finish(&i8_array);

  StringBuilder str_builder;
  str_builder.Append("test");
  str_builder.Append("another test");
  std::shared_ptr<Array> str_array;
  str_builder.Finish(&str_array);

  EXPECT_EQ(1, 1);
}
