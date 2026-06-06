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

void trier_par_date()
{
  int i,j;
  struct etudiant temp;
  
  for (i=0;i<nombre_etudiant-1;i++)
  {
    for (j=0;j<nombre_etudiant-i-1;j++)
    {
    int jour1,mois1,annee1;
    int jour2,mois2,annee2;
      sscanf(liste[j].date_de_naissance, "%d/%d/%d",&jour1,&mois1,&annee1);
      sscanf(liste[j+1].date_de_naissance, "%d/%d/%d",&jour2,&mois2,&annee2);
      
    int doit_echanger=0;
    
    if (annee1>annee2)
      {
      doit_echanger=1;
      }
    else if (annee1==annee2)
    {
      if (mois1>mois2)
        {
        doit_echanger=1;
        }
      else if (mois1==mois2)
      {
        if (jour1>jour2)
          {
          doit_echanger=1;
          }
        }
      }
    if (doit_echanger)
    {
      temp=liste[j];
      liste[j]=liste[j+1];
      liste[j+1]=temp;
    }
  }
}
  printf("\nliste d'etudiant trier par date de naissance\n");
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

void rechercher_nom()
{
  int i;
  char recherche_nom[50];
  int trouve=0;
  
  printf("entrer le nom à rechercher:\n");
  scanf("%s",recherche_nom);
    
  for (i=0;i<nombre_etudiant;i++)
    {
      int k=0;
      int correspond=1;
      
      while (recherche_nom[k] !='\0' && liste[i].nom[k] != '\0')
        {
          if (recherche_nom[k] != liste[i].nom[k])
            {
              correspond=0;            
              break;
            }
            k++;
          }
          if (correspond && recherche_nom[k] == '\0' && liste[i].nom[k] == '\0')
            {
              printf("\netudiant trouvé\n");
              printf("nom:%s\n",liste[i].nom);
              printf("prenom:%s\n",liste[i].prenom);
              printf("date_de_naissance:%s\n",liste[i].date_de_naissance);
              printf("adresse:%s\n",liste[i].adresse);
              printf("niveau:%s\n",liste[i].niveau);
              trouve=1;
            }
          if (!trouve)
            printf("aucun etudiant trouve");
        }
      }

void modifier_etudiant()
{
  char recherche_nom[50];
  int trouve=0;
  int i;
  
  printf("entrer le nom à rechercher:\n");
  scanf("%s",recherche_nom);
  
  for (i=0;i<nombre_etudiant;i++)
    {
      int k;
      int correspond=1;
      while (recherche_nom[k] != '\0' && liste[i].nom[k] != '\0')
        {
          if (recherche_nom[k] != liste[i].nom[k])
          {
            correspond=0;
            break;
          }
          k++;
        }
        if (correspond && recherche_nom[k] == '\0' && liste[i].nom[k] == '\0')
          {
            printf("\nmodification de l'etudiant %s\n",liste[i].nom);
            printf("nouveau nom:\n");
            scanf("%s",liste[i].nom);
            
            printf("nouveau prenom:\n");
            scanf("%s",liste[i].prenom);
            
            printf("nouveau date_de_naissance:\n");
            scanf("%s",liste[i].date_de_naissance);
            
            printf("nouveau adresse:\n");
            scanf("%s",liste[i].adresse);
            
            printf("nouveau niveau:\n");
            scanf("%s",liste[i].niveau);
            trouve=1;
            printf("modification effectue\n");
            break;
          }
        }
      if (!trouve)
        printf("etudiant non trouve\n");
    }
    
void supprimer_nom()
{
  int i,j;
  char recherche_nom[50];
  int trouve=0;
  
  
  printf("entrer le nom à supprimer\n");
  scanf("%s",recherche_nom);
  
  for (i=0;i<nombre_etudiant;i++)
  {
    int k;
    int correspond=1;
    while (recherche_nom[k] !='\0' && liste[i].nom[k] !='\0')
      {
        if (recherche_nom[k] != liste[i].nom[k])
          {
            correspond = 0;
            break;
          }
          k++;
        }
          
        if (correspond && recherche_nom[k] == '\0' && liste[i].nom[k] == '\0')
          {
            for (j=i;j<nombre_etudiant;j++)
            {
              liste[j]=liste[j+1];
            }
              nombre_etudiant--;
              trouve=1;
              printf("nom supprimer\n");
              break;
            }
          if (!trouve)
          {
            printf("aucun nom supprimer\n");
          }
        }
      }
      
void sauvegarder_fichier()
{
  int i;
  FILE *fichier;
  
  fichier=fopen("L1.txt","w");
  
  if (fichier==NULL)
    {
      printf("erreur d'ouverture\n");
      return;
    }
    
    fprintf(fichier,"%d\n",nombre_etudiant);
    for (i=0;i<nombre_etudiant;i++)
      {
        fprintf(fichier,"%s\n",liste[i].nom);
        fprintf(fichier,"%s\n",liste[i].prenom);
        fprintf(fichier,"%s\n",liste[i].date_de_naissance);
        fprintf(fichier,"%s\n",liste[i].adresse);
        fprintf(fichier,"%s\n",liste[i].niveau);
      }
        fclose(fichier);
        printf("fichier sauvegarder\n");
        printf("%d etudiant ont ete sauvegarder dans L1.txt\n",nombre_etudiant);
      }

void charger_fichier()
{
  int i;
  FILE *fichier;
  
  fichier=fopen("L1.txt","r");
  
  if (fichier == NULL)
    {
      printf("erreur d'ouverture\n");
      return;
    }
  
  fscanf(fichier,"%d",&nombre_etudiant);
  
  for (i=0;i<nombre_etudiant;i++)
    {
      fscanf(fichier,"%s",liste[i].nom);
      fscanf(fichier,"%s",liste[i].prenom);
      fscanf(fichier,"%s",liste[i].date_de_naissance);
      fscanf(fichier,"%s",liste[i].adresse);
      fscanf(fichier,"%s",liste[i].niveau);
    }
    fclose(fichier);
    printf("fichier charger\n");
  }

void afficher_menu()
{
  printf("\n menu principale \n");
  printf("1.ajouter des etudiants\n");
  printf("2.afficher la liste des etudiants\n");
  printf("3.trier par nom la liste des etudiants\n");
  printf("4.trier par date de naisssance la liste des etudiants\n");
  printf("5.trier par adresse la liste des etudiants\n");
  printf("6.rechercher le nom des etudiants\n");
  printf("7.modification des etudiants\n");
  printf("8.suppression de nom d'etudiant\n");
  printf("9.sauvegarder les fichier\n");
  printf("10.charger les fichier\n");
  printf("11.quitter\n");
  printf("votre choix:");
}

int main()
{
  int choix;
  
  printf("menu principale\n");
  do 
  {
    afficher_menu();
    scanf("%d",&choix);
    
    switch (choix)
      {
        case 1:
          ajouter_etudiant();
          break;
        case 2:
          afficher_liste();
          break;
        case 3:
          trier_par_nom();
          afficher_liste();
          break;
        case 4:
          trier_par_date();
          afficher_liste();
          break;
        case 5:
          trier_par_adresse();
          afficher_liste();
          break;
        case 6:
          rechercher_nom();
          break;
        case 7:
          modifier_etudiant();
          break;
        case 8:
          supprimer_nom();
          break;
        case 9:
          sauvegarder_fichier();
          break;
        case 10:
          charger_fichier();
          break;
        case 11:
          printf("fini\n");
          break;
        default:
          printf("choix invalide\n");
        }
      }
  while (choix!=11);
  return 0;
}
