#include <stdio.h>
#include "matrice.h"

int main(void)
{
	int choix;
	Matrice m_mat;
	Matrice m_mat2;
	ChargerMatrice(&m_mat, "mat.conf");
	ChargerMatrice(&m_mat2, "mat2.conf");
	Matrice m_add = Addition(m_mat, m_mat2);
	AfficherMatrice(m_mat);
	printf("\n");
	AfficherMatrice(m_mat2);
	printf("\n");
	AfficherMatrice(Oppose(m_add));
	LibererMatrice(&m_mat);
	LibererMatrice(&m_mat2);
	LibererMatrice(&m_add);
	return 0;
}
