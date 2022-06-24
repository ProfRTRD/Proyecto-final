#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
std::string separator(std::string s);

int main() {
  std::ifstream myfile;
  std::ofstream fout("Decoded.txt"); // Crear el documento en que vamos a añadir
                                     // el texto modificado
  myfile.open("Documento de prueba.txt"); // Abrimos el documento que vamos a leer.
  std::string myline;          // creamos un string vacío.
  if (myfile.is_open()) {      // verificamos que el documento esté abierto
    while (myfile) { // Va a leer desde el inicio hasta el fin del documento
      std::getline(myfile, myline); // el string ahora toma el valor del primer
                                    // renglón del documento que le pasamos
      std::cout << myline << '\n';  // verificación de lo dicho anteriormente
      fout <<separator(myline);
    }
  } else { // se ejecuta sólo si el documento no está abierto
    std::cout << "Couldn't open file\n";
  }
  return 0;
}

std::string separator(std::string s) {
  std::string str_returner;
  std::vector<std::string> Word_container;
  std::stringstream ss(s);
  std::string word;
  while (ss >> word) {
    Word_container.push_back(word);
  }
  for (auto x : Word_container) {
    str_returner += x[0];
  };
  return str_returner;
}