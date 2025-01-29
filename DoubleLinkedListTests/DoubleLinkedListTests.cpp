#include "pch.h"
#include "CppUnitTest.h"
#include "List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DoubleLinkedListTests
{
	TEST_CLASS(DoubleLinkedListTests)
	{
	public:
		
		TEST_METHOD(DefaultConstructor)
		{

			List<int> list;
			

		}

		TEST_METHOD(InitializerListConstructor)
		{

			List<int> list = { 9, 8, 7, 6, 5 };
		
			Iterator<int> iter = list.begin();

			Assert::AreEqual(*iter, 9);
			iter++;
			Assert::AreEqual(*iter, 8);
			iter++;
			Assert::AreEqual(*iter, 7);
			iter++;
			Assert::AreEqual(*iter, 6);
			iter++;
			Assert::AreEqual(*iter, 5);
			

			Assert::AreEqual(list.getLength(), 5);

		}

		TEST_METHOD(PushFront)
		{

			List<int> list;
			list.pushFront(1);
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(1, list.getLength());
			
			list.pushFront(2);
			Assert::AreEqual(2, list.first());
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(2, list.getLength());


			list.pushFront(3);
			Assert::AreEqual(3, list.first());
			Assert::AreEqual(2, *(list.begin()));
			Assert::AreEqual(1, list.last());

			
			Assert::AreEqual(3, list.getLength());



		}





	};
}
