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

#include "doissomamx.h"
int doisSomamXComTimer(int **in, int sz, int x, clock_t *tempo, void sort(int**,int), int search(int**,int,int)){
    int retorno = 0;
    clock_t inicio_cpu = clock();
    retorno = doisSomamX(in,sz,x,sort,search);
    *tempo = (clock() - inicio_cpu)/(CLOCKS_PER_SEC/1000);
    return retorno;
}
int doisSomamX(int **in, int sz, int x, void sort(int**,int), int search(int**,int,int)){
    if(sort != NULL)    sort(in,sz);
    return search(in,sz,x);
}
