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
	std::string parseencoding(){ //TODO:this function isn't complete yet
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
	 * 2: miscalculated number of k/v pairs
	 */
	int parsekvstrings(bool encoding){
		std::string qstring = "";
		if(encoding){
			qstring = parseencoding();
		}
		else{
			qstring = getqstring();
		}
		std::string key = "";
		std::string value = "";
		bool writekey;
		int numpairs = 0;
		int currentpair = 0;
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
		for(char c: qstring){
			if(c == '?' || c == '&'){
				writekey = true;
				if(key != "" && currentpair < numpairs){
					kvpairs[currentpair].key = key;
					kvpairs[currentpair].value = value;
					currentpair++;
				}
				if(currentpair >= numpairs) return 2;
				key = "";
				value = "";
			}
			else if(writekey){
				key += c;
			}
			else{
				value += c;
			}
		}
		return 0;
	}
}
