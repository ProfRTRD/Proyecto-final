#include <iostream>    
#include <algorithm>    // std::count
#include <vector>       
#include <string>
#include <fstream> 


//La lógica empleada para desarrollar este punto, será: Tener en un solo string el documento leído. Posteriormente, con un auto for revisar letra por letra si ya está en el vector de letras contadas; si no lo está, se añade la letra al vector y se cuenta cuántas veces aparece la letra en el string, luego esa cuenta se añade en otro vector que lleva el conteo.

int after(std::string & str);
int main(){
std::ifstream myfile;
  std::ofstream fout("Occurences.txt"); // Crear el documento en que vamos a añadir el texto modificado
  myfile.open("Documento de prueba.txt"); // Abrimos el documento que vamos a leer.
  std::string myline;  // creamos un string vacío.
  std::string total;
  if (myfile.is_open()) { // verificamos que el documento esté abierto
    while (myfile) { // Va a leer desde el inicio hasta el fin del documento
      std::getline(myfile, myline); // el string ahora toma el valor del primer renglón del documento que le pasamos
      total += myline;
      std::cout << total << '\n'; // verificación de lo dicho anteriormente
}
    std::cout << after(total);
    }
  }





int after(std::string & str){
  std::vector<std::string> container;
  std::vector<int> appearence;
  
  for(auto x: str){
    int sum = 0;
    if (find(container.begin(), container.end(), x) != container.end()) {
      container.emplace_back(x);
      for (auto letter: str) {
        if (x==letter){
          sum+=1;
        }
      }
      appearence.emplace_back(sum);
    }
  }

  for(int i = 0; container.size();i++){
    std::cout << "El número de veces que " << container[i] << " aparece son: " << appearence[i] <<"\n";
  }
  
  return 0;
}

  
