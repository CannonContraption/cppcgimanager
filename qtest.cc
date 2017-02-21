#include"getquery.cpp"

int main(){
	int result = cgim::parsekvstrings(true);
	for(int i = 0; i<cgim::kvpaircount; i++){
		std::cout<<"                    "<<cgim::kvpairs[i].value<<"\r";
		std::cout<<cgim::kvpairs[i].key<<std::endl;
	}
}
