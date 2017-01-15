#include "file.h"

namespace files{

	
	filemedia::filemedia(){
		url = new char[1];
		strcpy(url,"");
		kbyte = 0;
		formato = new char[1];
		strcpy(formato,"");
		
	}
	
	filemedia::filemedia(const char* add, const int dim, const char* ext){
		url = new char[strlen(add)+1];
		strcpy(url,add);
		kbyte = dim;
		formato = new char[strlen(ext)+1];
		strcpy(formato,ext);
		
	}
	
	filemedia::filemedia(const filemedia & f){
		url = new char[strlen(f.url)+1];
		strcpy(url,f.url);
		kbyte = f.kbyte;
		formato = new char[strlen(f.formato)+1];
		strcpy(formato,f.formato);
		
	}
	
	filemedia filemedia::operator=(const filemedia & f){
		if(this==&f) return *this;
		if(url) delete[] url;
		set_url(f.get_url());
		kbyte = f.get_kbyte();
		if(formato) delete[] formato;
		set_formato(f.get_formato());
		
		return *this;
		
	} 
	
	void filemedia::set_url(const char* add){
		if(url) delete [] url;
		url = new char [strlen(add)+1];
		strcpy(url,add);
		
	}
	
	void filemedia::set_kbyte(const int dim){
		kbyte = dim;
		
	}
	
	void filemedia::set_formato(const char* form){
		if(formato) delete [] formato;
		formato = new char [strlen(form)+1];
		strcpy(formato,form);
		
	}
	
	void filemedia::print(ostream & of)const{
		of << url << ' ' << kbyte << ' ' << formato << ' ';
		
	}
	
	ostream & operator<<(ostream & of, const filemedia & f){
		f.print(of);
		return of;
		
	}
	
	void filemedia::read(istream & in){
		char buffer[800];
		int dim;
		in.getline(buffer,799);
		set_url(buffer);
		in >> dim;
		set_kbyte(dim);
		in.ignore();
		in.getline(buffer,799);
		set_formato(buffer);
		
	}
	
	istream & operator>>(istream & in, filemedia & f){
		f.read(in);
		return in;
		
	}
	
	filemedia::~filemedia(){
		delete [] url;
		delete [] formato;
	}
	
	
	
	
	
	
	
	
	
	
} //files
