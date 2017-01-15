#include "video.h"

using namespace std;

namespace files{
	
	video::video() : filemedia(){
		autore=new char [1];
		strcpy(autore,"");
		soggetto=new char[1];
		strcpy(soggetto,"");
		data=new char [1];
		strcpy(data,"");
		
	}
	
	video::video(const char* add, const int dim, const char* form, const char* aut, const char* sog, const char* dat) : filemedia(add,dim,form){
		autore = new char [strlen(aut)+1];
		strcpy(autore,aut);
		soggetto=new char [strlen(sog)+1];
		strcpy(soggetto,sog);
		data=new char[strlen(dat)+1];
		strcpy(data,dat);
		
	}
	
	video::video(const video & v) : filemedia(v){
		autore = new char [strlen(v.autore)+1];
		strcpy(autore,v.autore);
		soggetto=new char [strlen(v.soggetto)+1];
		strcpy(soggetto,v.soggetto);
		data=new char[strlen(v.data)+1];
		strcpy(data,v.data);
		
	}
	
	
	void video::set_aut(const char* aut){
		if(autore) delete [] autore;
		autore = new char[strlen(aut)+1];
		strcpy(autore,aut);
		
	}
	
	void video::set_sog(const char* sog){
		if(soggetto) delete [] soggetto;
		soggetto = new char[strlen(sog)+1];
		strcpy(soggetto,sog);
		
	}
	
	void video::set_data(const char* dat){
		if (data) delete [] data;
		data = new char [strlen(dat)+1];
		strcpy(data,dat);
	}
	
	void video::print(ostream & of)const{
		filemedia::print(of);
		of << autore << ' ' << soggetto << ' ' << data << ' ';
		
	}
	
	void video::read(istream & in){
		filemedia::read(in);
		char buffer [800];
		in.getline(buffer,799);
		set_aut(buffer);
		in.getline(buffer,799);
		set_sog(buffer);
		in.getline(buffer,799);
		set_data(buffer);
		
	}
	
	ostream & operator<<(ostream & of, const video & v){
		v.print(of);
		return of;
		
	}
	
	istream & operator>>(istream & in, video & v){
		v.read(in);
		return in;
		
	}
	
	
	video::~video(){
		delete [] autore;
		delete [] soggetto;
		delete [] data;
		
	}
	
	
	
	
	
} //files
