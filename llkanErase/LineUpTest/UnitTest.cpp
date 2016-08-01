#include "stdafx.h"
#include "../llkanErase/LineUp.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace LineUpTest
{
	[TestClass]
	public ref class LineUpTest
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///获取或设置测试上下文，该上下文提供
		///有关当前测试运行及其功能的信息。
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		// 编写测试时，可以使用以下附加特性: 
		//
		// 在运行类中的第一个测试之前使用 ClassInitialize 运行代码
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		// 在类中的所有测试都已运行之后使用 ClassCleanup 运行代码
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//在运行每个测试之前，使用 TestInitialize 来运行代码
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//在每个测试运行完之后，使用 TestCleanup 来运行代码
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

		[TestMethod]
		void CellTest()
		{
            Cell cell = Cell();
            Assert::IsTrue(cell.isNull);

            cell = Cell(1, 2);
            Assert::AreEqual(1, cell.col);
            Assert::AreEqual(2, cell.row);
		};
		    [TestMethod]
    void test2x2Array() {
        cellArray = CellArray(col: 2, row: 2, shapes: 2)
        cellArray.initWithrray([[1, 2], [1, 2]])
        Assert::IsTrue(cellArray.getCellValue(0, row: 0) == 1)
        Assert::IsTrue(cellArray.getCellValue(0, row: 1) == 2)
        Assert::IsTrue(cellArray.getCellValue(1, row: 0) == 1)
        Assert::IsTrue(cellArray.getCellValue(1, row: 1) == 2)
        Assert::IsTrue(cellArray.isConectted(0, row1: 0, col2: 1, row2: 0).isConnected)
        Assert::IsTrue(!cellArray.isConectted(0, row1: 0, col2: 0, row2: 1).isConnected)
    }
    
    [TestMethod]
    void test3x2Array() {
        cellArray = CellArray(col: 2, row: 3, shapes: 2)
        cellArray.initWithrray([[1, 2, 2], [2, 1, 2]])
        
        Assert::IsTrue(cellArray.getCellValue(0, row: 0) == 1)
        Assert::IsTrue(cellArray.getCellValue(0, row: 1) == 2)
        Assert::IsTrue(cellArray.getCellValue(0, row: 2) == 2)
        Assert::IsTrue(cellArray.getCellValue(1, row: 0) == 2)
        Assert::IsTrue(cellArray.getCellValue(1, row: 1) == 1)
        Assert::IsTrue(cellArray.getCellValue(1, row: 2) == 2)
        Assert::IsTrue(cellArray.isConectted(0, row1: 1, col2: 0, row2: 2).isConnected)
        Assert::IsTrue(cellArray.isConectted(1, row1: 0, col2: 1, row2: 2).isConnected)
        Assert::IsTrue(!cellArray.isConectted(0, row1: 0, col2: 1, row2: 1).isConnected)
    }

    [TestMethod]
    void test3x2PartArray() {
        cellArray = CellArray(col: 2, row: 3, shapes: 2)
        cellArray.initWithrray([[1, 0, 0], [2, 2, 1]])
        
        Assert::IsTrue(!cellArray.isConectted(0, row1: 0, col2: 0, row2: 1).isConnected)
        Assert::IsTrue(!cellArray.isConectted(1, row1: 0, col2: 0, row2: 1).isConnected)
        
        Assert::IsTrue(cellArray.isConectted(1, row1: 0, col2: 1, row2: 1).isConnected)
        Assert::IsTrue(cellArray.isConectted(0, row1: 0, col2: 1, row2: 2).isConnected)
    }
    
    [TestMethod]
    void testGeneralArray() {
        cellArray = CellArray(col: 4, row: 4, shapes: 2)
        cellArray.initWithrray([[1, 0, 0, 0], [0, 1, 1, 1], [1, 0, 1, 0], [1, 1, 0, 0]])
        
        Assert::IsTrue(cellArray.isConectted(0, row1: 0, col2: 1, row2: 1).isConnected)
        Assert::IsTrue(cellArray.isConectted(0, row1: 0, col2: 1, row2: 2).isConnected)
        Assert::IsTrue(cellArray.isConectted(0, row1: 0, col2: 1, row2: 3).isConnected)
        Assert::IsTrue(cellArray.isConectted(0, row1: 0, col2: 2, row2: 0).isConnected)
        Assert::IsTrue(cellArray.isConectted(0, row1: 0, col2: 3, row2: 0).isConnected)
        Assert::IsTrue(cellArray.isConectted(0, row1: 0, col2: 2, row2: 2).isConnected)
        Assert::IsTrue(cellArray.isConectted(0, row1: 0, col2: 3, row2: 1).isConnected)

        Assert::IsTrue(cellArray.isConectted(1, row1: 1, col2: 1, row2: 2).isConnected)
        Assert::IsTrue(cellArray.isConectted(1, row1: 1, col2: 1, row2: 3).isConnected)
        Assert::IsTrue(cellArray.isConectted(1, row1: 1, col2: 2, row2: 0).isConnected)
        Assert::IsTrue(cellArray.isConectted(1, row1: 1, col2: 3, row2: 0).isConnected)
        Assert::IsTrue(cellArray.isConectted(1, row1: 1, col2: 2, row2: 2).isConnected)
        Assert::IsTrue(cellArray.isConectted(1, row1: 1, col2: 3, row2: 1).isConnected)

        Assert::IsTrue(cellArray.isConectted(1, row1: 2, col2: 1, row2: 3).isConnected)
        Assert::IsTrue(!cellArray.isConectted(1, row1: 2, col2: 2, row2: 0).isConnected)
        Assert::IsTrue(!cellArray.isConectted(1, row1: 2, col2: 3, row2: 0).isConnected)
        Assert::IsTrue(cellArray.isConectted(1, row1: 2, col2: 2, row2: 2).isConnected)
        Assert::IsTrue(!cellArray.isConectted(1, row1: 2, col2: 3, row2: 1).isConnected)

        Assert::IsTrue(!cellArray.isConectted(1, row1: 3, col2: 2, row2: 0).isConnected)
        Assert::IsTrue(cellArray.isConectted(1, row1: 3, col2: 3, row2: 0).isConnected)
        Assert::IsTrue(cellArray.isConectted(1, row1: 3, col2: 2, row2: 2).isConnected)
        Assert::IsTrue(cellArray.isConectted(1, row1: 3, col2: 3, row2: 1).isConnected)

        Assert::IsTrue(cellArray.isConectted(2, row1: 0, col2: 3, row2: 0).isConnected)
        Assert::IsTrue(cellArray.isConectted(2, row1: 0, col2: 2, row2: 2).isConnected)
        Assert::IsTrue(cellArray.isConectted(2, row1: 0, col2: 3, row2: 1).isConnected)

        Assert::IsTrue(cellArray.isConectted(3, row1: 0, col2: 2, row2: 2).isConnected)
        Assert::IsTrue(cellArray.isConectted(3, row1: 0, col2: 3, row2: 1).isConnected)

        Assert::IsTrue(cellArray.isConectted(2, row1: 2, col2: 3, row2: 1).isConnected)
    }
	};
}
