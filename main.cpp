#include <iostream>
#include "window.h"

int main(){
	Window window;
	try{
		window.init();
		window.run();
	}catch(std::string s){
		std::cerr << "Exception: " << s << std::endl;
	}

	return 0;
}
