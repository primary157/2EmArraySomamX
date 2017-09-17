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

#include "buscacomhash.h"

int buscaHash(HashTable *h, int x){
    return h->itens[x].dados.valor;//at(h,x);
}
int buscaHashDeVetor(HashTable *h, int *entrada, int sz, int x){
    int it;
    for(int i = 0; i < sz; i++){
        it = buscaHash(h,x-entrada[i]);
        if(it != -1) return it;
    }
    return -1;
}
int criaHashEBusca(int **entrada, int sz, int x){
    ClosedAdressingHashTable *t;
	initClosedAdressingHash(&t,sz);
    for(int i = 0; i < sz; i++)   addItem(t,(Item){i,(*entrada)[i]});
    return buscaHashDeVetor(t->table,*entrada,sz,x);
}
