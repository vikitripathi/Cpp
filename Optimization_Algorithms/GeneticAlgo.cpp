/*
Created by  : Abhishek Dutt
Organisation: IMG IIT-R Sre
Project     : Optimization using Genetic Algorithm
 */

#include <iostream>
#include <ctime>
#include <stdio.h> /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h> /* time */
#include <cmath>

using namespace std;

/*
The goal of any optimization algorithm is to find a set of inputs that minimizes the cost function, so the
cost function has to return a value that represents how bad a solution is. There is no particular scale forbadness; 
the only requirement is that the function returns larger values for worse solutions
 */


/*
Now as the cost function has been listed , goal is to min cost by choosing correct set of numbers
 */

/*
random searching and hill climbing can get stuck in local  minima
Genetics algorithms are way to avoid  getting struck in local minima and find the best overall minima ,called the
global minimum, which is what optimization algorithms are ultimately supposed to find.
 */


const int n = 2;



int ** geneticOptimize(int domain[][n],int m,int maxiter,int f,int Cr,int Np){
	
	/* initialize random seed: */
	srand (time(0));


	//Define function to return 3(i) distinct random nos which are also not equal to another(j) no b/w a given range(0-Np)
	int * random(int i,int j){
		
		bool p_in_n(int p,int k){
			for (int i = 0; i < k; ++i)
			{
				/* code */
				if (n[i]==p)
				{
					/* code */return false;
				}
			}
			return true;	
		}

		static int n[3];
		int i=0,p;
		for(int k=0;k<3;++k)
		{
			do{
				p=rand() % Np;
			}while(p==j || p_in_n(p,k));
			n[k]=p;

		}
			
		return n;//return an array
	}




	//Define Cost Function
	int Costf(int x[]){
		//x[] is m dimensional
		
		int i=x[0]*2+x[1]*2+x[2]*2;;//to store the cost function
		
		return i;
	}

	
	
    //Initialisation of the first generation of population
    int X[Np][m];//target vector
    for (int i = 0; i < Np; ++i)
	{
		/* code */
		for (int j = 0; j < m; ++j)
		{
			/* code */
			X[i][j]=domain[j][0]+(domain[j][1]-domain[j][0])*((double) rand() / (RAND_MAX));

		}
		
	}


	//Main loop , controlling Generations
	for (int gen = 0; i < maxiter; ++gen)
	{
		/* code */
		
		//Mutation : to expand the search space
		int V[Np][m];//Mutant or Donor Vector
		for (int i = 0; i < Np; ++i)
		{
			//select 3 random no(r1,r2,r3) b/w 0 to np which are distinct and nt equal to i.
			int *a;
			int r1,r2,r3;
			a=random(3,i);
			r1=*a,r2=*(a+1),r3=*(a+2);
			/* code */
			for (int j = 0; j < m; ++j)
			{
				/* code */
				V[i][j]=X[r1][j]+f*(X[r2][j]-X[r3][j]);
				

			}
		
		}

		//Crossover : to increase diversity of perturbed vectors
		int U[Np][m];//Trial Vector
		for (int i = 0; i < Np; ++i)
		{					
			/* code */
			for (int j = 0; j < m; ++j)
			{
				/* code */
				if(((double) rand() / (RAND_MAX))<=Cr)
				
					U[i][j]=V[i][j];
				else
					U[i][j]=X[i][j];
				

			}
		
		}


		//Selection : Survival of the fittest , to select the fittest from the target vector and trial vector
		for (int i = 0; i < Np; ++i)
		{					
			/* code */
			if(Costf(U[i])<Costf(X[i]))
				for (int j = 0; j < m; ++j)
					X[i][j]=U[i][j];
					
		}



	}
	

	return X;//return a 2d array X 

}



int main ()
{
  cout<<"Optimization to find the min of the given cost function begins"<<endl;
  cout<<"----------------"<<endl;
  int domain[][2]={{-5,5},{-5,5},{-5,5}};
  int maxiter=100, f=0.5,Cr=0.5, Np=20,m=3;
  int **X;
  X=geneticOptimize(domain,m,maxiter, f,Cr, Np);
  cout<<"Optimization ends"<<endl;
  cout<<"----------------"<<endl;
  return 0;

}