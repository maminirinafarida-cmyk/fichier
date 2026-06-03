#include <stdio.h>
#include <stdlib.h>
  int premier (int n)
{
  if (n<2) 
  {
  return(0);
  }

  for (int i=2;i<=n-1;i++)
  {
    if (n%i==0)
    {
    return(0);
    }
  }
return(1);
}
int main ()
{
  FILE *fichier;
  int i=0;
  int n=2;
  char ligne[100];
  int j=1;
  fichier=fopen("premier.txt","w");
  
  if (fichier==NULL) 
  {
  printf("erreur d'ouverture du fichier\n");
  exit(0);
  }
  fprintf(fichier,"50 premiers nombres premiers\n");
  
  while (i<50) 
  {
    if (premier(n))
    {
    fprintf(fichier,"%d\n",n);
    i++;
    }
    n++;
  }
  fclose(fichier);
  printf("les 50 premiers nombres premiers dans premier.txt\n");
  
  fichier=fopen("premier.txt","r");
    if (fichier==NULL)
    {
    printf("erreur d'ouverture du fichier\n");
    exit (0);
    }
  
  while (fgets(ligne,100,fichier) !=NULL)
  {
    if (j%3==0)
    {
    printf("ligne %d:%s",j,ligne);
    }
    j++;
  }
  fclose(fichier);
  printf("numero de ligne divisible par 3\n");
  
  FILE *source = fopen("premier.txt","r");
  FILE *temp =fopen("temp.txt","w");
  
  if (source == NULL || temp == NULL)
    {
    printf("erreur d'ouverture des fichiers\n");
    exit(0);
    }
  int modif = 0;
  int lignemodif = 0;
  
  printf("remplacement des '5' par 'v'\n");
  
  while (fgets(ligne,100,source) != NULL)
    {
    int modifdansligne = 0;
    for(int k=0;ligne[k] != '\0'; k++)
    {
      if (ligne[k] == '5')
      {
      ligne[k] = 'v';
      modif++;
      modifdansligne++;
      }
    }
    if (modifdansligne>0)
    {
    lignemodif++;
    }
    fprintf(temp,"%s",ligne);
    }
    fclose(source);
    fclose(temp);
    
    remove("premier.txt");
    rename("temp.txt","premier.txt");
    
    printf("\n statistique \n");
    printf("nombre total de '5' remplace:%d\n",modif);
    printf("nombre de ligne modifie:%d\n",lignemodif);
    printf("remplacement termine avec succes\n");
    
    printf("\nnombre de caratere\n");
    fichier =fopen("premier.txt","r");
    
    if (fichier == NULL)
    {
    printf("erreur d'ouverture du fichier\n");
    exit(0);
    }
    int totalcaractere=0;
    char c;
    
    while((c=fgetc(fichier)) !=EOF)
    {
    totalcaractere++;
    }
    fclose(fichier);
    
    printf("nombre de caractere: %d\n",totalcaractere);

  return(0);
}
