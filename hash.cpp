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

void initHash(HashTable** t,int M){
	*t = (HashTable*)malloc(sizeof(HashTable));
	(*t)->sz = M;
	for (int i = 0; i < M; i++) {
        initListaEncadeada((*t)->itens);
    }
}

Item at(HashTable *h, int pos){
    ListaEncadeada *le = h->itens[pos%h->sz];
    while(le->dado.Chave != pos){
        if(le->prox != NULL) le = le->prox;
        else return (Item){-1,-1};
    }
    return le->dado;
}

void insereHash(HashTable *h, Item it){
    ListaEncadeada_Insere(h->itens[it.Chave%h->sz],it);
}
