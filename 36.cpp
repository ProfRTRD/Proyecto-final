//funciona solo si pongo lo codificado que está en 35.output.txtr en una misma columna, le voy a preguntar al profe cómo solucionar eso.
#include <fstream>
#include <iostream> // librería para imprimir
#include <map>    // librería para usar el diccionario
#include <string> //librearía que permite el uso de strings
#include <bits/stdc++.h> //para cmbiar mayusculas y minusculas

std::string decoder(std::string &str);
std::string coder(std::string &st);

int main (void){
  std::ifstream codificado;
  std::ofstream fout("decoded36.txt"); //Guarda la decodificación del archivo codificado.
   codificado.open("35.output.txt");
   std::string eachline;  // creamos un string vacío.
  if (codificado.is_open()) { // verificamos que el documento esté abierto
    while (codificado) { // Va a leer desde el inicio hasta el fin del documento
      std::getline(codificado, eachline); // el string ahora toma el valor del primer renglón del documento que le pasamos
      std::cout << eachline << "\n" <<"Decodificación terminada, revise decoded.txt" << '\n'; // verificación de lo dicho anteriormente
      fout << decoder(eachline); // invocación de la función codyfier, y adición  de su resultado a nuestro documento donde estamos escribiendo la codificación.
    }
  
  }
}

std::string decoder(std::string &str){
  std::string EmptyString;  // creamos un string vacío.
  for (auto  eachletter : str) { // recorremos el string (letra por letra)que pasamos por referencia. Recuerden que dicho string corresponde a un renglón entero del .txt
  std::string s(1,eachletter);
    //std::string s={letter};
    std::string new_letter = coder(s);// invocamos a la función getter, la cual nos daría una letra decodificada.
   EmptyString += new_letter; // Añadimos la letra modificada al string que creamos al inicio.
  }
  return EmptyString; // retornamos el string decodifica
}

std::string coder(std::string &st){
  std::map<std::string, std::string> Cambiar; // Creación del diccionario
  std::string StrReturner; // Creación del string que retornaremos
 Cambiar["q"] = "a";// Adición de los elementos del diccionario.
 Cambiar["a"] = "b";
 Cambiar["w"] = "c";
 Cambiar["s"] = "d";
 Cambiar["d"] = "e";
 Cambiar["e"] = "f";
 Cambiar["r"] = "g";
 Cambiar["f"] = "h";
 Cambiar["t"] = "i";
 Cambiar["g"] = "j";
 Cambiar["y"] = "k";
 Cambiar["h"] = "l";
 Cambiar["u"] = "m";
 Cambiar["j"] = "n";
 Cambiar["i"] = "o";
 Cambiar["k"] = "p";
 Cambiar["o"] = "q";
 Cambiar["l"] = "r";
 Cambiar["p"] = "s";
 Cambiar["m"] = "t";
 Cambiar["n"] = "u";
 Cambiar["b"] = "v";
 Cambiar["v"] = "w";
 Cambiar["c"] = "x";
 Cambiar["z"] = "y";
 Cambiar["x"] = "z";
 auto determiner = Cambiar.find(st); // determinador del índice en donde se encuentra la letra que estamos buscando. Si la letra no está (por ser mayúscula), entonces nos da una posición externa al diccionario ( Changer.end() )
  if (determiner != Cambiar.end()) { // Si la letra está en el diccionario entonces...
    StrReturner = determiner->second; // accede a los valores de su respectiva llave. Es decir, retorna la letra modificada
  } 
   else { // Si la letra no está en en diccionario es porque debe estar en mayúscula.
    transform(st.begin(), st.end(), st.begin(),::tolower); // Transformamos la letra de mayúscula a minúscula
    determiner = Cambiar.find(st); // Consultamos en qué índice se encuentra la letra luego de haberla transformada
    StrReturner = determiner->second; // Retorna la letra modificada
    transform(StrReturner.begin(), StrReturner.end(), StrReturner.begin(),::toupper); // Como la letra originalmente era mayúscula, entonces la letra codificada se transforma a mayúscula.
  }
  return StrReturner;
}