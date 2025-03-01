#include "pch.h"
#include "CppUnitTest.h"
#include "../DoubleLinkedList/ObjectPool.h"
#include "../DoubleLinkedList/Critter.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace ObjectPoolTest
{
	TEST_CLASS(ObjectPoolTest)
	{
	public:
	

		TEST_METHOD(DefaultConstructor)
		{
		
			
			ObjectPool<int*> objectPool = ObjectPool<int*>(100, []() {return new int; });
			
		}

		TEST_METHOD(Disable)
		{
		}

		TEST_METHOD(Release)
		{
			Critter* critters[50];
			ObjectPool<Critter*> objectPool = ObjectPool<Critter*>(50, []() {return new Critter; });
			for (int i = 0; i < 50; i++)
			{
				critters[i] = new Critter();
			objectPool.Release(critters[i]);
			}
			//assert that critters are initialized in disabled list
			Assert::AreEqual(50, objectPool.CountInactive());

			//release from inactive to active

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
