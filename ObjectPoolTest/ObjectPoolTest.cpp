#include "pch.h"
#include "CppUnitTest.h"
#include "../DoubleLinkedList/ObjectPool.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace ObjectPoolTest
{
	TEST_CLASS(ObjectPoolTest)
	{
	public:
		class Critter;

		TEST_METHOD(DefaultConstructor)
		{
		
			
			ObjectPool<int*> objectPool = ObjectPool<int*>(100, []() {return new int; });
			
		}

		TEST_METHOD(Disable)
		{
		}

		TEST_METHOD(Release)
		{

		}

		TEST_METHOD(Clear)
		{
		}

		TEST_METHOD(Get)
		{
		}

		TEST_METHOD(CountActive)
		{

		}

		TEST_METHOD(CountInactive)
		{
		}


		TEST_METHOD(CountAll)
		{
		}





	};
}
