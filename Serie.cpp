#include"Serie.h"
#include<iostream>
#include<vector>
#include<bits/stdc++.h>//para hacer uso de "accumulate"
using namespace std;

Serie::Serie(string i,string no,string dur,string gen,string epi,string temp):Video{i,no,dur,gen},numero_episodios{epi},numero_temporadas{temp}{} 


void Serie::mostrar_informacion(){
cout<<"Nombre de la Serie: "<<nombre<<endl;
cout<<"Duracion: "<<duracion<<endl;
cout<<"Genero: "<<genero<<endl;
cout<<"Numero de temporadas: "<<numero_temporadas<<endl;
cout<<"Numero de episodios: "<<numero_episodios<<endl;
cout<<"Rating promedio: "<<rating<<endl<<endl<<endl;

}

bool Serie::calificar_video(){
int calificacion{0};
try{
cout<<"Por favor selecciona la calificacion deseada: "<<endl;
for(int i=1;i<=5;i++){
    cout<<"("<<i<<")"<<i<<" estrellas"<<endl;
}
cin>>calificacion;
if(calificacion != 1 && calificacion !=2 && calificacion !=3 && calificacion !=4 && calificacion !=5){
throw -1;
}
resenias.push_back(calificacion);//agregamos al vector reseñas la calificacion dada por el usuario
float suma_resenias = accumulate(resenias.begin(),resenias.end(),0); //sumamos las reseñas de la pelicula
this->rating = suma_resenias/resenias.size();//obtenemos el promedio de las reseñas
return true;
}catch(int e){
cout<<"Calificacion Invalida"<<endl;
return false;
}
}



