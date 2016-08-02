#include "stdafx.h"
#include "CppUnitTest.h"
#include "../llkanErase/LineUp.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LineUpUnitTest
{		
	TEST_CLASS(LineUpTest)
	{
	public:
		TEST_METHOD(CellTest)
		{
            Cell cell = Cell();
            Assert::IsTrue(cell.isNull);

            cell = Cell(1, 2);
            Assert::AreEqual(1, cell.col);
            Assert::AreEqual(2, cell.row);
		}

        TEST_METHOD (test2x2Array)
        {
            LineUpArray cellArray(2, 2, 2);
            cellArray.InitWithArray({ { 1, 2 },{ 1, 2 } });
            Assert::IsTrue(cellArray.GetCellValue(0, 0) == 1);
            Assert::IsTrue(cellArray.GetCellValue(0, 1) == 2);
            Assert::IsTrue(cellArray.GetCellValue(1, 0) == 1);
            Assert::IsTrue(cellArray.GetCellValue(1, 1) == 2);
            Assert::IsTrue(cellArray.IsConectted(0, 0, 1, 0).IsConnected);
            Assert::IsTrue(!cellArray.IsConectted(0, 0, 0, 1).IsConnected);
        }

        TEST_METHOD(test3x2Array)
        {
            LineUpArray cellArray(2, 3, 2);
            cellArray.InitWithArray({ { 1, 2, 2 },{ 2, 1, 2 } });

            Assert::IsTrue(cellArray.GetCellValue(0, 0) == 1);
            Assert::IsTrue(cellArray.GetCellValue(0, 1) == 2);
            Assert::IsTrue(cellArray.GetCellValue(0, 2) == 2);
            Assert::IsTrue(cellArray.GetCellValue(1, 0) == 2);
            Assert::IsTrue(cellArray.GetCellValue(1, 1) == 1);
            Assert::IsTrue(cellArray.GetCellValue(1, 2) == 2);
            Assert::IsTrue(cellArray.IsConectted(0, 1, 0, 2).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(1, 0, 1, 2).IsConnected);
            Assert::IsTrue(!cellArray.IsConectted(0, 0, 1, 1).IsConnected);
        }

        TEST_METHOD(test3x2PartArray)
        {
            LineUpArray cellArray(2, 3, 2);
            cellArray.InitWithArray({ { 1, 0, 0 },{ 2, 2, 1 } });

            Assert::IsTrue(!cellArray.IsConectted(0, 0, 0, 1).IsConnected);
            Assert::IsTrue(!cellArray.IsConectted(1, 0, 0, 1).IsConnected);

            Assert::IsTrue(cellArray.IsConectted(1, 0, 1, 1).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(0, 0, 1, 2).IsConnected);
        }

        TEST_METHOD(testGeneralArray)
        {
            LineUpArray cellArray(4, 4, 2);
            cellArray.InitWithArray({ { 1, 0, 0, 0 },{ 0, 1, 1, 1 },{ 1, 0, 1, 0 },{ 1, 1, 0, 0 } });

            Assert::IsTrue(cellArray.IsConectted(0, 0, 1, 1).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(0, 0, 1, 2).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(0, 0, 1, 3).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(0, 0, 2, 0).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(0, 0, 3, 0).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(0, 0, 2, 2).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(0, 0, 3, 1).IsConnected);

            Assert::IsTrue(cellArray.IsConectted(1, 1, 1, 2).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(1, 1, 1, 3).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(1, 1, 2, 0).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(1, 1, 3, 0).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(1, 1, 2, 2).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(1, 1, 3, 1).IsConnected);
            ;
            Assert::IsTrue(cellArray.IsConectted(1, 2, 1, 3).IsConnected);
            Assert::IsTrue(!cellArray.IsConectted(1, 2, 2, 0).IsConnected);
            Assert::IsTrue(!cellArray.IsConectted(1, 2, 3, 0).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(1, 2, 2, 2).IsConnected);
            Assert::IsTrue(!cellArray.IsConectted(1, 2, 3, 1).IsConnected);

            Assert::IsTrue(!cellArray.IsConectted(1, 3, 2, 0).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(1, 3, 3, 0).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(1, 3, 2, 2).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(1, 3, 3, 1).IsConnected);

            Assert::IsTrue(cellArray.IsConectted(2, 0, 3, 0).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(2, 0, 2, 2).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(2, 0, 3, 1).IsConnected);

            Assert::IsTrue(cellArray.IsConectted(3, 0, 2, 2).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(3, 0, 3, 1).IsConnected);

            Assert::IsTrue(cellArray.IsConectted(2, 2, 3, 1).IsConnected);
        }
	};
}