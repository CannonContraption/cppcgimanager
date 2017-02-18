#ifndef _GLIBCXX_IOSTREAM
#include<iostream>
#endif

#ifndef _GLIBCXX_CSTDLIB
#include<cstdlib>
#endif

namespace cgim{
	struct kvpair{
		std::string key;
		std::string value;
	};
	kvpair * kvpairs;
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
	int parsekvpairs(){
		std::string querystring = getqstring();
		bool decoding = false;
		std::string decodestring = "";
		for(char c : querystring){
			if(c == '%'){
				decoding = true;
			}
			else if(decoding){
				if((int)c > 57){
					decoding = false;
					
				}
				else decodestring+=c;
			}
			else{
				//add the character to a string
			}
		}
	}
}
