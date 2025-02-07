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
			list.pushBack(1);

			Assert::AreEqual(1, list.first());
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(1, list.getLength());

			list.pushBack(2);

			Assert::AreEqual(1, list.first());
			Assert::AreEqual(2, list.last());
			Assert::AreEqual(2, list.getLength());

			list.pushBack(3);

			Assert::AreEqual(1, list.first());
			Assert::AreEqual(2, *(list.begin()++));
			Assert::AreEqual(3, list.last());
			Assert::AreEqual(3, list.getLength());
		}

		TEST_METHOD(PushBack)
		{


			List<int> list = { 1,2 };

			list.pushBack(11);

			Assert::AreEqual(11, list.last());
			Assert::AreEqual(1, *(list.begin()));
			
			list.pushBack(-5);
			Assert::AreEqual(-5, list.last());
			
			list.remove(list.last());
			Assert::AreEqual(11, list.last());



		}

		TEST_METHOD(PopFront)
		{
			List<int> list = { 2, 6, 5, 1 };
			list.popFront();

			Assert::AreEqual(6, *(list.begin()));
			list.pushFront(3);
			list.popFront();
			Assert::AreEqual(6, *(list.begin()));


			



		}

		TEST_METHOD(PopBack)
		{
			List<int> list = { -2, -4, -2, 12, 122 };

			list.popBack();

			Assert::AreEqual(12, list.last());

			list.popBack();
			Assert::AreEqual(*(list.begin()), list.last());
			list.pushBack(1000000000);
			list.popBack();
			Assert::AreEqual(*(list.begin()), list.last());

		}
	
		TEST_METHOD(Erase)
		{
			List<int> list = { 2,5,6,1,-4 };

			list.remove(-4);

			Assert::AreEqual(1, list.last());

			list.remove(2);

			Assert::AreNotEqual(list.last(), list.first());
			


		}

		TEST_METHOD(Remove)
		{
			List<int> list = { 3 ,6 ,6 ,6 ,3 };

			list.remove(6);

			Assert::AreEqual(list.first(), list.last());
			
			

				

		}

		TEST_METHOD(Insert)
		{
			List<int> list = { 1,2 };

			list.insert(1, 1);
			
			Assert::AreEqual(3, list.getLength());
			Assert::AreEqual(1, list.last());

			list.insert(2,2);

			Assert::AreEqual(2, list.last());

			list.insert(-10000, 3);

			Assert::AreEqual(-10000, list.last());
			

			

		}

		TEST_METHOD(Begin)
		{
			List <int> list = { 1,2,3,4 };

			Assert::AreEqual(1, *(list.begin()));
		}

		
		


	};
}
