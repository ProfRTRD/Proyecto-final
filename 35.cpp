//Terminado, funciona------------
#include <iostream>
#include <string>
#include <fstream>


void coder(std::string &st, std::string & k, int s);

int main (void){
  
  std::ifstream myfile; 
  myfile.open("35.input.txt");
  std::string tex,ntex;
  std::string key="qawsderftgyhujikolpmnbvczx";
  int size=25;

  while(myfile){ 
   ntex+=tex;
   std::getline(myfile, tex);
  }

 coder(ntex,key,size);
  
  std::cout <<"ENCRYPTION FINISH IT"; 
  myfile.close();
  return 0;
}


//------  Coder -----------
void coder(std::string &st, std::string &k,int s){
 std::string encrypted;
 std::ofstream fout("35.output.txt"); //imprimir aquí
  
 for(auto letter: st){ 
//------------ Cambia de Mayúscula a minúscula ------------  
      if(65<=letter && letter<= 90){
         letter = letter + 32;}

//--------------- Hace la codificación --------------      
    if(97<=letter && letter <= 122){
      for(int i = 0; i<=s; i++){//iterador
        
        if(letter == i + 97){ // Busca posicion 
          letter = k[i]; //la cambia
          encrypted =+letter; //agrega nueva letra
          fout<<encrypted; //imprime nuevo tex
          break; }   
        
      }
     }
//-------------- Espacio para cualquier otro -----------
    else{fout<<" "; }
  }
}


