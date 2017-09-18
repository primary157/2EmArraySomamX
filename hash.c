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

#include "hash.h"
//Array de numeros primos uteis para se calcular tamanho da tabela Hash
void initHash(HashTable** t,int M){
	*t = (HashTable*)malloc(sizeof(HashTable));
	(*t)->sz = M;
	initListaEncadeada(&(*t)->itens,M);
	for (int i = 0; i < M; i++) {
		(*t)->itens[i].prox = NULL;
		(*t)->itens[i].dados.chave = -1;
	}
}

int search(HashTable* t, unsigned int Chave){ //Retorna 1 caso matricula seja encontrada, 0 caso nao esteja na lista
	int hash = Chave % t->sz, hash_tam = t->sz;
	ListaEncadeada* ptr = &t->itens[hash];
	while(ptr != NULL && Chave != ptr->dados.chave){
		ptr = ptr->prox;	//Campo possui item
	}
	return ptr == NULL;
}
void addItem(HashTable *t, Item item){
	int hash = item.chave % t->sz;
	if(t->itens[hash].dados.chave != -1){
		ListaEncadeada_Insere(&t->itens[hash].prox,item);	//Campo possui item
		return;
	}
	t->itens[hash].dados = item;	//Se Campo estiver vazio
	t->itens[hash].prox = NULL;
}
