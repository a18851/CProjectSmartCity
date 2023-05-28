/**
 * @file aluguer.h
 * @author lugon (a18851@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 2023-05-24
 * @copyright Copyright (c) 2023
 */

#ifndef ALUGUER_H
#define ALUGUER_H
#define TAMANHO 50
#include "../Meios/meio.h"
#include "../Clientes/cliente.h"

typedef struct Data{
    int ano;
    short mes;
    short dia;
} Data;

typedef struct Aluguer {
    int idCliente;
    int idMeio;
    Data data;
    char geocodigoRecolha[TAMANHO];
    struct Aluguer *proximo;
    struct Aluguer *anterior;
} Aluguer;

typedef struct Fila {
    Aluguer *inicio;
    Aluguer *fim;
} Fila;

Data getDate();
Aluguer* criarAluguer(int idCliente, char geocodigoRecolha[TAMANHO]);
Fila* inserirAluguer(Fila* filaAlugueres, Aluguer* aluguer, Meio* listaMeios, Cliente* listaClientes, bool* inserido);
Fila* importarAlugueres(const char* filename, Meio* listaMeios, Cliente* listaClientes);
void imprimirAlugueres(Fila* filaAlugueres);
bool guardarAlugueres(const char* filename, Fila* filaAlugueres);
Fila* carregarAlugueres(const char* filename, Meio* listaMeios, Cliente* listaClientes);
#endif