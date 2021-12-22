#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 20 //On alloue plus de cases mémoires que besoin dans notre cas pour pouvoir experimenté sur d'autres matrices plus grandes.


void Pivot_De_Gauss()
{
  // Algo pour résoudre une équation du type Ax=B 
  int i, j, k, compteur = 0;
  float result;
  int n=15;//Dimension de la matrice A.
  float Matrice_A[N][N]=
  {
  {1.0,     1.0/2, 1.0/4, 1.0/8, 1.0/16, 1.0/32, 1.0/64, 1.0/128, 1.0/256, 1.0/512, 1.0/1024, 1.0/2048, 1.0/4096, 1/8192, 1/16384},
  {1.0/2,    1.0,     0,     0,     0,       0,      0,       0,       0,      0,       0,        0,        0,       0,      0   },
  {1.0/4,     0,     1.0,    0,     0,       0,      0,       0,       0,      0,       0,        0,        0,       0,      0   },
  {1.0/8,     0,      0,    1.0,    0,       0,      0,       0,       0,      0,       0,        0,        0,       0,      0   },
  {1.0/16,    0,      0,     0,    1.0,      0,      0,       0,       0,      0,       0,        0,        0,       0,      0   },
  {1.0/32,    0,      0,     0,     0,      1.0,     0,       0,       0,      0,       0,        0,        0,       0,      0   },
  {1.0/64,    0,      0,     0,     0,       0,     1.0,      0,       0,      0,       0,        0,        0,       0,      0   },
  {1.0/128,   0,      0,     0,     0,       0,      0,      1.0,      0,      0,       0,        0,        0,       0,      0   },
  {1.0/256,   0,      0,     0,     0,       0,      0,       0,      1.0,     0,       0,        0,        0,       0,      0   },
  {1.0/512,   0,      0,     0,     0,       0,      0,       0,       0,     1.0,      0,        0,        0,       0,      0   },
  {1.0/1024,  0,      0,     0,     0,       0,      0,       0,       0,      0,      1.0,       0,        0,       0,      0   },
  {1.0/2048,  0,      0,     0,     0,       0,      0,       0,       0,      0,       0,       1.0,       0,       0,      0   },
  {1.0/4096,  0,      0,     0,     0,       0,      0,       0,       0,      0,       0,        0,       1.0,      0,      0   },
  {1.0/8192,  0,      0,     0,     0,       0,      0,       0,       0,      0,       0,        0,        0,      1.0,     0   },
  {1.0/16384, 0,      0,     0,     0,       0,      0,       0,       0,      0,       0,        0,        0,       0,     1.0  },
  };
    float Matrice_b[N]={1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
    float Matrice_temp[N][N];
    float Matrice_x[N];
    
    //printf("Saisir la dimension de votre matrice: ");     Cette partie est faite si l'on souhaite saisir les coeff de la matrice par saisie clavier
    //scanf("%d", &n);

    /*printf("Saisir les élèments de A: \n");
    for (i = 0; i < n; i++)
    {
	    for (j = 0; j < n; j++)
      {
	      scanf("%f", &a[i][j]);
      }
    }*/
    
    /*printf("Saisir les élèments de B: \n");
    for (i = 0; i < n; i++)
    {
	    scanf("%f", &b[i]);
    }
    */

    for (k = 0; k < n-1; k++)
    {
	    //Le cas où l'on peut pas effectuer le pivot de Gauss
	    if (Matrice_A[k][k] == 0)
      {
	      printf("Impossible a résoudre avec Gauss.\n");
	      exit (1);
	    }
      //On initialise une autre matrice pour stocker certain élèments de la matrice A afin de faciliter l'échelonnement par la suite.
	    for (i = k+1; i < n; i++)
      {
	      Matrice_temp[i][k] = Matrice_A[i][k] / Matrice_A[k][k];
	      compteur++; //sert a stocker le nombre d'opérations
	    }
      //On effectue l'échelonnement de la matrice
	    for (i = k+1; i < n; i++)
      {
	      for (j = k+1; j < n; j++)
        {
		      Matrice_A[i][j] = Matrice_A[i][j] - Matrice_temp[i][k] * Matrice_A[k][j];
		      compteur++;
	      }
	      Matrice_b[i] = Matrice_b[i] - Matrice_temp[i][k] * Matrice_b[k];
	      compteur++;
	      Matrice_A[i][k] = 0;
	    }   
    }
    //On affiche la matrice A et la matrice B après la fin de l'échelonnement.
    printf("Après, A(%d*%d) et B(%d*1) peut etre:\n", n, n, n);
    for (i = 0; i < n; i++)
    {
	    for (j = 0; j < n; j++)
      {
	      printf("%.4f  ", Matrice_A[i][j]);// On arrondi les coefficents de la matrice à 4 chiffres après la virgule.
	    }
	    printf("%.4f\n", Matrice_b[i]);
    }
    //On effectue les opérations suivantes sur le tableau x de taille n donnant la solution à notre algo.
    printf("La solution à la Matrice x est: ");
    Matrice_x[n-1] = Matrice_b[n-1] / Matrice_A[n-1][n-1];
    compteur++;
    for (i = n-2; i >= 0; i--)
    {
	    result = 0.0;
	    for (j = i+1; j < n; j++)
      {
	      result = result + Matrice_A[i][j] * Matrice_x[j];
	      compteur++;
	    }
	    Matrice_x[i] = (Matrice_b[i] - result) / Matrice_A[i][i];
	    compteur++;
    }
    //On affiche la matrice x solution de notre système 
    for (i = 0; i < n; i++)
    {
	    printf("%.4f  ", Matrice_x[i]);
    }
    //On affiche le nombre d'opérations effectuées au total par cet algo.
    printf("\nLe nombre de multiplication(s) et de division(s) effectuée(s) est : %d\n", compteur);
}

int main()
{   
  Pivot_De_Gauss(); //On effectue un appel à la fonction.
  return 0;
}