#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

namespace files{
	
	class filemedia{
		private:
			char* url;
			int kbyte;
			char* formato;
		protected:
			void set_url(const char*);
			void set_kbyte(const int);
			void set_formato(const char*);
			virtual void print(ostream & of)const;
			virtual void read(istream & in);
			
		public:
			filemedia();
			filemedia(const char*, const int, const char*);
			virtual ~filemedia();
			filemedia(const filemedia &);
			filemedia operator= (const filemedia &);
			char* get_url()const{return url;}
			int get_kbyte()const{return kbyte;}
			char* get_formato()const{return formato;}
			friend ostream & operator<<(ostream & of, const filemedia &);
			friend istream & operator>>(istream & in, filemedia &);
			
			//definire la funzione memorizza_dati che scrive su file di testo 
			//e la funzione salva che scrive su file binario
	};
	
	
	
	
	
	
	
	
	
	
	
} //files




#endif //FILE_H
