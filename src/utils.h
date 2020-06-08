#pragma once

#include <utility>
#include <type_traits>

namespace Game
{
	template <class T>
	struct function;

	template <class Ret, class ...Args>
	struct function<Ret(Args...)>
	{
		Ret operator()(Args... arg)
		{
			auto fn = (Ret(*)(Args...))address;
			return fn(arg...);
		}

		void operator=(void* new_address)
		{
			address = new_address;
		}

		operator void* () const
		{
			return address;
		}

	private:
		void* address {};
	};

	// ==========================================================================================

	template <typename T, typename S>
	struct method;

	template <class T, class Ret, class ...Args>
	struct method<T, Ret(Args...)>
	{
		using signature = Ret(T::*)(Args...);

		static_assert(std::is_class_v<T>, "T must be a class or struct type.");

		Ret operator()(T* instance, Args... arg)
		{
			union
			{
				void* rawAddress;
				signature address;
			} fn {};

			fn.rawAddress = address;
			return (instance->*fn.address)(arg...);
		}

		void operator=(void* new_address)
		{
			address = new_address;
		}

		operator void* () const
		{
			return address;
		}

	private:
		void* address {};
	};
}
