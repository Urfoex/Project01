#ifndef SAVE_PTR_H
#define SAVE_PTR_H

#include <functional>
#include <iostream>

namespace ext{

	template<typename T>
		class save_ptr{
			public:
				save_ptr() = delete;
				//explicit save_ptr()
					//: m_ptr( new T())
					//, m_deleter([](T* ptr){ delete ptr;})
				//{
					//std::clog << "Save_ptr constructor\n";
				//}

				~save_ptr(){
					std::clog << "Save_ptr destructor " << m_ptr << "\n";
					m_deleter(m_ptr);
					m_ptr = nullptr;
				}
				explicit save_ptr( std::nullptr_t ptr)
					: m_ptr(ptr)
					, m_deleter([](T*){})
					{
						std::clog << "Save_ptr nullptr\n";
					}

				explicit save_ptr(
						std::function<T*(void)> creater, 
						std::function<void(T*)> deleter = [](T *ptr){ delete ptr; })
					: m_ptr(creater())
					, m_deleter(deleter)
					{
						std::clog << "Save_ptr function\n";
					}

				save_ptr( save_ptr *save_ptr) = delete;
				save_ptr( save_ptr &save_ptr) = delete;
				save_ptr( save_ptr &&save_ptr) = delete;
				//explicit save_ptr( save_ptr &sptr)
					//: m_ptr( sptr.m_ptr)
					//, m_deleter( sptr.m_deleter)
					//{
						//std::clog << "Save_ptr copy-constructor\n";
					//}

				void operator=(save_ptr &&other){
					std::clog << m_ptr << " vs " << other.m_ptr << std::endl;
					
					m_deleter(m_ptr);

					m_ptr = other.m_ptr;
					m_deleter = other.m_deleter;					
					other.m_ptr = nullptr;
					
					std::clog << "Save_ptr operator=\n";
					//return *this;

				
				}

				T *get(){ return m_ptr; }
			protected:
			private:
				T *m_ptr;
				std::function<void(T*)> m_deleter;

		};

}
#endif
