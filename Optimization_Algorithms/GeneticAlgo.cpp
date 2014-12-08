/*
Created by  : Abhishek Dutt
Organisation: IMG IIT-R Sre
Project     : Optimization using Genetic Algorithm

To Execute : Change to the directory which contains the .cpp file , then in Terminal 
			 Compile by-> g++ GeneticAlgo.cpp -o main
			 Run by    -> ./main 	 
 */
#include <iostream>
#include <ctime>
#include <stdio.h> /* printf, scanf, puts, NULL */
#include <cstdlib> /* srand, rand */
#include <time.h> /* time */
#include <cmath>
#include <termios.h>
#include <unistd.h>			 
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
int getch(void)
{
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}
const int n = 2;
//a function to be used in  random(int,int)
bool p_in_n(int n[],int p,int k)
{
	for (int i = 0; i < k; ++i)
	{
		/* code */
		if (n[i]==p)
		{
			/* code */
			return false;
		}
	}
	return true;
}

//Define function to return 3 distinct random nos which are also not equal to another(j) no b/w a given range[0-Np)
int * random(int j,int Np)
{
	static int n[3];//static :check reason
	for(int k=0;k<3;++k)
	{
		int p;
		if(k==0)
		{
			do{
				p=rand() % Np;
			}while(p==j);
		}
		else
		{
			do{
				p=rand() % Np;
			}while(p==j || p_in_n(n,p,k));
		}
		n[k]=p;
	}
	return n;//return an array
}

//Define Cost Function
double Costf(double x[])
{
	//x[] is m dimensional
	double i=x[0]*2+x[1]*2+x[2]*2;;//to store the cost function
	return i;
}

double ** geneticOptimize(int domain[][n],int m,int maxiter,double f,double Cr,int Np)
{
	/* initialize random seed: */
	srand(time(0));
    //Initialisation of the first generation of population
   
    double **X=0;//target vector
    X=new double *[Np];
    cout<<"Initialisation for Generation 1(Target Vector)"<<endl;
    for (int i = 0; i < Np; ++i)
	{
		X[i] = new double[m];
		/* code */
		cout<<"{";
		for (int j = 0; j < m; ++j)
		{
			/* code */
			X[i][j]=domain[j][0]+(domain[j][1]-domain[j][0])*((double) rand() / (RAND_MAX));
			cout<<X[i][j]<<"  ";
		}
		cout<<"}"<<" ----->> "<<Costf(X[i])<<endl;
	}
	//Main loop , controlling Generations
	for (int gen = 0; gen < maxiter; ++gen)
	{
		/* code */
		//Mutation : to expand the search space
		cout<<"-----------------"<<endl;
		cout<<"Mutant Vector for Generation "<<(gen+1)<<endl;
		double V[Np][m];//Mutant or Donor Vector
		for (int i = 0; i < Np; ++i)
		{
			//select 3 random no(r1,r2,r3) b/w 0 to np which are distinct and nt equal to i.
			int *a;
			int r1,r2,r3;
			a=random(i,Np);
			r1=*a;
			r2=*(a+1);
			r3=*(a+2);
			/* code */
			cout<<"{";
			for (int j = 0; j < m; ++j)
			{
				/* code */
				V[i][j]=X[r1][j]+f*(X[r2][j]-X[r3][j]);
				cout<<V[i][j]<<"  ";
			}
			cout<<"}"<<endl;
		}
		cout<<"------------------"<<endl;
		//Crossover : to increase diversity of perturbed vectors
		double U[Np][m];//Trial Vector
		cout<<"Crossover for Generation"<<(gen+1)<<endl;
		for (int i = 0; i < Np; ++i)
		{
			/* code */
			cout<<"{";
			for (int j = 0; j < m; ++j)
			{
				/* code */
				if(((double) rand() / (RAND_MAX))<=Cr)
				{
				   	U[i][j]=V[i][j];
				   	cout<<U[i][j]<<"  ";
				}
				else
				{
					U[i][j]=X[i][j];
					cout<<U[i][j]<<"  ";
				}
			}
			cout<<"}"<<endl;
		}
		cout<<"---------------------"<<endl;
		//Selection : Survival of the fittest , to select the fittest from the target vector and trial vector
		cout<<"Selection(Target Vector) for Generation "<<(gen+2)<<endl;
		for (int i = 0; i < Np; ++i)
		{
			/* code */
			cout<<"{";
			if(Costf(U[i])<Costf(X[i]))
				for (int j = 0; j < m; ++j)
					{
						X[i][j]=U[i][j];
						cout<<X[i][j]<<"  ";	
					}
			else
				for (int j = 0; j < m; ++j)
					{
						cout<<X[i][j]<<"  ";	
					}
			cout<<"}"<<" ----->> "<<Costf(X[i])<<endl;		
		}
		getch();
	}
	return X;//return a 2d array X 
}

int main ()
{
  cout<<"  Optimization to find the min of the given cost function (x1*2+x2*2+x3*2) begins"<<endl;
  cout<<"----------------"<<endl;
  int domain[][2]={{-5,5},{-5,5},{-5,5}};
  int maxiter=100, Np=10,m=3;
  double f=0.5,Cr=0.5;
  double **X;
  X=geneticOptimize(domain,m,maxiter, f,Cr, Np);
  // print contents of the array2D
  cout<<"==============================="<<endl;
  for (int h = 0; h < Np; h++)
    {
        for (int w = 0; w < m; w++)
        {
            printf("%f,", X[h][w]);//%f is the correct format for double
        }
        printf("\n");
    }
  cout<<"  Optimization ends"<<endl;
  cout<<"----------------"<<endl;
  return 0;

}