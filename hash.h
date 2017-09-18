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
//USEI https://github.com/anholt/hash_table
#ifndef HASH_H
#define HASH_H
#include "listaencadeada.h"
#include <stdlib.h>
//Estrutura da tabela Hash, sem encadeamento
typedef struct{
	int sz;
	ListaEncadeada *itens;
} HashTable;
void addItem(HashTable *t, Item i);
// Funcao inicializadora da estrutura
void initHash(HashTable** t,int M);
// Funcao de busca por Item pela Chave
int searchHash(HashTable* t, unsigned int Chave);
#endif // HASH_H
