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
        void test2x2Array()
        {
            LineUpArray cellArray(2, 2, 2);
            cellArray.InitWithArray({ {1, 2}, { 1, 2 } });
            Assert::IsTrue(cellArray.GetCellValue(0, 0) == 1);
            Assert::IsTrue(cellArray.GetCellValue(0, 1) == 2);
            Assert::IsTrue(cellArray.GetCellValue(1, 0) == 1);
            Assert::IsTrue(cellArray.GetCellValue(1, 1) == 2);
            Assert::IsTrue(cellArray.IsConectted(0, 0, 1, 0).IsConnected);
            Assert::IsTrue(!cellArray.IsConectted(0, 0, 0, 1).IsConnected);
        }

        [TestMethod]
        void test3x2Array() {
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

        [TestMethod]
        void test3x2PartArray() {
            LineUpArray cellArray(2, 3, 2);
            cellArray.InitWithArray({ {1, 0, 0},{2, 2, 1} });

            Assert::IsTrue(!cellArray.IsConectted(0, 0, 0, 1).IsConnected);
            Assert::IsTrue(!cellArray.IsConectted(1, 0, 0, 1).IsConnected);

            Assert::IsTrue(cellArray.IsConectted(1, 0, 1, 1).IsConnected);
            Assert::IsTrue(cellArray.IsConectted(0, 0, 1, 2).IsConnected);
        }

        [TestMethod]
        void testGeneralArray() {
            LineUpArray cellArray(4, 4, 2);
            cellArray.InitWithArray({ {1, 0, 0, 0},{0, 1, 1, 1},{1, 0, 1, 0},{1, 1, 0, 0} });

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
