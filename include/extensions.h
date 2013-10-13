#ifndef EXTENSIONS_H
#define EXTENSINOS_H

#include <memory>

namespace ext{

	template<typename T>
		std::shared_ptr<T> make_shared(T &&obj){
			auto ptr = std::make_shared<T>();
			*ptr = obj;
			return ptr;
		}

}
#endif
