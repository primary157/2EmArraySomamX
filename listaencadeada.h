/*
 * <one line to give the library's name and an idea of what it does.>
 * Copyright (C) 2017  Victor Guerra Veloso <victorgvbh@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include <stdlib.h>
// Renomeamos o tipo vetor de chars para tornar mais intuitivo o uso deste
typedef int Chave;
//Estrutura responsável por armazenar informações usadas em nossa implementação
typedef struct{
	int valor;
	Chave chave;
} Item;
//Estrutura da Lista encadeada
typedef struct _ListaEncadeada{
	struct _ListaEncadeada *prox;
	Item dados;
} ListaEncadeada;
// Funcao inicializadora da estrutura
void initListaEncadeada(ListaEncadeada **lista, int M);
// Funcao de adicao de itens na lista
void ListaEncadeada_Insere(ListaEncadeada **lista, Item item);

#endif // LISTAENCADEADA_H
