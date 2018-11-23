#include <iostream>  // padrão de entrada e saída no C++
#include <cmath>     // inclui funções matemáticas
#include <cstring>   // inclui funções de manipulação de string
#include <locale>    // inclui função para se usar palavras em português
#include <iomanip>
#include <fstream>
using namespace std;

string palavra_chave;

void manipula(string texto)
{
	int TAM = texto.size();

	for(int i = 0; i < TAM; i++)
	{
		cout << texto[i] << endl;

	}
}
void grava(string t)
{


	ofstream arq_out;
	arq_out.open("bbb.txt", ofstream::out | ofstream::app );//todos os dados q foram salvos nao irao sobrepor outro
	arq_out << t << endl;      // vamos gravar a respostas  o mesmo arquivo ?
	arq_out.close();

}

void leitura()
{

	int cont = 0;
	do
	{
		ifstream arq_in;
		string txt;
		arq_in.open("aaa.txt", ifstream::in);
		while(getline(arq_in, txt))
		{
			if(cont == 1)
				palavra_chave = txt;
			cout << txt << endl;
			manipula(txt);
		}
		cont ++;
	}
	while(cont == 1);
	cout <<  "palavra chave = " << palavra_chave << endl;
}

void matriz(int l1, int l2)
{
	int c, l, a = 97, b, mat[26][26];
	char m[26][26];

	for(l = 0; l < 26; l++)
	{
		b = a;
		for(c = 0; c < 26; c++)
		{
			mat[l][c] = b;
			m[l][c] = mat[l][c];
			if(b == 122)
			{
				b = 96;
			}
			b++;

		}
		a++;
	}

	cout << m[l1][l2];

}

void cripto(char q[45], char n[45], int k1, int n1)
{
	int l = 0, c = 0, nf = 0, qf = 0;

	l = 0;
	for(c = 0; c < n1; c++)
	{
		if(n[c] == ' ')
		{
			cout << " ";
			c++;
		}

		qf = q[l] - 'a';
		nf = n[c] - 'a';

		matriz(qf, nf);
		l++;

		if(l == k1 )
			l = 0;

	}

}


int main()
{


	char first[45], sec[150];
	int   n1 = 0, l = 0;
    
	//chamada da função leitura
	leitura();

	cin.getline(first, 45);
	l = strlen(first);
	//for de repetiçao
	cin.getline(sec, 150);
	n1 = strlen(sec);


	//cripto(firts, fra[150], k, n1);
	cripto(first, sec, l, n1);

	

	//chamada da função void grava
	grava();




	return 0;

}