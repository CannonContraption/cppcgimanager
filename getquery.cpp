#ifndef _GLIBCXX_IOSTREAM
#include<iostream>
#endif

#ifndef _GLIBCXX_CSTDLIB
#include<cstdlib>
#endif

namespace cgim{
	std::string getqstring(){
		std::string querytype = getenv("REQUEST_METHOD");
		std::string query;
		if(querytype == "GET"){
			query = getenv("QUERY_STRING");
		} else {
			std::string qsection;
			std::cin>>query;
			while(!std::cin.fail()){
				std::cin>>qsection;
				query+=" "+qsection;
			}
		}
		return query;
	}
}
