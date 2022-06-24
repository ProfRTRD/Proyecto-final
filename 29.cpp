// clang-format -i main.cpp
#include <bits/stdc++.h> //librería que permite cambiar de letras a Mayúsculas y Minúsculas.
#include <fstream> //librería que permite crear, escribir y leer en documentos.
#include <iostream>
#include <map>    // librería para usar el diccionario
#include <string> //librearía que permite el uso de strings

std::string codyfier(std::string &str);
std::string getter(std::string &st);

int main() {
  std::ifstream myfile;
  std::ofstream fout("Coded.txt"); // Crear el documento en que vamos a añadir el texto modificado
  myfile.open("Documento de prueba.txt"); // Abrimos el documento que vamos a leer.
  std::string myline;  // creamos un string vacío.
  if (myfile.is_open()) { // verificamos que el documento esté abierto
    while (myfile) { // Va a leer desde el inicio hasta el fin del documento
      std::getline(myfile, myline); // el string ahora toma el valor del primer renglón del documento que le pasamos
      std::cout << myline << '\n'; // verificación de lo dicho anteriormente
      fout << codyfier(myline); // invocación de la función codyfier, y adición  de su resultado a nuestro documento donde estamos escribiendo la codificación.
    }
  } else { // se ejecuta sólo si el documento no está abierto
    std::cout << "Couldn't open file\n";
  }
  return 0;
}

std::string codyfier(std::string &str) {

  std::string EmptyString;  // creamos un string vacío.
  for (auto letter : str) { // recorremos el string (letra por letra)que pasamos por referencia. Recuerden que dicho string corresponde a un renglón entero del .txt
   
    std::string new_letter = getter(letter);// invocamos a la función getter, la cual nos daría una letra codificada.
   EmptyString += new_letter; // Añadimos la letra modificada al string que creamos al inicio.
  }
  return EmptyString; // retornamos el string codificado
}

std::string getter(std::string &st) {
  std::map<std::string, std::string> Changer; // Creación del diccionario
  std::string StrReturner; // Creación del string que retornaremos
  Changer["a"] = "c";// Adición de los elementos del diccionario.
  Changer["b"] = "d";
  Changer["c"] = "e";
  Changer["d"] = "f";
  Changer["e"] = "g";
  Changer["f"] = "h";
  Changer["g"] = "i";
  Changer["h"] = "j";
  Changer["i"] = "k";
  Changer["j"] = "l";
  Changer["k"] = "m";
  Changer["l"] = "n";
  Changer["m"] = "o";
  Changer["n"] = "p";
  Changer["o"] = "q";
  Changer["p"] = "r";
  Changer["q"] = "s";
  Changer["r"] = "t";
  Changer["s"] = "u";
  Changer["t"] = "v";
  Changer["u"] = "w";
  Changer["v"] = "x";
  Changer["w"] = "y";
  Changer["x"] = "z";
  Changer["y"] = "a";
  Changer["z"] = "b";
  auto determiner = Changer.find(st); // determinador del índice en donde se encuentra la letra que estamos buscando. Si la letra no está (por ser mayúscula), entonces nos da una posición externa al diccionario ( Changer.end() )
  if (determiner != Changer.end()) { // Si la letra está en el diccionario entonces...
    StrReturner = determiner->second; // accede a los valores de su respectiva llave. Es decir, retorna la letra modificada
  } 
  else { // Si la letra no está en en diccionario es porque debe estar en mayúscula.
    transform(st.begin(), st.end(), st.begin(),::tolower); // Transformamos la letra de mayúscula a minúscula
    determiner = Changer.find(st); // Consultamos en qué índice se encuentra la letra luego de haberla transformada
    StrReturner = determiner->second; // Retorna la letra modificada
    transform(StrReturner.begin(), StrReturner.end(), StrReturner.begin(),::toupper); // Como la letra originalmente era mayúscula, entonces la letra codificada se transforma a mayúscula.
  }
  return StrReturner; // Se retorna la letra modificada
}
