#include <iostream>
#include "include/view.h" // Solo llamamos a la vista.

// No incluímos el sort.h ni el search.h ya que aquí el main no hace el trabajo, la función iniciarSistema() de view.cpp es la que se encarga de llamar a los métodos necesarios, manteniendo el main limpio y enfocado solo en iniciar el sistema. La vista se encarga de toda la interacción y lógica de negocio, siguiendo el modelo orientado a objetos
using namespace std;

int main() {
	iniciarSistema(); // Llamamos a la función que inicia el sistema, la cual se encuentra en view.cpp
	return 0;
}