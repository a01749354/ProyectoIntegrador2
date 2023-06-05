#include"Pelicula.h"
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

//constructor
Pelicula::Pelicula(string i,string no,string dur,string gen): Video{i,no,dur,gen}{}



void Pelicula::mostrar_informacion(){
cout<<endl<<"ID: "<<id<<endl;
cout<<"Nombre de la Pelicula: "<<nombre<<endl;
cout<<"Duracion: "<<duracion<<endl;
cout<<"Genero: "<<genero<<endl;
cout<<"Rating promedio: "<<rating<<endl<<endl<<endl;
}

bool Pelicula::calificar_video(){
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

