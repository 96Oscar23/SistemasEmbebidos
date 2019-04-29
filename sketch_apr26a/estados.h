#ifndef _ESTADOS_H
#define _ESTADOS_H

#include "inicializar.h"



enum estados {
    Config, Espera,No_Conf
};

enum acciones {
    Nill, Update, Sleep
};

void estado_config();
void estado_espera();
boolean serialEven(boolean comando);
void cleanRxBuffer();
void executeCMD();

#endif
