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
			Critter* critters[50];
			ObjectPool<Critter*> objectPool = ObjectPool<Critter*>(50, []() {return new Critter; });
			//create a loop to enable all already m_disabled and for critters
			for (int i = 0; i < 50; i++)
			{
				critters[i] = new Critter();
				objectPool.Get();
				//objectPool.Disable(critters[i]);
			}
			Assert::AreEqual(50, objectPool.CountInactive());
			Assert::AreNotEqual(50, objectPool.CountActive());
			
		}

		TEST_METHOD(Release)
		{
			
			ObjectPool<Critter*> objectPool = ObjectPool<Critter*>(50, []() {return new Critter; });
		
			//assert that critters are initialized in disabled list
			Assert::AreEqual(50, objectPool.CountInactive());

			//release from inactive to active

		}

		TEST_METHOD(Clear)
		{
		
			ObjectPool<Critter*> objectPool = ObjectPool<Critter*>(50, []() {return new Critter; });
			objectPool.Clear();
			Assert::AreEqual(0, objectPool.CountAll());
		}

		TEST_METHOD(Get)
		{
			
			ObjectPool<Critter*> objectPool = ObjectPool<Critter*>(50, []() {return new Critter; });
			objectPool.Get();
			Assert::AreEqual(1, objectPool.CountActive());
			Assert::AreEqual(50, objectPool.CountAll());
		}

		TEST_METHOD(CountActive)
		{
			
			ObjectPool<Critter*> objectPool = ObjectPool<Critter*>(50, []() {return new Critter; });

			//assert that critters are initialized in disabled list
			Assert::AreEqual(50, objectPool.CountInactive());

			for (int i = 0; i < 50; i++)
			{
				objectPool.Get();
			}
			Assert::AreEqual(0, objectPool.CountInactive());
			Assert::AreEqual(50, objectPool.CountActive());
		}

		TEST_METHOD(CountInactive)
		{
			
			ObjectPool<Critter*> objectPool = ObjectPool<Critter*>(50, []() {return new Critter; });
			//critters are already in disabled list
			Assert::AreEqual(50, objectPool.CountInactive());
		}


		TEST_METHOD(CountAll)
		{

		}





	};
}
