#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include <cstring>
#include <fstream>
#include "file.h"

using namespace std;


namespace files{
	
	class video : public filemedia{
		private:
			char* autore;
			char* soggetto;
			char* data;
		protected:
			void set_aut(const char*);
			void set_sog(const char*);
			void set_data(const char*);
			virtual void print(ostream & of)const;
			virtual void read(istream & in);
		public:
			video();
			video(const char*, const int, const char*, const char*, const char*, const char*);
			virtual ~video();
			video(const video &);
			video operator=(const video &);
			char* get_aut(){return autore;}
			char* get_sog(){return soggetto;}
			char* get_data(){return data;}
			friend ostream & operator<<(ostream & of, const video &);
			friend istream & operator>>(istream & in, video &);
		
	};
	
	
	
	
	
	
	
	
	
} //files


#endif //VIDEO_H
