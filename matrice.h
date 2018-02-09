#ifndef _Matrice
#define _Matrice
typedef struct Matrice_s
{
	double **M;
	long width;
	long height;
}Matrice;

void AllocMatrice(Matrice *p_m_address, long width, long height);

void LibererMatrice(Matrice *p_mat);

void ChargerMatrice(Matrice *p_m_address, char *path);

void EcrireMatrice(Matrice m_mat, char* path);

void AfficherMatrice(Matrice m_mat);

double Trace(Matrice m_mat);

Matrice Addition(Matrice m_01, Matrice m_02);

Matrice Oppose(Matrice m_mat);

Matrice Soustraction(Matrice m_01, Matrice m_02);

Matrice ProduitExterne(double scal, Matrice m_mat);

#endif
