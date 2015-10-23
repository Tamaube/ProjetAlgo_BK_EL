Ligne pour compiler le code

#!/bin/bash

if [ -d Algo_coloration ]; then 
	cd Algo_coloration 
fi


if [ -d ProjetAlgo_BK_EL ]; then 
	cd ProjetAlgo_BK_EL
fi

if [ -d Projet_BK_EL ]; then
	cd Projet_BK_EL
fi



g++ -Wall -fexceptions -g -std=c++11 -c src/comparaisonGenerate.cpp -o obj/Debug/src/comparaisonGenerate.o

g++ -Wall -fexceptions -g -std=c++11  -c src/LecteurImage.cpp -o obj/Debug/src/LecteurImage.o

g++ -Wall -fexceptions -g -std=c++11  -c src/Pixel.cpp -o obj/Debug/src/Pixel.o

g++ -Wall -fexceptions -g -std=c++11 -c src/WriteFic.cpp -o obj/Debug/src/WriteFic.o

g++ -o bin/Debug/Projet_BK_EL.exe obj/Debug/main.o obj/Debug/src/comparaisonGenerate.o obj/Debug/src/Ensemble.o obj/Debug/src/LecteurImage.o obj/Debug/src/Pixel.o obj/Debug/src/union.o obj/Debug/src/WriteFic.o obj/Debug/test/testWriteFic.o

echo " Script de compilation terminé"



Pour utiliser le programme il faut avoir un compilateur g++ ensuite il suffit de le lancer.
Le programme demandera à l'utilisateur si celui-ci souhaite fournir un fichier ou non.
Si oui il faudra entrer le chemin du fichier.
Sinon un fichier img_generate.ppm sera généré dans Projet_BK_EL

A la fin de l'execution le fichier est visible dans Projet_BK_EL/result.pbm