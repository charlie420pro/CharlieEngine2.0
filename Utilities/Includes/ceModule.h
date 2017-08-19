#pragma once

namespace ceEngineSDK
{

	template<class T>
	class CE_UTILITY_EXPORT Module
	{
	public:

		static T& Instance()
		{
			if (IsShutDown())
			{
				CE_EXCEPT(internalErrorException, "Tryung to access a module but it hasn't been started up yet.");
			}
			if (IsDestroyed())
			{
				CE_EXCEPT(internalErrorException, "Trying to access a destroyed module.");
			}
			return *_Instance();
		}

		static T* InstancePtr()
		{
			if (IsShutDown())
			{
				CE_EXCEPT(internalErrorException, "Tryung to access a module but it hasn't been started up yet.");
			}
			if (IsDestroyed())
			{
				CE_EXCEPT(internalErrorException, "Trying to access a destroyed module.");
			}
			return _Instance();
		}

		template<class... Args>
		static void StartUp(Args&&... args)
		{
			if (!IsShutDown())
			{
				CE_EXCEPT(internalErrorException, "Trying to start an already started module.");
			}
			_Instance() = ce_new<T>(std::forward<Args>(args)...);
			IsShutDown() = false;
			((Module*)_Instance())->OnStartUp();
		}

		template<class SubType, class... Args>
		static void StartUp(Args&&... args)
		{
			static_assert(std::is_base_of<T, SubType>::value, "Provided type is not derived from type the Module is initialized with.");
			if (!IsShutDown())
			{
				CE_EXCEPT(internalErrorException, "Trying tostart an already started module.");
			}
			_Instance() = ce_new<SubType>(std::forward<Args>(args)...);
			IsShutDown() = false;

			((Module*)_Instance())->OnStartUp();
		}

		static void ShutDown()
		{
			if (IsShutDown() || IsDestroyed())
			{
				CE_EXCEPT(internalErrorException, "Trying tostart an already shut down module.");
			}
			((Module*)_Instance())->OnShutDown();

			ce_delete(_Instance());
			IsShutDown() = true;
		}

		static bool IsStarted()
		{
			return !IsShutDown() && !IsDestroyed();
		}

	protected:
		Module()
		{
		}

		virtual ~Module()
		{
			_Instance() = nullptr;
			IsDestroyed() = true;
		}

		Module(const Module&)
		{

		}

		Module& operator=(const Module&)
		{
			return *this;
		}

		virtual void OnShutDown()
		{

		}

		virtual void OnStartUp()
		{

		}

		static T*& _Instance()
		{
			static T* inst = nullptr;
			return inst;
		}

		static bool& IsDestroyed()
		{
			static bool inst = false;
			return inst;
		}

		static bool& IsShutDown()
		{
			static bool inst = true;
			return inst;
		}

	};
}