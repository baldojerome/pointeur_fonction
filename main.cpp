#include <iostream>

using namespace std;


void permuter1(int* t, int posA, int posB){
    
    int temp = 0; 
    temp = t[posA];
    t[posA] = t[posB];
    t[posB] = temp;
}

void permuter2(int t[], int posA, int posB){
    
    int temp = 0; 
    temp = t[posA];
    t[posA] = t[posB];
    t[posB] = temp;
}

void permuter3(int& posA, int& posB){
    
    int temp =0; 
    
    temp = posA;
    posA = posB;
    posB = temp;
}

//choix sur les valeurs dans variables
//l'autre solution aurait ete de jouer avec les adresses 
//en permutant les adresses et non les valeurs
// int* temp = posA; 
void permuter4(int* posA, int* posB){
    
    int temp = *posA;    
    *posA = *posB;
    *posB = temp;
}

//simple navigation sur le tableau en incrementant l'indice 
//indice d'arrive + 1 pour prendre la valeur d'arrivee
void afficher1(int* t, int posA, int posB){
   
    cout << "AFFICHER #1 : ";
    for(int i = posA; i < posB+1 ; i++)
    {
        cout << t[i] << ", ";
    }
    cout << endl;
}

//simple navigation sur le tableau en incrementant l'indice 
//indice d'arrive + 1 pour prendre la valeur d'arrivee
void afficher2(int t[], int posA, int posB){
   
    cout << "AFFICHER #2 : ";
    for(int i = posA; i < posB+1 ; i++)
    {
        cout << t[i] << ", ";
    }
    cout << endl;
}

// la boucle while va jouer sur l'incrementation de l'adresse
// la boucle finira quand adresse incremente = adresse d'arrivee 
void afficher3(int& posA, int& posB){
    
    
    int* debut = &posA;
    int* arrivee = &posB;
    int i = 0;
    
    cout << "AFFICHER #3 : ";
    while(debut != arrivee)
    {
        cout << *(debut = debut + i) << ", "; 
        i++;
    }
    cout << endl;
}

//boucle while sur incremnetation de l'adresse de depart 
// +1 pour adresse d'arrivee afin de prendre adresse arrivee dans la boucle
void afficher4(int* posA, int* posB){
    
    int* debut = posA;
    int* arrivee = posB;
    int i = 0;
    
    cout << "AFFICHER #4 : ";
    while((debut + i) != arrivee+ 1)
    {
        cout << *(debut + i) << ", ";
        i++;
    }
    cout << endl;
}

//recherche va utiliser une boucle while pour chercher la valeur 
//condition de sortie de boucle quand valeur trouve ou fin de chaine
//verification si sortie de boucle est valeur trouvee
int* recherche(int* t, int taille, int valeur){

    int* tableau = t;
    int* adresse;
    int i = 0;
    int resultat = -1;

    while(resultat != valeur && i != taille){
        resultat = *(tableau + i);
        i++;
    }
    if (resultat == valeur){
        adresse = tableau + (i-1);
    }
    
    return adresse;
}
int main()
{
    int tableau[] = {1,3,4,5,8,7,0,2,6,9};
    
    permuter1(tableau, 2, 5);
    permuter2(tableau, 3, 6);
    permuter3(tableau[1], tableau[9]);
    permuter4(tableau + 4, tableau + 7);
    afficher1(tableau, 0, 7);
    afficher2(tableau, 2, 8);
    afficher3(*(tableau + 5), tableau[6]);
    afficher4(&tableau[3],&tableau[8]);
    int* valeur = recherche(tableau, 10, 8);
    cout << "valeur : " << *valeur << endl;
    *valeur = 10;
    afficher4(tableau, tableau+9);
    
	return 0;
}
