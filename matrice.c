#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "matrice.h"

long i, j;

void AllocMatrice(Matrice *p_m_address, long width, long height)
{	
		p_m_address->width = width;
		p_m_address->height = height;
		p_m_address->M = (double**) calloc(width, sizeof(double*));
		assert(p_m_address->M != NULL);
		for(i=0; i < width; i++)
		{
			p_m_address->M[i] = (double*) calloc(height, sizeof(double));
			assert(p_m_address->M[i] != NULL);
		}
}

void LibererMatrice(Matrice *p_mat)
{
	for(i=0; i < p_mat->width; i++)
		free(p_mat->M[i]);
	free(p_mat->M);
	p_mat->M = NULL;
}

void ChargerMatrice(Matrice *p_m_address, char *path)
{
		long conf_w, conf_h;
		FILE* p_conf = fopen(path, "r");
		assert(p_conf != NULL);
		fscanf(p_conf,"%ld ", &conf_w);
		fscanf(p_conf,"%ld\n", &conf_h);
		AllocMatrice(p_m_address, conf_w, conf_h);
		for (i=0; i < conf_w; i++)
		{
			for (j=0; j < conf_h-1; j++)
				fscanf(p_conf, "%lf ", &p_m_address->M[i][j]);
			fscanf(p_conf, "%lf\n", &p_m_address->M[i][j]);
		}
		fclose(p_conf);
}

void EcrireMatrice(Matrice m_mat, char* path)
{
	FILE* p_out = fopen(path, "w");
	assert(p_out != NULL);
	for(i=0; i < m_mat.width; i++)
	{
		for(j=0; j < m_mat.height; j++)
			fprintf(p_out, "%g ", m_mat.M[i][j]);
		fprintf(p_out, "\n");
	}
}

void AfficherMatrice(Matrice m_mat)
{
	for(i=0; i < m_mat.width; i++)
	{
		printf("[line: %ld] ", i+1);
		for(j=0; j < m_mat.height; j++)
			printf("%g ", m_mat.M[i][j]);
		printf("\n");
	}
}

double Trace(Matrice m_mat)
{
	double trace = 0;
	for(i=0; i < m_mat.width; i++)
	{
		for(j=0; j < m_mat.height; j++)
			if(i == j)
				trace += m_mat.M[i][j];
	}
	return trace;
}

Matrice Addition(Matrice m_01, Matrice m_02)
{
	Matrice m_out;
	if(m_01.width == m_02.width && m_01.height == m_02.height)
	{
		AllocMatrice(&m_out, m_01.width, m_01.height);
		for(i=0; i < m_01.width; i++)
		{
			for(j=0; j < m_01.height; j++)
			{
				m_out.M[i][j] = m_01.M[i][j] + m_02.M[i][j];
			}
		}
	}
	else
	{
		printf("[EE] -> ERROR WITH SIZE !");
		abort();
	}
	return m_out;
}

Matrice Oppose(Matrice m_mat)
{
	Matrice m_oppose;
	AllocMatrice(&m_oppose, m_mat.width, m_mat.height);
	for(i=0; i < m_mat.width; i++)
	{
		for(j=0; j < m_mat.height; j++)
			m_oppose.M[i][j] = -(m_mat.M[i][j]);
	}
	return m_oppose;
}

Matrice Soustraction(Matrice m_01, Matrice m_02)
{
	return Addition(m_01, Oppose(m_02));
}

Matrice ProduitExterne(double scal, Matrice m_mat)
{
	Matrice m_out;
	AllocMatrice(&m_out, m_mat.width, m_mat.height);
	for(i=0; i < m_mat.width; i++)
	{
		for(j=0; j < m_mat.height; j++)
			m_out.M[i][j] = scal * m_mat.M[i][j];
	}
	return m_out;
}