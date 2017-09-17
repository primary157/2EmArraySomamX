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
void initClosedAdressingHash(ClosedAdressingHashTable** t,int M){
	*t = (ClosedAdressingHashTable *)malloc(sizeof(ClosedAdressingHashTable));
	initHash(&(*t)->table,M);
	(*t)->pesos = (unsigned int *)malloc(sizeof(unsigned int));		//Primeira posicao vetor possui o tamanho do vetor
	(*t)->pesos[0] = 0;
}
void addItem(ClosedAdressingHashTable *t, Item item){
	int hash = 0;
	hash = item.chave % t->table->sz;
	if(t->table->itens[hash].dados.chave != -1){
		antiColisoes(&t->table->itens[hash],item);	//Campo possui item
		return;
	}
	t->table->itens[hash].dados = item;	//Se Campo estiver vazio
	t->table->itens[hash].prox = NULL;
}
void antiColisoes(ListaEncadeada *i,Item item){
	if(i->prox == NULL){
		ListaEncadeada_Insere(&(i->prox), item);
		return;
	}
	antiColisoes(i->prox, item);
}
