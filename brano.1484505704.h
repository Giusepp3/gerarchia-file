#ifndef BRANO_H
#define BRANO_H
#include <iostream>
#include <cstring>
#include <fstream>
#include "file.h"

using namespace std;

namespace files{
	
	class branomusic : public filemedia{
		private:
			char* brano;
			char* interprete;
			float durata;
		protected:
			void set_brano(const char*);
			void set_interp(const char*);
			void set_durata(const float);
			virtual void print(ostream & of)const;
			virtual void read(istream & in);
		
		public:
			branomusic();
			branomusic(const char*, const int, const char*, const char*, const char*, const float);
			virtual ~branomusic();
			branomusic(const branomusic &);
			branomusic operator=(const branomusic &);
			char* get_brano()const{return brano;}
			char* get_interp()const{return interprete;}
			float get_durata()const{return durata;}
			friend ostream & operator<<(ostream & of, const branomusic &);
			friend istream & operator>>(istream & in, branomusic &);
			
		
		
	};
	
	
	
	
	
	
	
	
	
} //files


#endif //BRANO_H
