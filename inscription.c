#include <stdio.h>
#include <stdlib.h>

struct etudiant
{
  char nom[50];
  char prenom[50];
  char date_de_naissance[50];
  char adresse[100];
  char niveau[50];
};

struct etudiant liste[100];
int nombre_etudiant=0;

void ajouter_etudiant()
{
  if (nombre_etudiant>=100)
  {
    printf("liste_plein\n");
    return;
  }
  
  printf("nom:\n");
  scanf("%s",liste[nombre_etudiant].nom);
  printf("prenom:\n");
  scanf("%s",liste[nombre_etudiant].prenom);
  printf("date_de_naissance:\n");
  scanf("%s",liste[nombre_etudiant].date_de_naissance);
  printf("adresse:\n");
  scanf("%s",liste[nombre_etudiant].adresse);
  printf("niveau:\n");
  scanf("%s",liste[nombre_etudiant].niveau);
  
  nombre_etudiant++;
  printf("etudiant ajouté avec succès\n");
  
}

void afficher_liste()
{
  int i;
  if (nombre_etudiant==0)
  {
    printf("aucun etudiant dans la liste\n");
    return;
  }
  
  printf("liste des etudiants\n");
  
  for (i=0;i<nombre_etudiant;i++)
  {
    printf("\netudiant%d\n",i+1);
    printf("nom:%s\n",liste[i].nom);
    printf("prenom:%s\n",liste[i].prenom);
    printf("date_de_naissance:%s\n",liste[i].date_de_naissance);
    printf("adresse:%s\n",liste[i].adresse);
    printf("niveau:%s\n",liste[i].niveau);
  }
}

void trier_par_nom()
{
  int i,j;
  struct etudiant temp;
  
  for (i=0;i<nombre_etudiant-1;i++)
    {
    for (j=0;j<nombre_etudiant-i-1;j++)
      {
      
        int k=0;
        while (liste[j].nom[k] !='\0' && liste[j+1].nom[k] !='\0')
        {
          if (liste[j].nom[k] > liste[j+1].nom[k])
            {
              temp=liste[j];
              liste[j]=liste[j+1];
              liste[j+1]=temp;
              break;
            }
            else if (liste[j].nom[k]<liste[j+1].nom[k])
            {
              break;
            }
            k++;
          }
        }
      }
       printf("liste trier par nom\n");
}

void trier_par_adresse()
{
  int i,j;
  struct etudiant temp;
  
  for (i=0;i<nombre_etudiant-1;i++)
    {
    for(j=0;j<nombre_etudiant-i-1;j++)
      {
        int k=0;
        while (liste[j].adresse[k] !='\0' && liste[j+1].adresse[k])
          {
            if (liste[j].adresse[k] > liste[j+1].adresse[k])
              {
                temp=liste[j];
                liste[j]=liste[j+1];
                liste[j+1]=temp;
                break;
              }
              else if (liste[j].adresse[k]<liste[j+1].nom[k])
              {
                break;
              }
              k++;
          }
        }
      }
      printf("liste trier par adresse\n");
}

int main()
{
  ajouter_etudiant();
  afficher_liste();
  trier_par_nom();
  trier_par_adresse();
  return 0;
}
