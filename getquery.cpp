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
	std::string parseencoding(){
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
	/*
	 * Return codes:
	 * 1: query string is empty
	 */
	int parsekvstrings(bool encoding){
		std::string qstring = "";
		if(encoding){
			qstring = parseencoding();
		}
		else{
			qstring = getqstring();
		}
		std::string key;
		std::string value;
		bool equals;
		int numpairs = 0;
		if(qstring != "")
			numpairs = 1;
		else
			return 1;
		for(char c: qstring){
			if(c == '&'){
				numpairs++;
			}
		}
		kvpairs = new kvpair[numpairs];
	}
}
