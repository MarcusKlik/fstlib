
#include "gtest/gtest.h"
#include "gtest/internal/gtest-filepath.h"

#include <interface/fststore.h>
#include <interface/fstdefines.h>

#include <fsttable.h>
#include <IntegerMethods.h>

#include "testhelpers.h"
#include "ReadWriteTester.h"
#include "../../lib/fst/interface/icolumnfactory.h"
#include "../../lib/fst/interface/ifsttable.h"
#include "../../lib/fsttable/fsttable.h"
#include "../../lib/fsttable/columnfactory.h"
#include "../../lib/fst/interface/fstdefines.h"
#include "../../lib/fsttable/IntegerMethods.h"
#include "../../lib/fst/interface/fststore.h"


#ifdef _OPENMP
#include <omp.h>
#endif

using namespace testing::internal;
using namespace std;

class CharacterTest : public ::testing::Test
{
protected:
  IFstTable* tableReader;
  IStringArray* selectedCols;
  IColumnFactory* columnFactory;

  std::string filePath;
  std::vector<int> keyIndex;
  StringArray* columnSelection = nullptr;

  virtual void SetUp()
  {
    filePath = GetFilePath("2.fst");
    tableReader = new FstTable();
    selectedCols = new StringArray();
    columnFactory = new ColumnFactory();
  }

  virtual void TearDown()
  {
    delete tableReader;
    delete selectedCols;
    delete columnFactory;
    delete columnSelection;
  }
};


//TEST_F(FactorTest, NaLevels)
//{
//	int nrOfRows = 10;
//	FstTable fstTable(nrOfRows);
//	fstTable.InitTable(1, nrOfRows);
//
//	vector<std::string> colNames {"Factor"};
//	fstTable.SetColumnNames(colNames);
//
//	// Add factor column
//	FactorVectorAdapter factorVec(nrOfRows);
//	IntConstantVal(factorVec.LevelData(), nrOfRows, FST_NA_INT);
//	StringColumn* levels = factorVec.DataPtr()->Levels();
//	levels->AllocateVec(0);
//	fstTable.SetFactorColumn(&factorVec, 0);
//
//	ReadWriteTester::WriteReadSingleColumns(fstTable, filePath, 0);
//}


TEST_F(CharacterTest, MediumLevels)
{
  const int nrOfRows = 1;
  FstTable fstTable(nrOfRows);
  fstTable.InitTable(1, nrOfRows);

  // column names
  vector<std::string> colNames{ "String" };
  fstTable.SetColumnNames(colNames);

  // add string column
  //StringColumn levels;
  //fstTable.SetStringColumn(&levels, 0);

  //FstStore fstStore(GetFilePath("medium_factor2.fst"));
  //fstStore.fstWrite(fstTable, 50);

  EXPECT_FALSE(false);

  //ReadWriteTester::WriteReadSingleColumns(fstTable, filePath, 50);
}


//TEST_F(FactorTest, FactorRead)
//{
//  FstStore fstStore(GetFilePath("medium_factor2.fst"));
//
//  // Read fst file
//  fstStore.fstRead(*tableReader, columnSelection, 1, -1, columnFactory, keyIndex, selectedCols);
//}
