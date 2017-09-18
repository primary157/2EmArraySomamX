from random import random
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("CoeficienteDoTamanhoDeEntrada", help="Coeficiente do Tamanho de Entrada")
coeficiente = int(parser.parse_args().CoeficienteDoTamanhoDeEntrada)

print (100000*coeficiente)
copia1 = int(random()*500000*coeficiente)
copia2 = int(random()*500000*coeficiente)
print (copia1+copia2)
print (copia1)
print (copia2)
for i in range(2,10000*coeficiente):
    print(int(random()*500000*coeficiente))
