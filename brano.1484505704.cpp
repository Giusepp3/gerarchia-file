#include "brano.h"

using namespace std;

namespace files{
	
	branomusic::branomusic() : filemedia(){
		brano = new char [1];
		strcpy(brano,"");
		interprete = new char [1];
		strcpy(interprete,"");
		durata = 0.0;
		
	}
	
	branomusic::branomusic(const char* add, const int dim, const char* form, const char* br, const char* interp,const float time) : filemedia(add,dim,form){
		brano = new char [strlen(br)+1];
		strcpy(brano,br);
		interprete = new char [strlen(interp)+1];
		strcpy(interprete,interp);
		durata = time;
		
	}
	
	branomusic::branomusic(const branomusic & b) : filemedia (b){
		brano = new char [strlen(b.brano)+1];
		strcpy(brano,b.brano);
		interprete = new char [strlen(b.interprete)+1];
		strcpy(interprete,b.interprete);
		durata = b.durata;
	}
	
	
	
	branomusic::~branomusic(){
		delete [] brano;
		delete [] interprete;
		
	}
	
	
	void branomusic::print(ostream & of)const{
		filemedia::print(of);
		of << brano << ' ' << interprete << ' ' << durata << ' ';
		
	}
	
	void branomusic::read(istream & in){
		filemedia::read(in);
		char buffer [800];
		float time;
		in.getline(buffer,799);
		set_brano(buffer);
		in.getline(buffer,799);
		set_interp(buffer);
		in >> time;
		set_durata(time);
		
	}
	
	void branomusic::set_durata(const float time){
		durata = time;
	}
	
	void branomusic::set_brano(const char* br){
		if (brano) delete [] brano;
		brano = new char [strlen(br)+1];
		strcpy(brano,br);
	}
	
	void branomusic::set_interp(const char * interp){
		if(interprete) delete [] interprete;
		interprete = new char [strlen(interp)+1];
		strcpy(interprete,interp);
	}
	
	
	
	branomusic branomusic::operator=(const branomusic & b){
		if(this==&b) return *this;
		set_url(b.get_url());
		set_kbyte(b.get_kbyte());
		set_formato(b.get_formato());
		set_brano(b.get_brano());
		set_interp(b.get_interp());
		set_durata(b.get_durata());
		return *this;
		
	}
	
	ostream & operator<<(ostream & of, const branomusic & b){
		b.print(of);
		return of;
	}
	
	istream & operator>>(istream & in, branomusic & b){
		b.read(in);
		return in;
	}
	
	
	
	
	
	
} //files
