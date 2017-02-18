#include<cstdlib>

string cgimanager_getqstring(){
	string querytype = getenv("REQUEST_METHOD");
	string query;
	if(querytype == "GET"){
		query = getenv("QUERY_STRING");
	} else {
		string qsection;
		cin>>query;
		while(!cin.fail()){
			cin>>qsection;
			query+=" "+qsection;
		}
	}
	return query;
}
